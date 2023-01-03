= レーザーでお絵かきする

レーザーの応用には多数あるが、この本はレーザーを使った図形描写を行う。コンサートなどでレーザーを用いた演出がなされることがあるが、これの応用として、適切に制御することで任意の図形を描画することができる。ここでは、ガルバノスキャナを購入し、基礎特性を評価し、今後の描画等につなげる。

==	ガルバノスキャナとは
ガルバノスキャナとは、回転軸にミラーを取り付け、回転軸を走査することでレーザ光を走査する光学素子である。図 3.1 に模式図を示す。入力信号の振幅に応じて角度が変化するモータを用いれば、ある一方向に任意の点を指すように光路を変化させることができる。また、互いに直交するように 2 軸でミラーを設置することで、二次元の図形を描画することができる。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap3/image1.png}
\caption{ガルバノスキャナの概念図(1軸)}
\end{figure}
//}

ガルバノスキャナの動作は、入力信号と描画のための回転角の直線性、位置再現性と、小角動作時のレスポンスが重要である。入力信号はオシロスコープにおける XY モードのように、X軸制御信号とY軸制御信号をそれぞれの軸に入力することで、対応するミラーを駆動する。動作にあたっては、駆動するミラーのモーメントが重要となり、したがって駆動トルクとモーメントの関係が動作周波数を与える。動作が可能となる周波数まで入力信号周波数を落とす必要がある。

===	ガルバノスキャナの購入
購入先は、いつもどおりeBayである。検索ワードは「Galvo Scanner」で検索すれば多数見つかる。15kpps∼20kpps 程度で100ドル程度、送料含めておよそ150ドル程度である。ドライバ基板とモーター、ミラーと接続ケーブル、電源を含む価格である。今回購入したのは最も安価なもので、スペック上は12kpps、本体価格$69.95、送料$39.95であった。合計$109.90で購入当時のレートで約8400円である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=1\linewidth]{images/chap3/image2.jpg}
\caption{ガルバノスキャナキット}
\end{figure}
//}

購入より2週間程度で到着したが、箱はティッシュ箱程度の大きさであった。中身の写真を図 3.2 に示す。中には裸の基板、ケーブル、電源と、小箱に入ったスキャナ/ミラーが入っていた。驚くべきはミラーがダンボールの小箱に裸で入っていたことである。ミラーに傷こそないが、ホコリが付いていた。

実動作の前にはクリーニングすればよいので、大きな問題ではないが、やはり中華クオリティである。eBayでいろんな物を買うようになって、中華クオリティを痛感することは多い。作りが雑だったり、梱包がダメダメだったりすることも多いが、安価すぎるというメリットには勝てない。DIYなので試行錯誤が入るというのもそれはそれで良いとする。いっそ中華クオリティが高すぎて清々しくなるほどである。さて添付の電源はAC100V入力で直流±15V出力である。出力電流は、+15Vが1.0A、-15Vが0.6Aである。電源ケーブルは、二股になっており、制御基板の X 軸用部分、Y 軸用部分に入力する。

使用するガルバノスキャナのスペックを記載する。取り付けてあるミラーのサイズは、7mm×11mm×0.6mmである。商品説明からの引用になるが、回転角20°で12kpps、8°で20kppsとのことである。角度と周波数の関係の詳細は表3.1のとおりである。また、ミラーは広帯域ミラーとあるが要するにただのアルミミラーである。コーティングの有無は不明であるが、汚れを軽くアルコールでふき取るくらいは問題なかった。また根本が接着剤で固められており、接着剤の素性が不明なため取り外しは困難と考えている。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap3/image3.jpg}
\caption{ガルバノスキャナ制御基板のレイアウト}
\end{figure}
//}

出品者ページより転載した基板レイアウトを図3.3に示す。基板中央部分に電源コネクタ、左右に出力コネクタがあり、基板下部に入力信号用コネクタがある。入力信号コネクタに印加した電圧に比例した傾きとなるようにモーターが駆動される。添付の信号ケーブルは両端がコネクタとなっていたが、接続機器はコネクタではないので、半分にカットして切り放しとしてファンクションジェネレータに接続して使用する。調整用ポテンショメーターが4個×2chついており、それぞれの意味は、表3.2	のとおりである。

また他に HFD High frequency damping (correct undershoot) PS Position scale (increases or decrease input sensitivity of the computer, DO NOT change it) という記述があったが、上記レイアウトには記載がない。LINの隣（ボード端）にポテンショメーターがある。これがどちらかに相当するかもしれないが、詳細はわからない。まずは、工場出荷調整状態のまま使用する。制御基板とガルバノスキャナ本体に同一のシリアル番号と思われるシールが貼ってあるため、基本的な調整は完了しているものと考えている。今後、出力信号の関係で必要となった場合には調整を行う。入力電圧は、出品ページに±5V という表記と、-5～+10Vという表記があるが、安全側として、±5Vを採用する。これらから、ファンクションジェネレータのスペックが決定した。

//table[spec][ガルバノスキャナのスペック]{ 
Defrection Angle	Operating Voltage	Spped@ Mirror size
-----------------------------------------
20°optical deflection	±15V	12Kpps@7*11*0.6
15°optical deflection	±15V	17Kpps@7*11*0.6
8°optical deflection	±15V	20Kpps@7*11*0.6
//}



//table[silk][制御基板上の調整用ポテンショメーターと意味]{
シルク	内容	説明、調整可否等
-------------------------------------------
IS	input Signal	工場調整のみ
SG	Servo Gain	内部 PID へのフィードバックゲイン
LFD	Low Frequency Damping	オーバーシュートダンピング補正
LIN	Zero Offset	ドライバーのオフセット調整。工場調整のみ
//}
なお、特にこのポテンショメーターの調整は行わなかった。

