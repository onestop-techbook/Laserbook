= オーディオ信号を用いた信号源製作


== オーディオ信号を用いた信号源製作
前節では DA ボードを利用したファンクションジェネレータを製作し、振幅、周波数、位相の変更を可能とし、PC オシロによる波形を確認した。一方で DA ボードは別のハードウエアを追加する必要があり、実装例で述べた Contec の DA ボードはその価格は数万円～10 万円前後となり、決して安いとはいえない。そこで本節では、アナログ信号の出力元としてパソコンにも標準装備されているオーディオ出力を利用する。オーディオ出力を制御するためにはもろもろ考慮しなければいけない内容がある。そこで、PCM（Wave ファイル）のヘッダの定義、Memory Streamを用いた直接出力について、コード例を示しながら実装する。

== PCM 音源の定義
最も単純な音源は、パルス符号化変調：PCM（Pulse Code Modulation）である。一定のサンプリング間隔で信号振幅を直接コード化したものである。非可逆圧縮を一切用いないためデータ量は大きくなるが、データ形式が簡単で扱いやすいという特徴がある。サンプリング周波数が高いほど、量子化ビット数が多いほど信号を忠実に記録することができる。

AudioCD などに記録されている形式でもある。量子化間隔は線形であり、リニア PCM とも呼ばれる。AudioCD は、サンプリング周波数 44.1kHz、量子化ビット数 16bit、2ch ステレオであり、 DVD や BD では、48kHz や 192kHz、24bit など、必要に応じて拡張される。

PC で使用する PCM ファイルの拡張子は.wav であり、ほぼどんな再生ソフトでも再生できる。ファイルは、ヘッダ部分とデータ本体部分からなり、ヘッダ部分でサンプリング周波数や量子化ビット数、チャンネル数を規定する。本体部分は、それぞれのチャンネルのデータを順に並べたものとなっている。

== PCM ヘッダの定義
ここでは、PCM ヘッダ構造を述べる。表 5.1 のようなヘッド構造を取る。Wave ファイルを扱う際には、データ部分は当然だが、ヘッダを生成するコードを作る必要がある。ただし、生成するファイルがほぼ一定ならば、ヘッダ部分などは定形で作成する形としても良い。ヘッダ構造については、次のページ@<fn>{wavewebsite}を参照した。

上の表に書ききれなかった内容について、簡単に解説する。

//footnote[wavewebsite][https://so-zou.jp/software/tech/file/format/wav/ https://web.archive.org/web/20150101141944/http://www.kk.iij4u.or.jp/~kondo/wave/index.html]

 * fmt チャンクの部分には、”fmt	“と入力する。スペースを忘れてはならない。
 * fmt チャンクと data チャンクは必須である。
 * 他に LIST チャンクや fact チャンクがあるが、あってもなくても構わない。
 * データは、LRLR の順で配置し、ビット数によって 8bit=Unsigned、16bit=Signed となる。そのため、8bit の無音は 128 だが、16bit の無音は 0 である。

//table[waveformat][Waveフォーマットのデータ構造]{
サイズ	ヘッダ名	文字・数値例	説明
------------------------------------
4byte	RIFF ヘッダ	RIFF	RIFFヘッダ
4byte	ファイルサイズ	Total Byte-8	これ以降のデータサイズ
4byte	ファイル識別子	WAVE	ファイルの種類を示す識別子
4byte	fmt チャンク	fmt	フォーマット定義
4byte	バイト数	16	fmtチャンクのバイト数
2byte	フォーマット ID	1	リニア PCM なら 1、他もある
2byte	チャンネル数	2	モノラルは 1、ステレオは 2
4byte	サンプリングレート	44100	Hz で指定
4byte	データ速度	176400	サンプリングレート ×byte×ch
2byte	ブロックサイズ	4	Byte×ch数16bit×2ch=4byte
2byte	サンプルあたり bit	16	8bit とか 16bit をそのまま指定
4byte	データチャンク	Data	ここからデータ、を宣言
4byte	バイト数	TotalByte-44	波形データのバイト数
2byte	データ	00	L のデータ 1
2byte	データ	01	R のデータ 1
2byte	データ	02	L のデータ 2
・・・	以下データ		LRLR と繰り返し。
//}

