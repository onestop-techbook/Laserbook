= プリント基板製作超入門

本章では、レーザープロジェクター用の電源スイッチの基板を起こしてみた件について記述する。まずそもそもどういう話の流れから基板を起こすことになったのかを述べたのち、基板の設計方針、実際にハマった部分や困った部分について述べる。トラ技で特集されたり、電子工作島界隈でも基板を起こしている人が増えているなど、基板起こしのハードルは非常に下がっている。乗るしかない、このビッグウェーブに！


== 動機：グリーンレーザーモジュールが発振しない件

C89、C90とも最初の動作チェック時点では動作していたものが、水冷ユニットを接続した途端にレーザーモジュールが発振しなくなるという現象に見舞われた。C89から戻ってから自宅で安定化電源にてチェックしたところ発振したが、C90後のチェックではやはり発振しなかった。ある程度の電圧をかけても電流もほぼゼロであるから確かに故障したと考えられる。

しかし、ポンプを接続する前には動作していたものが、ポンプを動かした直後に故障する というのは解せない。となるならば、例えば、モーターの突入電流によりしきい値を超える ような電圧がかかってしまった可能性がある。そこで、レーザーモジュールの交換を含めて、以下の3点を実施した。

 1.	レーザーモジュールを交換する。
 2.	レーザーの電源と水冷モジュール電源を分離する
 3.	水冷ユニットごと予備を作る。

2について、レーザー電源の設計と、電源基板製作として、本章で取り上げる。水冷ユニット製作は次の章で取り上げる。

=={chap11-laser} レーザーモジュール電源の設計
レーザーモジュールは電源電圧3V出力5mW以下というスペックのものをeBayにて購入した。
5個セットで36.99ドルで、購入時は1ドル102円程度なので、3750円程度であった。送料込みなので、単価750円ほどになる。

レーザーモジュール自体は購入から1週間ほどで到着した。最近の国際郵便は優秀である。そして、5mW以下ということだが、3Vフルにかけると眩しいこと眩しいこと。緑は人の感覚的感度が一番高い波長であるとはいえ、フルに使うと明るすぎる。レーザーパワーメータでの確認と、適当な明るさにするため、電源を新規設計することとした。基本的には、何らかの方法で適当な明るさに制御することとしたい。ただし現地での調整も含めてボリュームで分圧する程度でよいと考えている。

事前テストにおいて、安定化電源で通電してみたところ、2.25V程度、200mAで十分すぎるくらいの輝度が得られることがわかった。また、電源は、入力12Vを出力5Vに変換する DC-DCモジュールが手元にあるので、これを使うこととする。Cosel SUS3 3W、12V入力 5V600mA出力、定価1040円。これまでの電源装置でも使用していたものである。この5Vを適当に分圧して明るさ制御を行うものとする。

以下、我流ではあるが、素子選定を行ってみる。

 1. 輝度調整を行う必要があるから、ボリュームとする。
 2. 輝度の観点から、最大200mAに制限する。これは、過電流・過電圧によるレーザーモジュールの故障を防ぐためである。5Vの電源に対して200mAに制限するためには、少なくとも25Ω以上の抵抗を持つことが必要である。通常のボリュームは0～公称抵抗値までであるから、ボリュームと直列に25Ωの抵抗を入れておくと良いことがわかる。最大回しきっても、最大輝度に制限されるということである。
 3. 5V200mAがフルに流れた場合、全体の消費電力は1Wとなる。安全のため、そのすべてがボリュームにかかったとして、ボリューム自体の定格も1Wとする。そして、抵抗値の上限であるが、抵抗値があまり大きいと負荷側の輝度制御がしづらくなるから、25Ωとか、50Ωを狙った。とりあえず50Ωで探してみると、マルツでRA25Yというシリーズのボリュームがあり、10Ω、20Ω、50Ωなどいろいろ選択可能であった。定格も1.2Wと申し分ない。しかし、ネックは価格で、Web価格が665円、送料などまで入れると1個1000円近くなってしまう。