== ガルバノスキャナを動かす

あらためて、今回の実験対象のガルバノスキャナの写真を示す。電源。制御基板、駆動部分およびそれらを接続するケーブルからなる。中央部分の3芯のフラットケーブルが入力ケーブルであり、カードの端の方から、Y軸、GND、X軸である。とりあえずのトライとして、ミノムシでAD/DAボードの出力を入力する。線が細いため、固定方法は考える必要がある。組み立てた状態が図 3.4 である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap3/image4.jpg}
\caption{組み立てたガルバノキット}
\end{figure}
//}

===	とりあえず動かしてみる

さて、信号を入力するとミラーが振動する。振幅と周波数によっては、目視あるいは振動が音として確認できる場合がある、一方で数10Hz以上の場合は肉眼では見えないし、写真に撮っても写らない。また振幅が小さく発生する音も微弱なため、正弦波的な音は聞こえない。これが特定の音源（例えばiPodなどから出る音楽）であれば、音がそのまま聞こえる場合もある。本節での動作確認は、レーザーを入射して、リサージュが描けるか、ということを試す。

まずは机上に置いて、信号を入力する。10Hz5Vppくらいならば、震えているのが目視で確認できた。当然と言えば当然だが、30Hzあたりから見えなくなり、200Hz程度では目視上は何もわからない。そこで、片側のミラーにのみ当たるようにレーザ光を照射すると、壁に線が表示される。入力周波数をX軸入力に100Hz、Y軸入力に200Hzの正弦波を入力した結果を示す。なお撮影の都合上部屋を暗くしたため、背景が暗くなっている。位相によって形状は変化するが、位相差0付近では8の字を描く。ここから位相を変化させていくと、90° 付近では放物線状となる。

リサージュ図形のもう一例として、150Hzと200Hzの例も示した。X 軸の節が3個、y軸の節が4個であることがわかる。節の数は周波数比になるというリサージュ図形の基本が現れており、オシロスコープでも確認できる。なお、リサージュ曲線に歪みがあるように見えるが、これはガルバノと壁が正対しておらず、左右で投影倍率に差があるためである。正しい光学系を設計し、アライメントを取れば歪みのない図形が描画できるはずである。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap3/image5.jpg}
\caption{ガルバノスキャナの動作例(100Hzと200Hz入力)}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap3/image6.jpg}
\caption{ガルバノスキャナの動作例(150Hzと200Hz入力)}
\end{figure}
//}

== ガルバノスキャナの基礎特性

さて、ガルバノの入出力特性を調べないことにはDAボードを使うにせよ、オーディオ信号を使うにせよ、描画プログラムの作成の方針が立たない。そのため振幅及び周波数に関する特性を調査する。あわせてグリーンレーザモジュールの特性についても調査したので、ここであわせて記載する。実験の方法としては以下のとおりとする。

 1. スクリーンとの距離：ミラーの中心点とスクリーンの距離を 1m とする。
 2. 様々な振幅、周波数の信号を入力し、実際に描画される画像のサイズを計測する。
 
なお、位相については、測定することが難しいことと、XYでほぼ同一であるはずという前提のもと今回は考慮しない。出力特性によっては別途考慮する必要もあるが、それは結果が得られてからとする。また角度の測定に当たっては、壁面の描画像をメジャーにて測定しする形とした。原点は0V入力時点を原点とし、ゆっくりした正弦波(ここでは10Hz)を入力して、等しい幅になるようにアライメントを行った。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap3/image7.jpg}
\caption{ガルバノスキャナの振幅特性}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap3/image8.jpg}
\caption{ガルバノスキャナの周波数特性}
\end{figure}
//}

結果を図 3.7 に示す。まずは振幅と入力電圧に対する特性である。入力振幅はVoltage(Peak to Peak)で示している。また、出力振幅は、ガルバノ中心からスクリーンの距離1mにおける描画像の長さを示す。なお信号は片側の軸のみである。この測定結果より描画においては 0V~5Vまでほぼリニアである事がわかる。入力振幅の定格は±5Vとのことだが、一方で商品説明の中に-5V∼+10Vとの記載もある。マニュアルなどが添付されていないため、どちらが本当かは不明である。しかしファンクションジェネレータのオフセット電圧により、±10Vに対して585mmの振幅までは回転させることができることがわかった。角度にしておよそ±16°である。商品説明には±30°とあるが、図形の大きさも考えると十分であろう。なお、入力振幅を±5Vとしたとき、回転角は±8.4°となる。

次に、周波数特性である。あわせて、図3.8に示す。入力振幅を5Vppとし、5Hz~1.5kHzの信号を入力し、出力振幅を計測した。概ね 800kHz付近までフラットであり、その後急激に低下する。フィルタ特性などでよく見る図である。当然ながら、大振幅や高周波の信号を利用する必要がある場合には注意が必要であるが、高周波信号であっても振幅が小さければ追従すると考えられるため、直ちに問題であるとはいえない。

なおこの計測中に少々大きな音を出して光軸がズレるという現象が発生した。1.6kHzを入力している時であった。この時長時間の動作によって本体がかなり高温になっていた。発熱が影響していたのかは不明であるが、光軸調整が必要となった。この現象が発生した後もミラーは動いているので、全く動作しなくなったというわけではないことは確認している。後日、ネジをゆるめて、全体を回転させることで調整を行った。また、レーザモジュールと合わせた光学系のマウントを製作しなくてはならない。ずっと課題として残っていることであるから、そろそろ着手したいと考えている。さて、これによって、800Hz程度までは振幅フルでも問題なく動作することがわかった。