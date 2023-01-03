= 手書きデータの描画

本章では、手書きの絵をガルバノスキャナに入力し、描画するために、簡易おえかきツールの製作、一筆書きデータとしての抽出と、PCM および DA ボードに入力するところまでを実装する。将来的には、読み込んだ画像の輪郭抽出およびベクトル化により、ガルバノ用データを生成する方法についても実施したいが、いろいろハードルが高いことがわかったため、輪郭抽出や自動でのベクトル化は今後の課題とし、本節では一筆書きの要領で描画したものをガルバノ用データに変換するという方法による。

==	簡易お絵かきソフトの実装
まずは簡易ペイントソフトを制作する。機能としては、至って単純で、領域内をマウスでドラッグした軌跡を描くだけである。Undo などは存在しない。まず制作したソフトの外観を図 6.1 に示す。そのための手順としては、

 1.	マウスクリック/ドラッグイベントを記述する
 2.	画像の保存、テキストデータでの保存
 3.	Wave ファイルを生成する

の 3 ステップとなる。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap6/image1.jpg}
\caption{お絵かきソフトの外観}
\end{figure}
//}

まず、マウスクリック・ドラッグイベント記述について述べる。 先にコードを見てしまったほうがわかりやすいと考えられるので、コードを書く。

//listnum[drawsoft][お絵かきソフトの実装]{
Private Sub Form1 Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
    ’ 描画領域の確保
    img = New Bitmap(PictureBox1.Width, PictureBox1.Height) g = Graphics.FromImage(img)
    PictureBox1.Image = img
    g.FillRectangle(Brushes.White, 0, 0, PictureBox1.Width, PictureBox1.Height)
    PDown = False 
    n = 0
End Sub

Private Sub PictureBox1 MouseDown(ByVal sender As Object,	ByVal e As System.
Windows.Forms.MouseEventArgs) Handles PictureBox1.MouseDown
    ’ 描画フラグ ON，座標記録 
    PDown = True
    oldX = e.X oldY = e.Y
    posX(n) = (oldX - 160) / 160 ’XY ベクトルデータとして格納
    posY(n) = (oldY - 120) / 120 ’±1 に規格化
    tbConsole.Text = ”n=” & n & ”,” & posX(n) & ”,” & posY(n)	’ 位置実績をテキストボックスに表示
    n = n + 1 
End Sub

Private Sub PictureBox1 MouseMove(ByVal sender As Object,	ByVal e As System.
Windows.Forms.MouseEventArgs) Handles PictureBox1.MouseMove
    If PDown Then
        ’ ラインを引く
        g.DrawLine(p, oldX, oldY, e.X, e.Y) ’PictureBox を再描画する 
        PictureBox1.Invalidate()
        ’ いまの XY 座標を取得し、保存する
        oldX = e.X oldY = e.Y
        posX(n) = (oldX - 160) / 160 posY(n) = (oldY - 120) / 120
        tbConsole.Text = ”n=” & n & ”,” & posX(n) & ”,” & posY(n) ’& e.X & ”,” & e.Y n = n + 1
    End If 
End Sub

Private	Sub	PictureBox1 MouseUp(ByVal sender As Object, ByVal e As System.
Windows.Forms.MouseEventArgs) Handles PictureBox1.MouseUp
    ’ 描画フラグの解除
    PDown = False
End Sub

Private Sub btnSaveImg Click(ByVal sender As System.Object, ByVal e As System.
EventArgs) Handles btnSaveImg.Click
    SaveFileDialog1.ShowDialog() 
    PictureBox1.Image.Save(SaveFileDialog1.FileName, Imaging.ImageFormat.Bmp)
End Sub

Private Sub btnSaveXYcsv Click(ByVal sender As System.Object, ByVal e As System.
EventArgs) Handles btnSaveXYcsv.Click
    Dim sfd As New SaveFileDialog
    sfd.Filter = ”すべてのファイル (*.*)|*.*|csv ファイル (*.csv)|*.csv” ’ ファイルの種類に表示される一覧
    sfd.FilterIndex = 2 ’Filter の初期値
    Dim filename As String 
    Dim fileNo As Integer
    If sfd.ShowDialog() <> DialogResult.OK Then 
        Return
    End If
    filename = sfd.FileName fileNo = FreeFile()
    FileOpen(fileNo, filename, OpenMode.Output)

    For i = 0 To n - 1 Write(fileNo, i) 
        Write(fileNo, posX(i)) 
        WriteLine(fileNo, posY(i))
    Next 
    FileClose() ’SaveRoutine