そこで、ついでもあったのでボリュームについて千石、秋月の実店舗で確認することにする。秋月で小型ボリューム100ΩB特性を入手してみた。定格0.125Wと、サイズの割にしょっぱいなぁ、というのが正直なところであるが・・と書いていて、これで足りるかかなり不安になったので、改めてきちんと計算することにする。

//blankline

前提:

電流制御範囲：0～最大 250mA

入力電圧：5V

レーザーモジュールの適正動作点の電流電圧：2.5V	0.2A

//blankline

したがって、外付け抵抗で落とすべきボリュームに掛かる電圧は2.5Vとなる。ボリュームとレーザモジュールを直列接続してボリューム調整したところ、10～15Ωくらいが適当であることがわかった。この時のボリュームでの消費電力は0.4W～0.6Wとなり、ボリュームの定格を超えてしまうことがわかった。したがって、ボリュームでの調整は諦めた。

諦めたところで、別件で可変のDC-DCコンバーター@<fn>{dcdc}を購入していたことを思い出した。入力電圧4.5V～28Vで、出力0.8V～20V,Max3Aを利用したものである。送料込みで1個170円くらいと激安である。そこで、今回は輝度調整にこれを使うこととした。こういう便利なものばっかり使ってると回路の基礎とかがわからなくなるのではないかとは思いつつ、実装の容易さ、入稿デッドラインの関係から易きに流れることにした。

== 電源ユニット用の基板を起こす
さらに、電源スイッチ基板を起こすことにした。C89後の2016年正月に立てた同人活動における年度目標の一つが「基板を起こす」である。当初はArduino基板を作る予定であったが、手半田でとりあえず動いているからこちらには手を入れず、逆に優先度が高そう( かつ実装・設計が簡単そう)なスイッチ基板をつくることにした。現状の電源装置はあるが、アナログメーターとスイッチで既に一杯であり、見た目にも、取扱も微妙なので、新調する。アナログメーターは見た目一発で再度取り付ける予定であるが。

基板製作についての参考文献は以下の通り。

 * トランジスタ技術 2016 年 7 月号
 * 自作基板への道 電脳律速 2016 年 8 月 14 日発行

これらの本を参考にしつつ、基本通りに仕様設計→回路図作成→フットプリント設定→基板レイアウト→基板発注→部品実装という流れを追ってみる。トラ技のチュートリアルの劣化版@<fn>{rekka}になるかもしれないが、そうは言いつつハマったところを説明してみたい。経験ある人には当然の内容かも知れないがおつきあいいただけると幸いである。

//footnote[dcdc][DC-DC Buck Converter Step Down Regulator Power Module 3.3v 5v 9v 12v Adjustable http://www.ebay.com/itm/122001065930	価格 $1.58/個（送料込み！）]
//footnote[rekka][ちょっと話は変わるが、だいぶ昔の話、「初心者でも PC で絵を描く」といったよくあるチュートリアルを見たことがある。チュートリアルの冒頭が「さあこの下絵をスキャナで取り込んで」から始まったので、「その下絵が問題なんだよバカヤロウ」と毒づいた絵心のない筆者が通ります。ただし、決してトラ技のチュートリアルがダメといっているわけではない。とはいえ、いろいろ端折ってあるために分かりづらかったところがないわけではない。例えば、後述する「すべてのフットプリントを展開」がどこにあるのかの説明がトラ技の記事の中にはなかったためにハマった、などがあるため、一通りの過程を記載する。]
 
=== 作るものを考える。
まず初めに実施すべきは、何を作るかを考えることである。必要な機能と、入出力の制約、希望寸法などを書き出し、仕様設計を行う。これは回路図の前の段階であり、回路図の素を作ることである。この時点では、基板CADなどは必要なく、必要なのは紙と鉛筆である。

今回制作する基板に必要な機能は、12Vの入力をそれぞれの機器に供給する装置である。それぞれの装置は電圧も電流も異なるし、使ったり使わなかったりするから、それぞれにスイッチとインジケーターLEDがあると便利であろう。DC-DCコンバーターも載せると使い易いが、他への転用が効かなくなる。また、パネルメーターも載せたら便利だが、基板サイズが大きくなってしまいコストが上がってしまう。これらのことを書き出しながら、設計を進める。