==	ヘッダの生成
それでは、実際のコーディングに移る。

VB.net でのコーディング例は決して多くなかったが、そのものずばりの内容のHP@<fn>{wave}があったので、参考にした。（というか、コピペした。このなかにあるソースコードをコピペして、Sound.Makewave() を呼び出しデータ作成、Sound.Writewave() を呼び出してデータ書き込みすればよい。とのことである。とはいえ、プログラムに疎いヒト (私) は、うまく動かないのでしばらく悩んだりもした。それぞれのコードを貼り付けて、ボタンを 1 個配置した状態のコードは以下のようになる

//footnote[wave][無意識の温室栽培 http://natsuki631ppfpp.blog.fc2.com/blog-entry-3.html	VB.NET で wave ファイルを作成する その 1 http://natsuki631ppfpp.blog.fc2.com/blog-entry-5.html	VB.NET で wave ファイルを作成する  その 2]

//listnum[wave1][Wave生成コード]{
Public Class Form1
	Dim sound As Sounds = New Sounds
	Private Sub Button1 Click(ByVal sender As System.Object, ByVal e As System.
	EventArgs) Handles Button1.Click
		sound.MakeWave(1, 440, 20)
		sound.WriteWave()
	End Sub 
End Class
Public Class WaveHeader
	略：その 1 のコードをそのまま貼る
End Class
Public Class Sounds
	略：その 2 のコードをそのまま貼る
End Class
//}

//listnum[waveheader][WaveHeader生成コード]{
’ RIFF Header
Private RiffTag As Byte() ’ ”RIFF” の 4 バイト文字列を設定 
Public SizeOfFile As UInt32 ’ 全ファイルサイズ - 8 を設定 
Private WaveTag As Byte() ’ ”WAVE” の 4 バイト文字列を設定 
’ fmt チャンク
Private FmtTag As Byte() ’ ”fmt ”（スペース含む）の 4 バイト文字列を設定
Public SizeOfFmt As UInt32 ’ fmt チャンクのバイト数 LPCM ならば 16(10 00 00 00) ’ WAVE フォーマット
Public FormatID As UShort ’ フォーマット ID	リニア PCM ならば 1(01 00) 
Public Channels As UShort ’ チャンネル数 モノラルなら1ステレオなら2 
Public SamplingRate As UInt32 ’ サンプリングレート 44.1kHz ならば 44100
Public BytesPerSec As UInt32 ’ データ速度 44.1kHz 16bit ステレオなら 44100×2×2 = 176400 
Public BlockAlign As UShort ’ ブロックサイズ 16bit ステレオなら 2×2 = 4
Public BitsPerSample As UShort ’ サンプルあたりのビット数 16bit ならば 16 ’ Data チャンク
Private DataTag As Byte() ’ ”data” の 4 バイト文字列を設定
Public SizeOfBuffer As UInt32 ’ 波形データのサイズ
’ この後に波形データ
Public Sub SetParam()
	RiffTag = SingleByteChar(New Char(3) {”R”c, ”I”c, ”F”c, ”F”c})
	WaveTag = SingleByteChar(New Char(3) {”W”c, ”A”c, ”V”c, ”E”c})
	FmtTag = SingleByteChar(New Char(3) {”f”c, ”m”c, ”t”c, ” ”c}) 
	SizeOfFmt = 16
	FormatID = 1
	Channels = 2
	SamplingRate = 44100
	BitsPerSample = 16
	DataTag = SingleByteChar(New Char(3) {”d”c, ”a”c, ”t”c, ”a”c}) 
	SizeOfBuffer = 0
	CalcParam()
End Sub
//}

このように、順次ヘッダファイルを作成する。なお、SingleByteCharとは、2バイトChar型を1バイトByte型に変換するものである。VB.netのCharは2byteUnicodeで、1byte文字列を書き込む必要があるためである。