End Sub
//}

最初に新しいビットマップを確保し、白で塗りつぶしておく。

次に、マウスをクリックした時のイベントが、PictureBox1 MouseDown である。ここでは、クリックした時に描画フラグを True とし、座標を記録する。

次に、マウスを動かした時のイベントが、PictureBox1 MouseMove である。

描画エリア内でマウスを移動した時、描画フラグが True ならば、前回の点と現在の点の間に線を引く。同時に読み取った座標を記録する。

最後に、マウスのクリックを外した時には、描画フラグを False とし、PictureBox 上を移動しても線は描かれない。

あとは、画像の保存と、ファイルの保存を行えばよい。保存した XY データは、このような書式となる。

//table[drawdata][XYデータの書式]{
回数	X データ	Y データ
-----------------
0	-0.3	0.6333
1	-0.31875	0.6
2	0.325	0.58
//}

この二次元データを X のデータを L に、Y のデータを R にして Wave ファイルとすればよい。

また、このソフトより Wave ファイルを再生できるようにしておく。ボタンを押すと、指定したファイルを 1 回だけ再生し、もう一度押すと止まる、という仕様である。

== 一筆書きデータの抽出
次は、一筆書きしたデータテーブルを、音声ファイルに代入する方法である 。

基本的には、位置データを格納した変数 PosX、PosY を用いて、MakeWave 内のデータ配列生成部分に代入すれば良い。

//listnum[drawtowave][一筆書きデータを音声に変換する]{
Public Overloads Sub MakeWave(ByVal amp As Double, ByVal freqency As UInteger, 
ByVal sec As Double)
    Dim res As UInteger = CInt(sec * CDbl(wh.SamplingRate)) 
    Dim buf As UInteger = res * wh.Channels
    Dim data As Short() = Array.CreateInstance(GetType(Short), buf) 
    Dim val As Double
    Dim rep As Integer
    rep = Int(res / Form1.n)	‘データの繰り返し回数を定義
    ’ Wave の波形データサイズを設定
    wh.SizeOfBuffer = wh.SizeOfBuffer + buf * wh.BitsPerSample / 8 
    If wh.Channels = 1 Then ’ モノラル
        For i As Integer = 0 To res - 1 Step 1
            ’ 振幅の計算
            val = amp * Math.Sin(2 * Math.PI * i * freqency / wh.SamplingRate) 
            data(i) = CShort(val * 32767) ’ Mono Channel
        Next
    ElseIf wh.Channels = 2 Then ’ ステレオ 
    ’For i As Integer = 0 To res - 1 Step 1 
    For i As Integer = 0 To rep - 1 Step 1
    ’ 振幅の格納。 n 点のたびに最初に戻り、波形データを入れる。
        For j = 0 To Form1.n - 1
            ’val = amp * Math.Sin(2 * Math.PI * i * freqency / wh.SamplingRate) 
            data((i * Form1.n + j) * 2) = CShort(Form1.posX(j) * 32678) ’ Left 
            data((i * Form1.n + j) * 2 + 1) = CShort(Form1.posY(j) * 32678) ’R 
            ’data(i * 2) = CShort(val * 32767) ’ Left Channel
            ’data(i * 2 + 1) = CShort(val * 32767) ’ Right Channel 
        Next
    Next 
    End If
    datalist.Add(data)
End Sub
//}

//noindent
とすればよい。データ点数 res=再生時間 × サンプリング周波数に対して、データ繰り返し回数 rep を定義した。XY データ数 n で割って XY データの繰り返し回数を設定し、指定秒数だけ繰り返す。また XY データのうち PosX を L に、PosY を R に設定する。

次に、適宜振幅やサンプリング周波数の調整を行う。サンプリング周波数は、44k も必要ないので、4.4k としておく。もちろん変更することは容易である。このあたりは実際にガルバノスキャナを動かしながらチューニングする必要がある。このチューニングはあとで実施する予定である。30fps相当程度あれば十分と考えられる。そのため、例えばデータ点数を考慮して自動で周波数を変えるなどの機能があっても良いかもしれない。

