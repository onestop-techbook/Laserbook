= DA ボードによる描画信号源の製作

ここでは、DA ボードを利用したファンクションジェネレータを制作し、ガルバノスキャナとレーザポインターによるお絵かきシステムを製作する。DA ボードの選定、環境設定、コーディング等について述べる。

== DA ボードの選定
本節では、DA ボードを用いたファンクションジェネレータソフト製作について述べる。

私的な理由により、使用する言語は VisualBasic.net(2013) である@<fn>{VB}。単に私が比較的自由に使えるのが VB.net であるという理由による。また使用するボードは、CONTEC の DA ボードである。 AIO-160802AY-USB などが比較的安価で使いやすいと考えられる。他のメーカーの DA ボードでも問題ないが、入手性などの点から、本稿では AIO-160802AY-USB を用いる。16bit 分解能、入力 8ch、出力 2ch、カウンター 1ch のマルチファンクションボードである。CONTEC は関数がいろいろなボードでほぼ共通であり、接続バスや型番が変化しても関数などは共通で、プログラムはほぼそのまま利用できるというメリットがある。

//footnote[VB][本書前半はVB.netで制作しているが、後半はC#になる。原稿作成の途中で必要に迫られC#を学んだためである。VB.netの部分をC#に書き直すことも検討したが、作業負荷的に困難であったため、そのまま掲載することとする。ご容赦いただきたい。]

=== 環境設定
CONTEC の AD/DA ボードはサンプルプログラムが充実しており、ソースも添付されているのでそのまま使っても必要な機能を達成できる場合が多い。また追加の参照などの環境設定も完了しているので非常に便利である。しかし、最初から作成する場合などに、やり方を忘れてしまい長時間ハマるということが少なくないので、最初からコーディングする手順を示す。


==== AD/DA ボードのインストール

USB を接続すると、（あるいは PCI バスにカードを差し込むと）ハードウエアウィザードによって自動で認識する。

ドライバ CD をいれ、ドライバーをインストールする、と言いたいところだが、添付ドライバではなく、公式 HP に公開されている最新版を使用するべきである。Contec のドライバは常時更新されており@<fn>{contec}、新しい機能が追加されたり、動作がより安定したりしている。

基本的な動作であれば、多少古いドライバでも問題ない場合が多いが、スペックの限界近いところを使う用途などでは、マイナーバージョンによって微妙な挙動が異なり、ハマる事がある。最近のプレリリース版になってようやくとあるボードがWindows7x64に対応し、しかもそれはプレリリース版にしか入ってないとか、本来は対応しないにもかかわらず対応すると書いてあるなど、ハマる要素が多分にある。

さて正常にインストールされていれば、デバイスマネージャ上に CONTEC DEVICE>AIO160802AY“AIO000”などと認識される。なおデバイス名のあとの文字列、上記の例では AIO000 は、あとのプログラミング作業で使用するので、覚えておくこと。

//footnote[contec][こっそり更新して、しかも HP の深い階層にしか書いてないとか、中身の記述が間違ってるとかやめて欲しい。]

==== 新規プロジェクトの設定
Visual  Studio(以下 VS) を起動し、VB → Windows → Windows フォームアプリケーションを選択し、新しいプロジェクトを起動する。

次に、ボード関係の関数の定義ファイルを読み込む。AD/DA ボード固有の命令や関数、定数など、および DLL との連携を示すファイルである。ファイル名は Caio.vb である。このファイルを参照しておかないと、ボードが全く動かない。そもそも命令の関数が動かないので、文法エラーでコンパイルエラーとなる。

プロジェクト＞既存項目の追加＞から、CAIO.vbを探して追加する。

CAIO.vbは、C:\Program	Files\CONTEC\API-PAC(W32)\AIOWDM\Sample\Incまたは、他のサンプルプログラムのフォルダ中にあるので、適当なのを選べば良い。

CAIO.vbの中には、パラメータの定義や説明、戻り値や固有関数の定義が含まれている。なので、このファイルを参照しておくことで、プログラム本体でボード関係の関数を使うことができるようになる。