== PCM ファイルのデータ生成

次に音声データ部分を生成する。

//listnum[makewave][音声データ部分の生成]{
Public Overloads Sub MakeWave(ByVal amp As Double, ByVal freqency As UInteger, 
ByVal sec As Double)
	Dim res As UInteger = CInt(sec * CDbl(wh.SamplingRate)) 
	Dim buf As UInteger = res * wh.Channels
	Dim data As Short() = Array.CreateInstance(GetType(Short), buf)
	Dim val As Double
	’ Wave の波形データサイズを設定
	wh.SizeOfBuffer = wh.SizeOfBuffer + buf * wh.BitsPerSample / 8

	If wh.Channels = 1 Then ’ モノラル
		For i As Integer = 0 To res - 1 Step 1 
		　’ 振幅の計算
		　val = amp * t rate * Math.Sin(2 * Math.PI * i * freqency / wh.SamplingRate)
		　data(i) = CShort(val * 32767) ’ Mono Channel 
		Next
	ElseIf wh.Channels = 2 Then ’ ステレオ
		For i As Integer = 0 To res - 1 Step 1 
		　’ 振幅の計算
		　val = amp * t rate * Math.Sin(2 * Math.PI * i * freqency / wh.SamplingRate)
		　data(i * 2) = CShort(val * 32767) ’ Left Channel 
		　data(i * 2 + 1) = CShort(val * 32767) ’ Right Channel
		Next 
	End If
	datalist.Add(data)
End Sub
//}

与えた振幅、周波数、秒数に従って、Waveデータを生成する。ここでは単純に、左右同じ正弦波を生成する。データは、LRLRLR と、左のデータと右のデータを順番に並べたものである。そこで、正弦波を信号源とし左右を振り分ける形で代入することでデータ列を生成する。最後に Header部分とData部分をバイナリで保存して終了である。もちろん上記コード内の data(i) に任意の信号を入力すれば任意の波形生成が可能となる。

== 再生手順関係
このソフト単体で Wave ファイルを再生できるようにしておく。ボタンを押すと、指定ファイルを
1 回だけ再生し、もう一度押すと止まる。

//listnum[playwave][Waveの再生]{
Private player As System.Media.SoundPlayer = Nothing ’WAVE ファイルを再生する
Private Sub PlaySound(ByVal waveFile As String)
	If Not (player Is Nothing) Then
		StopSound() ’ 再生されているときは止める
	Else
		player = New System.Media.SoundPlayer(waveFile)	’ 読み込む
		player.Play() ’ 非同期再生する 
		’player.PlayLooping() ’ ループ再生する 
		’player.PlaySync() ’ 最後まで再生し終えるまで待機
	End If
End Sub
Private Sub StopSound() ‘再生されている音を止める
	If Not (player Is Nothing) Then 
		player.Stop() 
		player.Dispose()
		player = Nothing 
	End If
End Sub
Private Sub btnplaySound Click(ByVal sender As System.Object,ByVal e As System.EventArgs) 
Handles btnplaySound.Click
	PlaySound(”C:\test.wav”)
End Sub
//}

もちろん、Dialogより再生ファイルを指定してもよいし、保存したファイル名を覚えておいてそれを再生するようにしてもよい。
ファイル名を引いて保存したファイルを再生するには、Public  Class  Sounds 内にファイル名格納用の Public 変数を宣言し、WriteWave()内の SaveFileDialog で指定したパスを再生対象のファイル名に格納する

//listnum[saveWave][ファイルを保存する]{
Public Class Sounds
	Public savedwavefilename As String ‘追加
Public Overloads Sub WriteWave()
	Dim sfd As SaveFileDialog = New SaveFileDialog()
	‘略
	Try
	fs = sfd.OpenFile()
	savedwavefilename = sfd.FileName ‘追加 ‘略