最終的に作るものは、以下の通り。

 * 鉛シール電池の出力をそれぞれのDC-DCコンバーターに入力するためのスイッチとインジケーターLEDを並べたもの
 * 出力はコミケで使う可能性がある5点とする。

 1. ガルバノ
 2. レーザー
 3. 水冷ポンプ
 4. ノートPC
 5. Arduino

 * 出力毎に使う／使わないを選択可能。メインスイッチと、インジケーターランプもあり。
 * 出力5点とメインスイッチがあるため、ランプ・スイッチはそれぞれ6点。
 * DC-DC、メーター類はリード線渡しとし、別基板に実装する。
 * 基板は小さめに作る。実装も楽だし、基板も安い。安い方が良い
 * 入力はターミナルブロックとする。
 * 入力1点、出力5点なので、ターミナルブロックも6個

以下、幾つかの項目について補足する。

@<em>{コネクタにするか、パッド渡しにするか}

パッド渡しでリード線はんだ付けとしたほうが安価かつコンパクトにできるが、パッド部での配線折れが発生する懸念がある。自宅であればすぐ修理できて何の問題もないが、会場で修理することはほぼ不可能であるから、ターミナルブロックを取りつけ、リード線を直接取り付ける形とした。

電流・電圧計を取り付ける予定であるが、これも同じ理由から、カシメリード線での取付けとした。異論・ツッコミはあろうが、はんだ付けしたリード線ははんだ付けの付け根で折れることがあり、コミケ会場のように修復が不可能な状況では大きなリスクとなる。バラ線部と半田部で線の硬さに差があるから応力集中しやすくなるのが折れる原因である。
 
@<em>{表面実装かスルーホール実装か}

配線実装の部分で問題となるのだが、面実装部品を使うか、スルーホール部品を使うかという問題がある。どちらでも本用途においては特段問題にはならないが、今回はするーホール部品を使用した。

===	回路図の作成
この設計をもとに、回路図を引く。まずは手書きでよい。入力ポートがあり、メインスイッチがあり、LEDがあり、おっと電流制限抵抗を忘れてはいけない。

初段の出力とGNDを引っぱり、スイッチで受け、DC-DCへのターミナルブロックに出すとともに、インジケーターLEDを付ける。

トグルスイッチは両ONタイプでとりあえず実装する。1を入力側、2を出力として、3ピンは2ピンにショートしておく。ON時にLEDが点灯するように、スイッチの出力線から電流制限抵抗を挟んでGNDに接続する。12Vで10mAもあれば十分なので、仮に1kΩとしておく。超高輝度タイプで標準電流が20mAとかなので、実装のときに調整するものとする。出力は、とりあえずパッドのイメージで○を書いておく。手書きの回路図を図11-1に示す。字が汚いとか抵抗表記が旧版というツッコミは無視する。四角だけで抵抗というのはぱっと見のイメージが掴みづらいのだが・・・

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-1.jpg}
\caption{スイッチ基板の回路図(手書き)}
\end{figure}
//}

回路図の作成にあたっては、信号の流れ順に並べるとか、部品数個の機能ブロックごとにデータシートにある標準回路を配置するとか、いろいろな方法がある。今回は、とりあえず 1個目のスイッチを置いて、出力ラインとGNDを二本引張り、そこにスイッチとLEDと電流制限抵抗を置き、それを4個コピーするという方法で実施した。

===	回路図を KiCAD に入力する
作成した回路図をKiCADに入力する。

参考文献としてまずはトラ技2016年7月号を買ってから話をすすめることとする。 Amazonでも普通に買える@<fn>{toragi}ので、まずは買って、手元に置きながらすすめると良い。

スイッチは、両ONなので、SWITCH_INV、抵抗、LEDはそのまま入力すれば良い。出力端子は、CONN_01x02としておく。配線をすべての端子につなぎ、交差しているところはジャンクションを打っておく。この時点ではどの部品を使うか、サイズはどうか、などは考えなくて良い。

