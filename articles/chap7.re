= 実用ソフトの実装

ここまで述べた DA ボードおよびオーディオ出力を利用した信号発生器を用いて、少し実用的なものを作る。実装したのは、ファンクションジェネレータと、アナログ時計である。

==	ファンクションジェネレータの実装
===	ファンクションジェネレータとは
ファンクションジェネレータ（function	generator）とは、任意の周波数と波形を持った交流電圧信号を生成することのできる電気計測器である。主に機器のテスト信号を送り込むために使われ、標準信号発生器と機能や使われ方が似ているが、より低周波の領域で使用される。初期の製品はアナログ式であったが、近年はディジタル化され任意の波形生成やディジタル変調にも対応した製品が一般的となっている。*7

というわけで、任意の周波数と波形を出力するための装置であり、1 台手元にあると便利である。一方で、購入した場合は完成品で数万円程度、キットで数千円からのものであるから、自作しておくのも良い。秋月の DDS-FG キットなども良いが、今回は、AD ボードおよびオーディオ出力でファンクションジェネレータを作る。

ガルバノ用にコードを作っていたところ、ほとんどできてしまったので、追加すべき機能をいくつかつけるだけでファンクションジェネレータができてしまう。

===	波形の定義
単純な周波数決め打ちでよいから、とっとと作ってしまうべきだったのだが、いろいろあれやこれややり始めたら思ったより時間がかかってしまいそうな予感。実装内容は、矩形波と三角波の実装および、Duty 比可変である。今までの FG ソフトには、正弦波出力しかなかった。しかし、ガルバノのチェックを行うには、掃引しながら三角波を入力するなどする必要があり、正弦波のみの現在のソフトでは機能に不足がある。そこで、三角波とついでに矩形波を実装する。また、三角波については、ノコギリ波まで可能なように、歪率調整を可能とする仕様とした。矩形波については、Duty 比を変更可能とした。ただし、調整つまみのスペース制約から、歪率と Duty 比は共通のスライドバー Duty/Asym による設定としした。また、Bipolar のチェックボックスにより、出力波形を正負とするか、正のみとするかを選択可能とする。

さて、実装を始めて気づいたのだが、矩形波や三角波の実装は意外と面倒である。これをスマートにする方法については、ぜひご教授頂きたい。正弦波はデータ定義領域のつながりはともかく単純に周波数を入れて sin を取れば点数に関係なく周期関数になる。ここでは、データ格納用の配列の全長にわたって、インクリメントして Sin を取ったものを格納するだけですむ。

//listnum[sin][正弦波の実装]{
’Sin 波の波形を作る
For i = 0 To AoSamplingTimes - 1
AoVolt = PPx * Sin(Xfreq * 2 * PI * i / AoSamplingTimes) 
AoData(i * AoChannels * 2) = AoVolt
Next
//}

一方で 、三角波や矩形波は、1 周期を定義してやらなければ周期関数とならず、少々面倒で ある。基本的な考え方としては、一周期分のデータを計算し、それを繰り返し並べるという方法である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap7/image1.jpg}
\caption{矩形波の定義}
\end{figure}
//}

データ列の総数を周波数で割ることで 1 周期のサンプリング点数が得られる。このサンプリング点数の中を順に埋め、それを繰り返すことで連続データとする。歪率を定義するため、サンプリングデータの中である割合の点を決め、その前後で傾きあるいは出力を変化させることで波形歪を表現することにした。具体的な説明は図 7.1 および図 7.2 で示す。矩形波は Duty 比として、三角波では歪率としたが、いずれもここでは 0～100%としている。矩形波は、Duty0%で出力が0、100%で直流となる。Bipolar で Duty50 以上は、負のパルスが短くなるという定義になる。また、パルスの立ち上がりが遅くなるという実装にした。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=1.0\linewidth]{images/chap7/image2.jpg}
\caption{三角波の定義}
\end{figure}
//}

三角波については、対称な三角波を歪率50%とし、0%で右下がりのノコギリ波、100%で右上がりののこぎり波となると定義した。概念を図に示す。



=== ファンクションジェネレータの実装
つづいて、実装内容の説明に移る前に、図 7.3 にソフトの UI を示しておく。つづいて、実装したそれぞれの波形生成部分のコードを示す。


//embed{
\begin{figure}[h]
\centering
\includegraphics[width=1.0\linewidth]{images/chap7/image3.jpg}
\caption{ファンクションジェネレーターの画面}
\end{figure}
//}