Private Sub btnplaySound Click(ByVal sender As System.Object,ByVal e As System.EventArgs) 
Handles btnplaySound.Click
	’PlaySound(”C:\test.wav”)  ‘これを
	PlaySound(sound.savedwavefilename) ‘こう書き換える
End Sub
//}

これらの内容は、プログラムに慣れた人なら言うまでもないことであることは認識しているが、躓いた内容なので自分用に記録しておく。Savewavefilename への格納がうまく行かなかったり、 Form1 から引けなかったり、細かいトラブルがあったためである。だからプログラミングの苦手意識は抜けない・・・

== XYデータファイルの生成
次は、一筆書きしたデータテーブルを音声ファイルに代入する方法である 基本的には、位置データを格納した変数 PosX、PosY を用いて、MakeWave 内のデータ配列生成部分に代入すれば良い。

//listnum[saveXYdata][XYデータファイルの生成]{
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
	ElseIf wh.Channels = 2 Then ’ ステレオ ’
		'For i As Integer = 0 To res - 1 Step 1
		For i As Integer = 0 To rep - 1 Step 1
		’ 振幅の格納。 n 点のたびに最初に戻り、波形データを入れる。
			For j = 0 To Form1.n - 1
			’val = amp * Math.Sin(2 * Math.PI * i * freqency / wh.SamplingRate) 
			data((i * Form1.n + j) * 2) = CShort(Form1.posX(j) * 32678) ’ Left 
			data((i * Form1.n + j) * 2 + 1) = CShort(Form1.posY(j) * 32678) ’R ’
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

次に、適宜振幅やサンプリング周波数の調整を行う。サンプリング周波数は、44k も必要ないので、4.4k としておく。もちろん変更することは容易である。このあたりは、実際にガルバノスキャナを動かしながらチューニングする必要がある。描画そのものは 30fps 相当程度あれば十二分で、とりあえずなら 10fps 程度でも十分と考えられる。そのため、例えばデータ点数を考慮して自動で周波数を変えるなどの機能があっても良いかもしれない。

==	Memory Steram を用いた直接出力
本節では、Wave ファイルへの出力をファイルに保存しないで直接オーディオ端子から出力する方法について記述する。Wave ファイルの生成や取り扱いについては前節を参照いただきたい。
 
ここでは、Wave ファイルに保存する代わりに、Memory  Stream を利用する@<fn>{memorystream}。
//footnote[memorystream][http://blog.ume108.mobi/?p=837 うめつる開発室  Memory  Stream で音を再生する]

Memory  Stream とは・・なんだろう。よくわからんので、MSDN を見てくださいな。要するに、データを展開する先として、ファイルではなく、メモリを使う、ということで、バイナリデータを扱える仮想的なファイル的なものと考えればよいのか。今回はファイルとして書き出す代わりにメモリ上にバッファし、それを再生するのに使う。基本的な方法としては、普通の Wave ヘッダとデータを作り、それを BinaryWriter でファイルに書き込む代わりに、StreamWriter にて MemoryStreamに書き込む。

これで、とりあえず、作ったファイルを Memory  Stream から再生できるようになった。最初は、Try∼End Try の後ろに、Player を追記しただけだったが、それでは閉じたストリームを参照することになってしまうため、Object Disposed Exception がスローされる。これに気づくのに半日かかったわけだが。End∼Ttry で Memory Stream を閉じる前に再生する必要がある。また、これでは再生したものを止めることができないため、Play/Stop ボタンに機能をもたせる。再生するだけなら、参照に気を付ける必要はあまりないが、停止操作をボタンなどから行う場合は、参照を可能にしておく必要がある。

//listnum[play][参照の調整]{
	’再生だけはできる
	Public player As System.Media.SoundPlayer = Nothing
	’止めるときにメインのClassから参照する必要がある
	Public Shared player As System.Media.SoundPlayer = Nothing
//}

その他にも、WaveHeader や波形データをクリアするコードを入れたり、細かいところにいろいろ手を入れている。結果、生成したWaveファイルをファイル保存を経由することなく再生し、停止、消去を可能となった。