//footnote[toragi][Amazonでも普通に買えると思っていたが、現在マーケットプレイスでの中古扱い品しかなく、しかも価格が上がっている。残念。(2016.11.27時点)　しかしながら、ここ数年毎年1回程度、プリント基板のつくり方特集の巻があるので、入手には困らないと考える。]

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-2.png}
\caption{KiCAD に入力した切り替え基板回路図}
\end{figure}
//}


回路図という意味で、部品の選定と結線が一通り終わったら、ERC(Electrical Rule Check)をかけて、未接続がないかを確認する。あわせて回路定数の入力を完了させる。回路定数が異なっていても誰か(ERCの中の人)に怒られるというわけではないが、手書き図面をクリーンアップすることで設計確認の意味もあるので、一旦ここで入力する。端子の未接続があると怒られるので、ここは修正する。接続のない、あるいは接続してはならないピンが出て来る場合がある。こういう場合は、明示的に未接続フラグを立てておく必要がある。そうしないとERCが通らない。未接続ピンの処理をする癖は付けておくと良いようだ。

その後、ネットリストを出力する。ネットリストとは、どの部品とどの部品がつながっているのかを示すテキストである。例えば、Sw1の2番ピンとD1の1番ピンがつながってるよ、D2の2番ピンとGNDがつながってるよ、という情報であり、中身はその情報を含んだテキストファイルが出力される。ここはチュートリアルの手順に従ってそのままやればよい。

===	回路シンボルとフットプリントの紐付け
フットプリントとは、使用する部品のピン・パッドの形状と配置(および外形形状)の情報であり、フットプリントが決まらないと部品配置と結線ができない。同じ部品でも、スルーホール品と表面実装部品では当然フットプリントは異なるので、部品配置前のこの段階で決定する必要がある。ある程度有名な部品はフットプリントがKiCADのライブラリに登録されているが、マイナーな部品(特にコネクタやスイッチなど？)は登録されていない場合があり、使用部品のフットプリントがない場合は手動登録する必要がある。とはいえ、新規登録も面倒なので、まずはライブラリに登録のある部品を主に使うということで構わないと考える。

さていよいよそれぞれの部品にフットプリントを紐つける作業を行う。部品の物理的形状を反映したものであるから、部品が異なれば当然フットフリントも異なる。回路図上は同じものであっても、スルーホール部品と表面実装部品、あるいは定格や取付方向のある部品等、部品によってフットプリントは異なる。例えば、同じ1kΩの抵抗があったとして、回路図上は単に1kΩの抵抗である。しかしフットプリントは、例えば、定格1/4Wのカーボン抵抗と、チップ抵抗、またセメント抵抗や巻線抵抗など、サイズ、定格によって異なる。またコネクタやスイッチなど、垂直タイプと横向きタイプ等、があるものなど、部品によって異なることは明らかであろう。

なお、フットプリントの紐付けであるが、正直ここが一番手間取った。なぜなら、使う部 品が既存のライブラリに登録されていない場合は自分で作らなければならないからである。すなわち、使いたい部品をこの時点で決定する必要があるということである。もちろんあと から変更する事もできるが、だからといって未定のままでは次の作業に進めないので、部品 調達の容易さや寸法を参考にしつつ部品を決定しておく。あとで変更する場合、部品レイアウト、配線などをやりなおす必要が出てくる場合がある。

今回ハマったのは実はスイッチで、両ONのトグルスイッチのフットプリントが登録されていなかった。（実はあるかもしれないが見つけられなかった）。そこで、フットプリント紐付け作業の途中で秋月に行き、先に部品選定・購入を行った。部品を決めてから、それに合わせてフットプリントを自前登録するということである。

さて基板用トグルスイッチは意外と選択肢が少なく、事前に千石で見ていたところ、1個160円もするため選定を保留していたのである。結局、秋月で購入することとした。今回は基板用トグルスイッチ3P24を選んだ。基板1枚あたり6個使うので安価なものを使いたい、スルーホール用、小型、容量十分等から、これを最適とした。