//listnum[triangle][三角波の実装]{
’ 三角波作る
For k = 0 To Xfreq - 1
    If cbBipolarX.Checked Then ’Bipolar 
        For i = 0 To ChangePointX / 2
        If ChangePointX = 0 Then ’0 は上りランプなし
            Exit For
        Else
            AoData(2 * (i * AoChannels + k * PulseWidthPointX)) = PPx * i * 2/ChangePointX
        End If 
    Next
    j = 0
    For i = ChangePointX / 2 To AoSamplingTimes - ChangePointX / 2 - 1
        AoData(i * AoChannels * 2 + k * PulseWidthPointX) = PPx * (1 - 2 * j/(AoSamplingTimes - ChangePointX))
        j = j + 1 
    Next
    j = 0
    For i = AoSamplingTimes - ChangePointX / 2 To AoSamplingTimes - 1
    AoData(i * AoChannels * 2 + k * PulseWidthPointX) = -PPx * (1 - 2 * j/ChangePointX)
            j = j + 1 
        Next
    Else ’Unipolar
    For i = 0 To ChangePointX - 1 If ChangePointX = 0 Then
    Exit For
    Else
    AoData(2 * (i * AoChannels + k * PulseWidthPointX)) = PPx * i /ChangePointX
    End If Next
    j = 0
    For i = ChangePointX To PulseWidthPointX - 1
        AoData(2 * (i * AoChannels + k * PulseWidthPointX)) = PPx * (1 - j /ChangePointX)
        j = j + 1 Next
    End If
Next	k
//}

//listnum[rectangle][矩形波の実装]{
’ 矩形波を作る
For k = 0 To Xfreq - 1 ’ 周波数分の回数繰り返すループ
    For i = 0 To ChangePointX - 1
        AoData(2 * (i * AoChannels + k * PulseWidthPointX)) = PPx 
    Next
    If cbBipolarX.Checked Then	’Bipolar のとき
        For i = ChangePointX To PulseWidthPointX
            AoData(2 * (i * AoChannels + k * PulseWidthPointX)) = -PPx 
        Next
    Else
        For i = ChangePointX To AoSamplingTimes
            AoData(2 * (i * AoChannels + k * PulseWidthPointX)) = 0 
        Next
    End If
Next
//}

なお、効率を考えるなら、X と Y をそれぞれ作るのではなく、Class 化するとか、適切な引数を取るサブルーチンとしておくのがよいと思うが、今回はベタで打った。時計の実装においても、よくあれを実装したものだ、と言われたが、そのあたりは難しい。やはりもう一段階プログラミングの能力を上げたい。英語とかといっしょなのかな、とも思わないでもないが、やっぱりいろいろサンプルを見ながら書いていくのが良いのか。幸いにして今は作りたい物が沢山あるので、それを順次実現していけば、サンデープログラマとしては十分なところまで行ける日が来るのだろうか。

== アナログ時計の実装
今回はデモ用の一環として、アナログ時計っぽいものを作ってみる。これまでデモに使ったのは、ニコニコからもらってきたネギ振りミク*8。ミクはともかく、単なるステレオ音源では一見してよくわからない内容なので、今回はもう少しわかりやすいデモを目指し、時計を作ってみることにした。
基本的には、3 本針のアナログ時計である。デジタルにしてもいいのだけど、文字をベクトル化するのが少々面倒で、アナログ時計ならば、時刻→針の位置→角度で出力とプログラムに落としこみ易いので、今回はアナログ時計とした。描画データそのものを自動生成することが今後の肝と考えているので、この方法を採用した。描画イメージを図 7.4 に示す。

===	時計の文字盤の定義

基本的な考え方は以下のとおりである。

 1.	文字盤を示す点を 12 個と針を 3 本描画する。	文字盤と針は順次描画し、残像を利用して 全体を表示する。
 2.	時間的な考え方	DA ボードのサンプリングは 1ms である。 12 点 + 針の終点始点を指定して、 全部で 25ms で１回描画する。
 3.	針の終点と始点	現時点ではレーザの ON/OFF には対応していない。 そのため、変なところを横切ってはマズい

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap7/image4.jpg}
\caption{レーザー時計のイメージ}
\end{figure}
//}

=== 時計の実装
原点スタート→短針→長針→秒針→ 0 → 11 → 0 →原点→短針→長針→秒針→原点と いうシーケンスを選んだ。ここで、数字は文字盤、原点は針の付け根である。