//listnum[caio][CAIO.vbの中身]{
'パラメータの略語の定義や説明
Public Const PM10 As Short = 0	’±10V
'イベントの戻り値の定義、
Public Const AIE START As Short = &H2S ’AD 変換開始イベント
'固有関数の定義
Declare Function AioInit Lib ”CAIO.DLL” (ByVal DeviceName As String, ByRef Id As Short) 
As Integer
//}



CONTEC の関数の基本形は、

//listnum[standard][基本動作例]{
Ret = AioInit(DeviceName, Id) ’Init Device@VB
Ret = aio.Init(DeviceName, out Id); ’Init Device@C#
//}

//noindent
という形であり、上記の例では、DeviceNameとIdを引数にデバイスを初期化する命令である。また、その関数が正常に動いた時の戻り値Retは0であり、関数の動作にエラーがあった時には戻り値Retが0以外の値となる。そこで、

//listnum[initwork][基本動作例]{
Ret = AioInit(Text Device.Text, Id) ’ Init Device If Ret <> 0 Then
Ret2 = AioGetErrorString(Ret, ErrorString)
Text ErrorString.Text= ”AioInit=” &Ret & ”:” & ErrorString.ToString() Exit Sub
End If
//}

とすることで、戻り値の参照とエラーの内容を表示することができる。たとえば二重起動などのときには、
AioResetDevice = 20003 : Can not use because another process is using the device
などといったエラーメッセージによりデバッグが容易になる。

== コア部分のコーディング

以下、DA ボードによる描画ソフトの出力部分のコーディングの基本的なところを記述していく。サンプルプログラム内の
C:\Program  Files\CONTEC\API-PAC(W32)\AIOWDM\Sample\VbNet\Ao\SingleAo
を開くと良いし、もちろん、一から作ってもよい。

=== ボードの初期化

ボードの初期化は、以下の関数群を使う。

//listnum[init][ボードの初期化]{
Devicename = ”AIO000” ’DeviceName Ret = AioInit(Devicename, Id) ’Init
Ret = AioResetDevice(Id) ’Reset device
Ret = AioSetAoRangeAll(Id, 0) ’Set Output Range AoChannels = 2 ’Output channel = 2 (XY)
Ret = AioSetAoChannels(Id, AoChannels) ’Set Output Channels
Ret = AioSetAoSamplingClock(Id, 1000) ’Samplimg Clock=1000usec Ret = AioResetAoMemory(Id) ’Reset memory
tbStatus.Text = ”Init Finish” ’Init Finish
//}

ここでは、エラーメッセージの処理は省略している。

出力レンジの設定は、0すなわち±10Vである。CONTECのADボードは、デフォルト設定値が0であり、変更しないパラメータは標準値を使えば良く、省略可能である。ただし他のプロセスやDiagソフトで動作状態を確認した場合など、意図しない状況で変更される場合がある。さらに一度変更されれば次に明示的に設定がなされるまでその値を保持する。例えば出力レンジが0~5Vに変更された場合、オフセットのないSin波を出力しようとしても、マイナス側がクリップされることになる。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap4/image1.jpg}
\caption{ボード設定ミスによる出力不良例（出力レンジ設定の不良）}
\end{figure}
//}

そのため、出力レンジ以外のパラメータについても、たとえ標準値 0 を入力する場合であっても、おまじないだと思って明示的に設定条件を入力することが望ましい。

実際この問題でハマったことがある、図4.1 にオシロ波形を示す。出力設定レンジ 0∼5V の設定で、出力振幅 2V(±2Vpp) 設定の正弦波を出力した際の波形である。崩れた矩形波と、半波正弦波のような形になっていることがわかる。実はこの問題が発生した時、レンジ設定を省略していた。そのため、過去の設定により出力レンジが変わった状態であった。コードにミスはないのに、挙動がおかしくなっている状態であり、このようなトラブルを防ぐため、設定条件の明示化は必要である。
 
===	DA 変換条件の設定
出力データを格納したデータテーブルを準備しておき、そのデータを逐一読み出し、DA変換するという手順による。そのため、データテーブルのサイズを決定し、データを作成する必要がある。ただし、データ生成部分は後でコーディングするので先にデバイスの設定を行う。なお、AoDataは、出力データを格納する配列であり、次節でデータを生成する。