ファイル→新規フットプリントで、新しいフットプリントを作り、パッドを並べる。今回使った3P用は両端に固定用ピンがあるタイプなので、1～3のほかに2個パッドを作っておく。外形も線を引き、保存する。

//footnote[akiswitch][基板用トグルスイッチ 3P(2MS1-T1-B4-VS2-Q-E) 250V1A/120V3A http://akizukidenshi.com/catalog/g/gP-00300/]
 
基板全体を小型化するには、表面実装部品を使うと良いのだが、表面実装部品ははんだ付けが大変でもある。もっとも、抵抗単体やチップLEDくらいならその苦労もたかが知れているかもしれないが・・・今回は一旦全てスルーホール部品で対応することとした。量産するなら表面実装部品を使って、かつ実装サービスを利用するなども可能であるが、当面そのような予定はない。

図11.3に今回登録したフットプリントの図を示す。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.3\linewidth]{images/chap11/image11-3.png}
\caption{登録した小型スイッチのフットプリント}
\end{figure}
//}

グリッドは 1.27mm ピッチであり、外形寸法は 5.08mm×10.16mm となる。アクティブなピンは 1～3で、取り付け用ホールが H1,H2 となる。都合 5 つのピンが一列に並んでいることになる。これを適当な名前をつけて保存した上で、フットプリントライブラリーに登録する。

設定＞フットプリントライブラリーウィザード＞このコンピュータにあるファイル＞Finish

で登録することができる。登録したフットプリントがフットプリントビューア（ライブラリブラウザ）から確認できるようになっていれば正常に登録されている。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-4.png}
\caption{フットプリントビューア}
\end{figure}
//}

===	部品の配置・レイアウト
次に、部品の配置・レイアウトを行う。ここで製作するプリント基板の大まかな部品配置が定まり、より現物に近いイメージが出来上がることになる。

PCBエディタでネットリストを読み込み、配置を進める。図11-5にネットリストを読み込んだところの図を示す。すべてのコンポーネントが重なって配置されている。部品を一つ動かしてみるために、部品の上で右クリックすると、部品が選べる。移動コマンドはMなので、とりあえずKBを叩いて移動してみると良い。移動すると、図3-6のようになり部品が一つ移動する。

先程述べたように、ネットリストは部品ごとの接続を示したものであるから、それぞれの部品のピンがどこかにつながっている。このつながりは、図3-6中の直線で示されている。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-5.png}
\caption{ネットリストを読み込んだところ}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-6.png}
\caption{コンポーネントをひとつ動かしたところ}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-7.jpg}
\caption{「すべてのフットプリントを展開」を実施}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-8.png}
\caption{フットプリントモードの切り替え}
\end{figure}
//}

さて、以下全ての部品について、配置をすれば良いのだが、部品点数が多い場合など、重なっている部品を拾い上げるだけでも大変な手間であるから、そこを簡単にするツールがある。それが「すべてのフットプリントを展開」のコマンドである。自動展開後のレイアウトを図3-7に示す。すべての部品が重なりなく配置されている事がわかる。ただし、どういう順番かはいまいちわからないものの、単純に部品順に並べただけという状態であるから、このまま配線等行う事はできない。

なお、「すべてのフットプリントを展開」コマンドにより重ならないように移動する。と、本には書いてあるが、すべてのフットプリントを展開コマンドがどこにあるかさがすのにだいぶ時間がかかった。この点はKiCADはとっても不親切・・・普通とりあえず使う機能なのだから、ネットリスト読み込みの画面に置いといてくれてもいいくらいだと思う。そもそも、全部の部品が中央に重なるのも不便だと思うが・・・重ねて表示／展開して表示を選べるようにしておけばよいのに・・・

フットプリントモードに切り替えたのち、ワークスペース上で右クリックした上で、上から5行目、「全てのフットプリントを展開」をクリックすれば、適当に並べてくれる。トラ技などの本、ネット上の大多数の記事には、そのコマンドがどこにあるのかが書いておらず、ハマったので記載した。