//listnum[clock][時計データの生成]{ 
Private Sub GenerateClockData() ’ 時計データを生成。
    Dim dtNow As DateTime = DateTime.Now()   ’ 現在時刻を取得
    For j = 0 To 20
    AoData(j * 50 + 0) = 0
    AoData(j * 50 + 1) = 0
    AoData(j * 50 + 2) = 2 * Sin(2 * Math.PI * 30 * dtNow.Hour / 360) 
    AoData(j * 50 + 3) = 2 * Cos(2 * Math.PI * 30 * dtNow.Hour / 360) 
    AoData(j * 50 + 4) = 0
    AoData(j * 50 + 5) = 0
    AoData(j * 50 + 6) = 3.5 * Sin(2 * Math.PI * 6 * dtNow.Minute / 360) 
    AoData(j * 50 + 7) = 3.5 * Cos(2 * Math.PI * 6 * dtNow.Minute / 360) 
    AoData(j * 50 + 8) = 0
    AoData(j * 50 + 9) = 0
    AoData(j * 50 + 10) = 5 * Sin(2 * Math.PI * 6 * dtNow.Second / 360) 
    AoData(j * 50 + 11) = 5 * Cos(2 * Math.PI * 6 * dtNow.Second / 360) 
    AoData(j * 50 + 12) = 0
    AoData(j * 50 + 13) = 0
        For i = 0 To 12
            AoData(j * 50 + i * 2 + 14) = 5 * Sin(2 * Math.PI * 30 * i / 360) 
            AoData(j * 50 + i * 2 + 15) = 5 * Cos(2 * Math.PI * 30 * i / 360)
        Next
    AoData(j * 50 + 38) = 0
    AoData(j * 50 + 39) = 0
    AoData(j * 50 + 40) = 2 * Sin(2 * Math.PI * 30 * dtNow.Hour / 360) 
    AoData(j * 50 + 41) = 2 * Cos(2 * Math.PI * 30 * dtNow.Hour / 360) 
    AoData(j * 50 + 42) = 0
    AoData(j * 50 + 43) = 0
    AoData(j * 50 + 44) = 3.5 * Sin(2 * Math.PI * 6 * dtNow.Minute / 360) 
    AoData(j * 50 + 45) = 3.5 * Cos(2 * Math.PI * 6 * dtNow.Minute / 360) 
    AoData(j * 50 + 46) = 0
    AoData(j * 50 + 47) = 0
    AoData(j * 50 + 48) = 5 * Sin(2 * Math.PI * 6 * dtNow.Second / 360) 
    AoData(j * 50 + 49) = 5 * Cos(2 * Math.PI * 6 * dtNow.Second / 360)
Next
’ 出力データを格納
Ret = AioSetAoSamplingDataEx(Id, AoSamplingTimes, AoData) Ret = AioStartAo(Id)

'イベントルーチン内に追加
Protected Overrides Sub WndProc(ByRef m As System.Windows.Forms.Message) 
    Select Case m.Msg
        Case AIOM AOE END
            tbErrorString.Text = ”変換停止” 
            If cbClock.Checked Then
                GenerateClockData() 
            End If
    End Select 
End Sub
//}

Dim dtNow As DateTime = DateTime.Now()
で現在の時刻を取得し、それぞれの要素を.Hour や.Minute で取り出し、針の描画に使う。残像のこともなんとなく考えて、サンプリング 1ms、XY2 点なので 25ms で一周するようになっていて、リフレッシュレートは約 40Hz（プログラム的な遅延除く）である。なお、上記プログラムでは簡単のため、短針の微妙なズレについては考慮していない。分の項も拾ってきて、60 分で 6° 移動することを考慮して、それを加えても良い。より微妙な動きを反映した時計を表示することができるはずである。時計の針の部分のコードは羅列的にしており、多少冗長である。この部分をすっきりさせることができればよいのだが。配列のインデックスをそのまま羅列しているため、修正が面倒である。よりスマートなコードがあればご教授頂きたい。

また、イベントルーチンの中に、1 周期の DA 出力が終わったら、次の描画データの作成とデータ格納を行うために、GenerateClockData() を追記する。このように割り込みを適切に使って次のシーケンスを設定することで、連続的に動作させることができる。実際の描画画像を見ながらタイミングをチューニングする必要はあるが、簡単な図形ならばデータ生成も簡単に行え、このようなものを作成する事ができる。描画におけるリフレッシュレートを適切に調整し、一点の保持時間を調整することで、輝度を調整する事ができる。


===	動作状況
PC オシロで表示した例を図 7.5 に示す。狙ったとおりの形状が描けており、実装大成功と思ったところが、実際にガルバノに入力したところが大変なことになってしまっていた。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap7/image5.jpg}
\caption{オシロでの表示}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap7/image6.jpg}
\caption{実際の投影結果}
\end{figure}
//}

外周が大きく変形しており、どう見ても時計には見えない。ただし、確かに 1 秒毎に動いているので（バグはあったとしても）、動作していないということではなさそうである。オシロ上は問題ないことから、ガルバノの機械的特性（制動などの問題か）と考えられる。

===	改善の方針
サンプリング周波数は 1kHz で比較的大きな振幅であることから、周波数特性によるものであると考えられる。ガルバノミラーは軽いとはいえ、イナーシャ(慣性による負荷)がある。そこで、全体の周波数を落として実験を行う予定であったが、原稿には間に合わなかった。今40Hz程度の速度であるが、10Hz あるいは 5Hz 程度まで落としても十分視認できるであろうし、形状の追従性も向上すると考えられる。

周波数特性を含めたチューニングは本書の後半で行い、描画性能は改善させる予定である。