音声ファイルとともに、CSV ファイルも保存する。Wave 保存のファイル名とデータを用いて、同じパスにほぼ同じ名前で保存する。それから、保存したファイルを読み出して、音声ファイルを再生成する機能も盛り込んでおく。
 
//listnum[savecsv][csvの保存]{
Private Sub btnOpenCSV Click(ByVal sender As System.Object,	ByVal e As System.
EventArgs) Handles btnOpenCSV.Click
    Dim ofdcsv As New OpenFileDialog()
    ofdcsv.Filter = ”すべてのファイル (*.*)|*.*|csv ファイル (*.csv)|*.csv” ’ ファイルの種類に表示される一覧
    ofdcsv.FilterIndex = 2 ’Filter の初期値
    Dim filename As String Dim fileNo As Integer Dim i As Integer = 0
    If ofdcsv.ShowDialog() <> DialogResult.OK Then 
        Return
    End If
    filename = ofdcsv.FileName fileNo = FreeFile()
    FileOpen(fileNo, filename, OpenMode.Input) 
        Do Until EOF(fileNo)
        Input(fileNo, i) 
        Input(fileNo, posX(i)) 
        Input(fileNo, posY(i)) ’i += 1
    Loop n = i
    tbConsole.Text = tbConsole.Text & ”n=” & n 
    FileClose(fileNo)
    tbConsole.Text = tbConsole.Text & posX(0) & posY(0)	‘データ確認
End Sub
//}

ファイルの読み込み自体には特記事項はない。ただし、格納先配列を posX および posY としているので、そのまま SaveWave コマンドを出せば Wave ファイルが再生成される。

== 信号チェック
このあたりで、出力信号のチェックを行う。ここまでのソフトの画面を示す。

中央部分が描画領域である。ボタンは上から音声ファイルの保存、描いた図形を bmp で保存、XYデータを CSV で保存、消去、保存した音声再生、保存した XY データ CSV を読み込むボタンである。また、右上の長いテキストボックスは動作状況モニタで、デバッグ用として設置した。またその下の今 2 と入っているところは、振幅を設定するテキストボックスである。ただし。飽和した時の処理を記述していないため、現在は使用していない。基本図形として、イをマウスで一筆書きし、 Wave ファイルとして保存した。描画の基本であるから、仕方がない。

また、これを PC オシロスコープの XY モードで見ると、次のような図 6.3 になる。問題点は幾つかあり、まず左右反転している点。これは、プログラムの修正で容易に集積できる。横軸 (いまの環境では X) のデータ符号を反転させ修正することができた。波形歪とノイズについては、一旦保留しておく。ノイズについては USB オシロ自体の特性であると考えられるためである。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap6/image2.jpg}
\caption{お絵かきソフトでの描画}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap6/image3.jpg}
\caption{保存した画像(bmp)}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap6/image4.jpg}
\caption{オシロのXYモードでの表示例}
\end{figure}
//}

== ガルバノスキャナによる任意図形の描画
仮組み状態ではあるが、動作する状態まで組み上げた。写真を図 6.4 に示す。定盤の左側の白い箱が鉛シール電池であり、その上に電源回路を実装したブレッドボードが乗る。信号入力端子は、ステレオピンジャックで、左下にある。ブレッドボードの下側で、ステレオピンジャックのケーブルとガルバノスキャナのドライバへのケーブルを接続している。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap6/image5.jpg}
\caption{ガルバノとレーザーポインタの仮組み}
\end{figure}
//}

動作チェック時点では、ロッド上に取り付けた板の上にグリーンレーザポインターを仮止めしている。細かい位置の調整などはできないので、今後調整する。なお、しばらく動作させておくと、レーザポインタがかなりの熱を持つことがわかった。

連続的に動作していると、しばらくすると発振しなくなることがある。この時、レーザポインタ上のLED がオレンジ色に変わる。レーザポインタの冷却についても、後ほど触れる。

ここに、先ほどと同じように、”イ”を入力する

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap6/image6.jpg}
\caption{レーザープロジェクタでの最初の表示例}
\end{figure}
//}

描画結果を図 6.5 に示す。多少歪はあるものの、手書きにより生成した画像が描かれている事がわかる。ここまでで、手書き画像をオーディオ出力により画像化するという、当初目的を達したことになる。