自動展開されたら、きれいなレイアウトになるように並べていく。きれいといってもこの点は慣れが必要であろうから、とりあえずやってみることをオススメする。ピン数の多いICを使う場合や、配線に気を使わなければならない高周波、あるいはアナログ配線に関する実装技術は別途情報を当たって頂きたい。

基本的には、大きい、あるいは重要なパーツから並べていくとか、信号や電流の流れに沿って配置していくのが良いのではないだろうか。とりあえず並べてみるが勝ち。

並べてみたら、それが入る大きさに外形を描く。外形は、Edge.Cuts層に描く。FusionPCB などでは50mmごとに価格が変わるので、50mm×50mmに入らなそうなら50mm×100mに するなどが可能となる。いずれにせよ、とりあえずの配置をしてみないと外形が決まらない。天下り的ではあるが、外形を決めるのに必要以上に凝った配置にするのは作り慣れてから にしてよいであろう。
 
===	配線する
部品を並べたら、導体レイヤーを選択し、配線ツールで配線を引いていく。今回作るのは片面基板なので、B.Cu層（裏面導体層）を選択する。簡単な回路／基板であり、フットプリントは確保済みなので順番に引いていけばよい。KiCADは標準でリアルタイムDRCが効いているので、配線ができないところには線が引けない。DRCとは、デザインルールチェック（Design Rule Check）の略で、パターン幅／空間が規定値以下になるとパターン形成に困難が生じる場合等をチェックするものである。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-9.png}
\caption{とりあえずの配置と配線完了状態}
\end{figure}
//}

とりあえずの配置・配線が完了した状態が図11-9 である。ネットリストの白い線が緑の配線パターンになっていることがわかる。（白、緑等は環境によって異なる可能性はあるが、初期状態を白、配線済を緑としている）配線忘れ等がないかを簡単に確認するには、DRCを行ってみれば良い。未配線がある状態では、未配線タブにエラーが出る。（図11.10）

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.8\linewidth]{images/chap11/image11-10.png}
\caption{未配線のある状態でのDRC結果}
\end{figure}
//}


次に、配線のブラッシュアップ等を行う。高周波信号や大電流配線の調整、あるいはノイズ対策としてのベタGNDの扱い等である。個別の情報はネット上や本を当たっていただくとして、今回のスイッチ基板は、入力段とガルバノへのパターンは1A程度の電流が流れることがわかっているので、この部分のみ配線を太くしておく。一般的に35μm厚の銅箔パターンはざっくり幅1mmあたり1Aの耐電流であるとされている。また、電圧は比較的低いので、ラインを太くするが、スペースはそれほど大きくしなくても良いと考え、最終的に配線太さを2mm、クリアランスは当初のまま0.2mmとした。配線後のレイアウトが図11.11である。あとは、シルク層にテキストを入れたり、入出力の説明を入れたりする。
 
//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.9\linewidth]{images/chap11/image11-11.png}
\caption{とりあえずの配置と配線完了状態}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.2\linewidth]{images/chap11/image11-12.png}
\caption{レイヤー選択画面}
\end{figure}
//}

注意事項は、マウントホールはEdge.Cuts層に入れる必要がある。（これはトラ技にちゃんと書いてある）。当初それを見落としており、部品層に配置したところ、後述のドリルリストが2ファイルになってしまう現象が発生した。マウントホールを非メッキから、メッキスルーホールとすることで基板発注可能なデータを生成する事ができたがおそらくイレギュラーな方法であると考えられる。図11-12のように、レイヤ選択画面からレイヤをちゃんと選んで作業を進めないと、思わぬ手戻りが生じる事がある。

また、片面基板の表面シルクはF.SilkS層であるから、シルクを入れる場合はきちんと選んでから作業を行うようにする。編集すべき層を間違えると、配置変更ができない！とか、いろいろ面倒が起こる。今回はやっていないが、銅箔で文字を入れる場合は、Cu層に文字を入れるのだろうか・・・きっとそうだよね・・・

基板の名前や製作者の名前を入れたり、いろいろやることはある。マウントホールの REF**という表記を消し忘れていた／消し方がわからなかったら、完成基板にこれが残ってしまった。