//listnum[DAsetting][DA変換条件の設定]{
’Output Setting
AoSamplingTimes = 1000 ’AO sampling times = 1000
Ret = AioSetAoSamplingDataEx(Id, AoSamplingTimes, AoData) Dim AoEvent As Integer
AoEvent = AOE END Or AOE DATA NUM Or AOE DAERR
Ret = AioSetAoEvent(Id, Handle.ToInt32, AoEvent) ’Stop after 500 sampling
Ret = AioSetAoEventSamplingTimes(Id, 500)
tbStatus.Text = ”DA Setting Finish”
//}

===	変換データの生成
AoData(2000) という一次元配列を確保し、データを格納する。 とりあえず、2ch、1000 点のデータなので、2000 確保しておく。
データは、サンプリング 1 回目の 1ch データ、サンプル 1 回目の 2ch データ・・・、サンプリング 2 回目の 1ch データ、サンプリング 2 回目の 2ch データ・・・、サンプリング 3 回目の・・・・サンプリング 4 回めの・・・サンプリング n 回目の・・・という配列になる。

//listnum[makedata][変換データの生成]{
Dim AoData(2000) As Single Dim AoSamplingTimes As Integer AoSamplingTimes = 1000 ’Generate AO data
Dim i As Short ’Sampling count Dim j As Short ’Ch
Dim AoVolt As Single
For i = 0 To AoSamplingTimes - 1
    For j = 0 To AoChannels - 1
    ’ Generate Sin wave
        AoVolt = 10.0 * System.Math.Sin(2 * PI * i / AoSamplingTimes)
        AoData(i * AoChannels + j) = AoVolt
    Next j
Next i
//}

出力信号を変更する時には、AoData() の中身を変更し、再度 DA 変換設定を行い、データを入力する必要がある。そのため、データ生成部分と、DA 変換設定は、サブルーチンとして独立させておくことが望ましい。

=== イベントサブルーチンの設定

データ出力が終わったあとの処理を記述する。データ列は 1ms サンプリングで 1000 点なので、1周期 1 秒で終了する。連続して出力するためには、波形出力が終わったことを検知し、次の波形を出力する命令を出す必要がある。そのためのイベントルーチンを設定する。

//listnum[event][イベントサブルーチンの設定]{
Protected Overrides Sub WndProc(ByRef m As System.Windows.Forms.Message)
    Select Case m.Msg
        ’ 指定回数 DA 変換終了イベント
        Case AIOM AOE DATA NUM
            ’Show Event times
            AoEventCount = AoEventCount + 1 
            ’Set output data again
            Ret = AioSetAoSamplingDataEx(Id, AoSamplingTimes, AoData) 
            tbErrorString.Text = ”Output continue”

        ’DA 出力エラーイベント
        Case AOE DAERR
            tbErrorString.Text = ”Stop due to Error”

        ’ デバイス終了イベント
        Case AIOM AOE END
            tbErrorString.Text = ”Stop output” 
            ’Get Status
            Ret = AioGetAoStatus(Id, AoStatus) 
    End Select
    MyBase.WndProc(m)
End Sub
}

指定回数の DA 変換が終わったことを検知すれば、AO を再実施する。エラーを検知すれば、エラーで停止したことを示す。AO が終了した時には、出力が終了したことを検知する、という動作をする。

===	停止コマンドと終了コマンド

信号出力を停止する場合および終了時のコマンドについて記載する。停止はそのままの意味であるが、終了時には、きちんとデバイスを開放しないと、次回不具合が発生することがある。

listnum[stop][DA停止、ボード停止]{
Ret = AioStopAo(Id) ’DA Stop
Ret = AioExit(Id) ’Exit device
//}

ここまでの実装で、2ch の正弦波を出力するプログラムが完成した。実装内容はサンプルプログラムとほとんど同じだが、出力が 2ch になっている。そのため、出力されるのは1Hzの正弦波が2ch分出力される。出力波形を図 4.2 に示す。出力振幅 ±10Vpp で 2 現象の出力になる。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap4/image2.jpg}
\caption{実装したサンプルの出力例}
\end{figure}
//}