===	製造発注
以上で製造発注可能なデータが出力できるところまで来たことになる。プロットアイコンをクリックし、製造に必要なファイルを出力する。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-13.png}
\caption{プロットコマンド}
\end{figure}
//}


今回のデータでは、使うのは片面基板であるから、

導体層 B.Cu

シルク F.Silks

外形図 Edge.Cuts

//noindent
と、ドリルファイルを出力する。出力したファイルは

電源基板 2-B.Cu.gbr

電源基板 2-Edge.Cuts.gbr

//noindent
など、基板名-層名.gbr となっている。FusionPCB に依頼する場合は、ファイル命名規則の説明@<fn>{rename}にしたがって、拡張子を変える必要がある（自動で出力する方法があるかもしれないが、リネームでも問題なかった。）。とりあえず電源基板2というファイル名で製作を進めていたが、日本語ファイル名はダメかも知れないので、適当な名前にリネームしておいたほうがよいと考える。日本語ファイル名が問題ないのかは確認していないので分からないが・・・

//footnote[rename][http://support.seeedstudio.com/knowledgebase/articles/493833-what-is-gerber-file]

さて、必要な（データのある）ファイルをまとめて、Zip圧縮してFusionPCBのサイトにアップロードするとともに、必要な事項を入力すると発注に進むことができる。発注には FusionPCBとPayPalのID登録をしておく必要がある。他の決済手段もあるかもしれないが、クレカ直接登録は怖いため、PayPalを経由することにした（個人の印象です）。

今回の基板は50mm×100mm に収めたので、PCB Dimension は5cm×10cmMax を選ぶ。片面基板、板厚 1.6mm、数量 10、Hasl（有鉛半田レベラ）で特に問題なかろう。見積額は＄18.9 であり、別途送料が＄16 ほどかかる（FedEx の場合）

お安いですねぇ・・・と思いながら、柏手を打って発注する。発注後の状況は以下の通り。

発注：11月9日

製造：11月10日に In Process に変化

発送連絡：11 月 15 日

荷物ピックアップ：11 月 23 日

日本入国：11 月 24 日、配達完了。

//noindent
ということで、製造が 4 日程度、受取まで 2 週間程度であった。

発送連絡からピックアップまでの謎の8日間はなんだったんだ、とあとから思うが・・・発送連絡があってから荷物がピックアップされるまでは、「出荷ラベルが作成されました。貨物が輸送が始まると貨物の状況が更新されます。」とだけあって何がなんだかさっぱりわからないという状態にあった。海外通販で似たようなメッセージが出て、荷物が届いても変化がなかった人がいる@<fn>{status}ようだが、こちらは、23日以降一気にステータスが進んだようで、ちゃんと再配達の履歴なども表示されていた。

//footnote[status][小泉哲郎ブログ +K department	続！Your Reebok ユアリーボック http://ameblo.jp/hair-design/entry-12008896749.html	（2016.11.16 閲覧）]

届いた現物写真はこのとおり。最初に受け取った感想は、「すごーい、本物の基板、市販の基板みたいじゃないか」であり、などとひとしきり感動した。4～5日で製造完了なんて素敵な話ですね・・・薄めの片面プチプチに包まれて、黄色い国際郵便封筒に入っていた。ピックアップ用と思われるラベルには11月13日と11月14日の日付があったので、実質2～3日で製造は完了したようである。表裏面の写真も合わせて示すが、シルクの潰れなどもなく、良好な仕上がりだと思う。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-14.jpg}
\caption{基板の納品時のパッケージ(中袋)}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-15.jpg}
\caption{製作した基板の表面}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-16.jpg}
\caption{製作した基板の裏面}
\end{figure}
//}

===	部品実装
それでは実装を、となったところで、がっかりの事実が発覚。スイッチを入れるべき穴が小さくて入らない。がっかり。フットプリントエディタから穴径を確認すると、0.762mm(0.03インチ)となっている。一見したところでは、スイッチの足は0.5mmよりは太く、 1.0mmよりはだいぶ細いので、おそらく0.76mmで、穴径も同じとなればそりゃ入りませんな・・・orzというわけで、作ってみてわかるミス。

しかたがないので、広げることにするが・・・次の問題は、

 1. 1mm なんて細いドリル手持ちにない
 2. ガラエポ削るのは、超硬ドリル必要？
 3. 穴数多いからめんどい・・・の 3 点である。

結果としては、普通の1㎜のドリルで問題なく穴広げができたことを付記しておく。ただし、削ったあとのドリルの切れ味のほうは保証の限りではない。削る分が少ないので、スルスル穴あけ可能であった。

また、今回は片面基板だったから問題なく穴を広げることができたが、両面基板だった場合、貫通ビアの裏表をつなぐ部分が損傷・断線していた可能性がある。穴径の選択にも留意しようという教訓を得た。リードを入れて裏表ではんだ付けするから問題なく導通する可能性も高いが予期せぬ接触不良の原因にもなりかねない。

さて、穴を広げた後は部品実装とハンダ付けである。スイッチの足が実際より細い想定でランドの大きさが自動指定されていたため、削ったら更に小さくなってしまい、はんだ付けが難しくなった。難しくなった、という程度であり、不可能であったわけではないが、ランドはある程度大きめのほうがハンダが乗りやすいのではんだ付けが簡単になる。実装後の写真を図11.17に示す。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-17.jpg}
\caption{部品実装したスイッチ基板}
\end{figure}
//}

実装にあたって調整したのは、以下の2点である。

 * 普通の赤色 LED@<fn>{redled}とした。

手元にあった超高輝度緑@<fn>{greenlde}を選んだところ、眩しすぎたため、赤の普通の LED に変更した。直視できないし、基板が見えなくなるほどであった。

 * 電流制限抵抗を 5kΩ とした。

電源が 12V であり、5kΩ でも十分な明るさがあったので、抵抗は 5kΩ とした。

//footnote[redled][５ｍｍ赤色ＬＥＤ ＥＳＬ－Ｒ５Ａ３３ＡＲＣＮ１１４ （５０個入）380 円http://akizukidenshi.com/catalog/g/gI-08359/]
//footnote[greenlde][超高輝度３ｍｍ緑色ＬＥＤ ＯＳＧ５８Ａ３１３１Ａ（１０個入） 200 円]
 
== DC-DC コンバーターの実装
スイッチ基板はあくまでスイッチと分岐とインジケーターLEDを提供するだけなので、別途DC-DCコンバーターを実装する必要がある。実装にあたっては、5つのDC-DCを使用し、入出力用のポートをつけたり、それらの配線をする必要がある。まず、適当なユニバーサル基板に5個のDC-DCを取り付け、ターミナルブロックを取り付ける。この段階で電圧を調整・確認しておく。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-18.jpg}
\caption{DC-DC群}
\end{figure}
//}

次にスイッチ基板と、DC-DC基板と、電源ユニットの電流計・電圧計とを接続し、パネルに取り付ける。パネルは過去に製作した電源ユニットを流用する。解体前の電源ユニットの写真を図11-19に示す。入力電圧、入力電流、あとは、汎用の電圧計である。今回、パネルメーターを残して、一旦全部撤去し、表側にスイッチ基板を取り付け、裏側にDC-DC基板を取り付ける。合わせて、結線ルートを検討する必要がある。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-19.jpg}
\caption{改造前の電源ユニットパネル}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap11/image11-20.jpg}
\caption{実装後の電源ユニットパネル}
\end{figure}
//}

さて、基板の実装を行うにあたって、電流と電圧のモニタ端子がないことに気がついた。基板に入る前に電流計・電圧計を接続すれば電源電圧と電流を測定できるが、メインスイッチのON/OFFによって制御できない。すなわち、バッテリーを接続してあれば測定し続けることになる。OFFにしたら0を指示するほうがよいのか、オフでもバッテリーが繋いであれば電圧を表示するほうが良いのか微妙なところである。今回は、若干違和感はあるものの、実装が容易なので、基板に入る前に電流計・電圧計を接続する形とする。