なお波形が歪んでいるように見えるが、後述する DA サンプリング周波数の設定不適切に基づくものである。オシロ自体のノイズもあるが、現時点では無視する。

=== 振幅設定
次に、振幅変更を実装する。トラックバーを配置し、名前を例えば TrackBarPPx とする。また、値の表示のために、テキストボックスを追加し、名前を tbPPx とする。

//listnum[ppsetting][振幅の設定]{
PPx = TrackBarPPx.Value
tbPPx.Text = TrackBarPPx.Value
For i = 0 To AoSamplingTimes - 1
    AoVolt = PPx * Sin(2 * PI * i / AoSamplingTimes)
    AoData(i * AoChannels) = AoVolt
Next i
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap4/image3.jpg}
\caption{振幅設定の実装}
\end{figure}
//}

===	周波数設定および位相設定
ほぼ同様の手順にて、周波数および位相の設定を追加する。

//listnum[freq][出力周波数の設定]{
Xfreq = TrackBarXfreq.Value
tbXFreq.Text = TrackBarXfreq.Value
For i = 0 To AoSamplingTimes - 1
    AoVolt = PPx * Sin(Xfreq * 2 * PI * i / AoSamplingTimes)
    AoData(i * AoChannels) = AoVolt
Next i
}

周波数を変更すると、テーブルが書き換えられ、出力周波数が変更される。図4.4に1Hz と2Hzの出力例を示す。振幅、位相とも同じで、周波数の2倍異なる波形が出力されていることが確認で
きる。

また同様の手順であるが、位相の変更を行う。トラックバーの名前は、TrackBarPhase である。ただし、位相は X 出力に対しての位相差で定義すればよく、Sin 波のみを考えるならば遅れ位相と進み位相は等価なので、0 360° の範囲で設定しておく。

//listnum[phase][出力位相の設定]{
Xfreq = TrackBarXfreq.Value
tbXFreq.Text = TrackBarXfreq.Value
For i = 0 To AoSamplingTimes - 1
    AoVolt = PPx * Sin(Xfreq * 2 * PI * i / AoSamplingTimes)
    AoData(i * AoChannels) = AoVolt
Next i
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap4/image4.jpg}
\caption{周波数設定の実装}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap4/image5.jpg}
\caption{位相設定の実装}
\end{figure}
//}

途中から位相が変わっていることがわかる。なお、ヒゲが出ているようだが、この理由については、現在確認中である。

現在のコーディングでは、Setを押すと直ちにテーブル書き換えが行われ、出力がなされる設定になる。そこで、設定変更の際には、一旦出力を停止し、テーブルを書き換え、サンプリングカウントなどをリセットした上で出力を開始する形のコーディングを行うことが望ましい。以上、必要なすべての機能を導入した、ファンクションジェネレータができた。

===	上限周波数とサンプリング周波数の調整
Contec の関数におけるサンプリング周期設定は µ ｓ単位であるから、現在のサンプリング周波数設定値は 1000µs=1ms である。したがって、100Hz 付近を超えたあたりから、階段状の波形ひずみが顕在化する（図 4.5）。100Hz の正弦波なら 1 周期が 10ms であり、10 点で表現することになるためこのような事が起こる。具体的には 1ms の間は、出力がクリップされてしまい波形が階段上になるわけである。

このボードのサンプリングの最大は、10µs=100kHz であり、kHz 程度の周波数を扱う場合にはサンプリングクロックを調整する必要がある。また、それに合わせて、データ点数を増やし、波形を調整する必要がある。そこで、ボード設定の部分で以下のようにし、サンプリング周期を 10kHz とする。単純にサンプリング周波数を増やすだけでは、データ長不足などが起こるため、他の場所も修正する。このあたりを調整することで、サンプリング点数が 10 倍になり、なめらかな波形が表現されることになる。

//listnum[sampling][サンプリング周波数の変更]{
Ret = AioSetAoSamplingClock(Id, 100) 
Const DATA MAX As Integer = 20000 
Dim AoData(20000) As Single
AoSamplingTimes = 10000
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap4/image6.jpg}
\caption{DAのサンプリング周波数が低い時}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap4/image7.jpg}
\caption{DAのサンプリング周波数を上げる}
\end{figure}
//}