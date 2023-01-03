= コミケにおけるデモ/展示に関するもろもろ

本章では、コミケで展示するにあたって、考慮、設計する必要のある各種項目について検討する。具体的には、

 1. 電源設計
 2. 定盤・ロッド・その他固定方法
 3. レーザモジュール選定
 4. レーザーモジュールの熱対策

の 4 項目について行う。

==	電源の設計
本節では、コミケで展示するにあたって最も重要な電源に関する検討を行った。Maker Faireとは異なり、コミケでは電源が用意されない。したがって、各自持ち込みの電源を利用し展示を行う必要がある。容量と電圧からバッテリーの選定と、最終的に選んだ鉛シール電池の使い方、コミケ用「電源装置」の製作について述べる。

===	バッテリー容量の選定
まずは電源について設計を行う。当サークルで必要な電源は、以下のとおり。

 * ノートパソコンの電源	19V	1.58A（AC アダプタの定格）
 * ガルバノスキャナの電源 +15V	1A	（ガルバノのスイッチング電源装置の出力）	-15V	0.6A
 * レーザ電源	5V	0.2A

合計をざっくり計算すると、単純加算で 55W の電力が必要となる。当然のことだが、これをフルに使うということはありえないので、実消費電力をノート PC、ガルバノの消費電力を確認しておく。クランプメーターを買おうかとも考えたが、安いのだと直流電流が測定できないとか、そもそも容量がデカすぎて精度が出ないとか、買いに行く服がないといった理由から、Amazon さんにお願いした。

で、単純に消費電力を見るだけなら、クランプメーターとか使うよりワットチェッカーを買ったほうが早いということになり、サンワサプライのワットチェッカーを購入。SANWA SUPPLY ワットモニター TAP-TST8 2020 円也。W で表示してくれるので大変便利。

デモに使用しているノート PC は Dell  Mini9 であり、AtomN270-1.6GHz を使っているため消費電力が小さい。計測の結果、ノートパソコンは消費電力 10W そこそこであることが判明した。なお、Mini9 はコミケデモ専用になっているため、半年に 1 回しか充電・使用しない。そのため、過放電により毎回バッテリーが死亡するというもったいない状況になっている。今回も死んでたよ！ orzでも今回は電源ちゃんと作ったのでバッテリー買わないよ。1 本くらいは買っといたほうがいいかなあ・・・でも値段はそれなりにするしもったいないかなあ・・・などと考えており、直前まで検討する。

ところで、ダメ元で数日電源繋ぎっぱなしにしてほっといたら、2 本のうち 1 本は若干復活したよ。瞬断しない程度なので、何分持つかはわからないけど。というわけで、今年の冬はこのバッテリーで行くことにする。本当に死んでたら、

こういうことをすると妊娠したりするのかな・・・。 Apple の Li-ion バッテリーを 2 年ほどほっといたら妊娠してた事があったなあ・・・もう 5-6 年前の話だけど。充電してない状態でそのまま放置して、久しぶりに見てみたらパッケージが破損して膨らんでるという状況であった。発火しなくてよかった・・・と胸をなでおろしたことを思い出した。

次に、ガルバノの消費電力についても、AC 電源の 1/3 として、消費電力 8W と仮定する。さらに   レーザポインターの消費電力 2W を加えて、トータルの消費電力を 20W とする。ガルバノの消費電力は、計測する時間がなかったというだけである。配線して、電源入れて、というだけなのだが、その時間が取れなかったという痛恨。時間配分ってホント重要だなあ・・

さて、電源電圧を 12V 定格とすると、20W を取り出すためには変換ロスを除いても 1.6A 必要となる。コミケの開催時間は 10 時-16 時であり、準備を考えて 9 時に電源投入として、7 時間持たせる必要がある。したがって、1.6A×7 時間=10Ah のバッテリー容量が必要ということになる。

=== バッテリーの選定@<fn>{battery}

//footnote[battery][このような検討をしてみたものの、2023年現在ではUSB出力のあるモバイルバッテリー一択であろうか…安全性と使い勝手と容量はこの当時より各段に向上しているので・・・]

次に、バッテリーと容量の選定を行う。コミケットアピールを確認すると、携帯電話、ノートパソコン等の小型機器用を除くバッテリー（自動車用等の大型バッテリーは転倒時に液漏れした場合、危険なため）持ち込み禁止とある。

これまでにみた例としては、単1型エネループを直列接続して、ペットボトルのシュリンクで覆ったバッテリーでデモをしていた例を見たことがある。容量は大きくなるが、見た目が明らかに不審物である。軽く調べてみたところ、容量Min,5700mAh とのことである。思ったよりでかい・・・そして、単一エネループってお高いのね。Amazon 価格で、1 本 1000 円程度する。12V とするためには、 8本必要であり、8 千円程度になることになる。通常のエネループ充電器は単 3 単 4 用が多いので、単 1 型対応のものを買う必要がある。

それから、ノートパソコンのバッテリーの端子に直接導線を突っ込んで電源を取る形でデモをしていた人もいた。外れたりしないのかな・・・と心配になる感じである。ノートパソコンのバッテリーはたとえば定格電圧 11V で、4Ah 程度が典型的であるようだ。

さらに、リポバッテリーも候補には上がる。リチウムポリマーバッテリーの通称であり、電動ガンやロボコンなど、モーター駆動系にも利用されている。1 セル 3.7V であり、7.4V のものが多いようだ。Li-ion 電池と同様軽量で、数が出ているため比較的安価である。例えば 7.4V  4000mAh のものが 3000 円程度である。本記事を書くために少し調べてみたところ、瞬時電流が取れるという特徴があるようである。一方で、リチウム系バッテリーは燃えるというイメージがある。リコールも時々あるしね。

次の候補が、鉛シール電池である。鉛シール電池は倒しても基本的には液漏れすることはなく、ガスが発生することもない。多少重量はあるが安価で大容量である。充電も安定化電源がひとつあれば比較的簡単にできるという特徴もある。鉛シール電池は、1 セル 2V で、市販品は 6V または 12V 定格が多い。容量も重量に比例するが、12V5Ah で 1.9kg 程度である。秋月で売っている Long というメーカーのものである。Li-ion バッテリーが 350g 程度であることと比較すると、5∼6 倍の重量がある。一方で、持ち運びを前提としないなど、重量についてはある程度許容するならば大変有用な電池となる。そこで、以下小型の鉛シール電池の利用を前提として容量設計などを行う。
 
まず、鉛シール電池のスペックの読み方である。鉛電池は 1 セルあたりの公称電圧が 2V であり、 6 セルで 12V となっている。容量は、車用などは 5 時間率で表示され、計測器や UPS など向けの鉛シール電池では、20 時間率で表示される事が多い。20 時間率は、定格の 1/20 の電流で動作させた時に 20 時間使えますよ、という意味であるから、例えば 5Ah のバッテリーで、5/20=0.25A を流した場合に 20 時間で終端電圧に到達する。

今回の消費電力は 20W であるので、1.6A 流れると考えると、単純計算でも 3 時間くらいしか持たないことになる。今まではガルバノだけだったので、まるまる一日は余裕であったのだが、ノートパソコンの 10W が加わることで負荷が増え、バッテリー動作可能時間が急激に短くなる可能性がある。負荷 2 倍となれば、寿命は半分以下になる。とりあえず、今回は現地テストも兼ねて、5Ah のバッテリーで参戦することにする。時々電圧を計測し、データ取りをする予定である。なおバッテリーは 2 台持っていくので、本当に力尽きたら交換することにする。C84 の前日の夜に DC-DC を壊してしまったため、近所のホームセンターでもう一台買い足したものであり、12V バッテリー 2 台を直列接続し、+12V と-12V でデモを行った時のものである。

===	鉛シールバッテリーの使い方
今回、電源として鉛シール電池を使用する。重量はあるが、充電が容易で安価という特徴がある。また、リチウムイオン電池のように妊娠することもなく、ましてやリチウムポリマー電池のように発火の危険も極めて低い。通常の車などのバッテリーにも使用されているが、密閉かつメンテナンスフリーにしたものを鉛シール電池と呼ぶ。

鉛二次電池は、二酸化鉛の正極と、鉛（海綿状の金属鉛）を用いた充電池であり、単セルで公称 2Vの電圧がある。一般には 6 セルを直列接続した定格12Vのバッテリーが広く市販されている。バイク用などは3セル6Vであり、トラックは 12 セル 24V である。放電時の反応式は、

負極 Pb+SO@<sub>{4}@<sup>{2−}→PbSO@<sub>{4} + 2e−

正極 PbO@<sub>{2} + 4H@<sup>{+} + SO@<sub>{2}	+ 2e-	→ PbSO@<sub>{4} + 2H@<sub>{2}O


であり、ともに硫酸イオンを消費して硫酸鉛 PbSO@<sub>{4}が生成する反応である。鉛蓄電池の放電特性で有利な点は、内部抵抗が小さく大電流放電時の特性が良いこと、逆に小電流での長時間放電についても特性が良い。ただし、深い放電を行うと急激に特性が劣化するとされている。反応が進行すると、サルフェーションと呼ばれる、硫酸鉛が結晶化する現象が発生する。結晶化した硫酸鉛は溶解しにくく、電極の表面を覆う。電池の反応は電極-電解液界面で進行するため、充電容量が著しく低下する。特に深い放電を行ったあと長時間放置するなどした場合、サイクル数が少なくとも急激に劣化する場合がある。鉛蓄電池はリチウムイオン電池など他の二次電池と異なり、満充電状態で保管することが望ましい。バッテリーの寿命を測る方法の一つとして、電解液の比重を測定する場合があるが、硫酸鉛の生成に伴って、硫酸イオンが消費され、水が生成するため電解液の比重が低下するためである。そのため、車用などのバッテリーには比重計がついている場合がある。

鉛シールバッテリーは、定電圧充電が可能である。これは他の二次電池と異なり、安定化電源があれば簡単に充電できることを意味する。もちろん専用の充電器を使用しても良いが、鉛シールバッテリーの充電時の電圧電流特性は、ニッケル水素電池やリチウ充ムイオン電池とは異なるため、対応する装置を使用する必要があることは言うまでもない。本節では、安定化電源を使用した鉛シール電池の充電方法を述べる。

設定電圧は、定格の 1.14 倍とする。12V ならば、13.68V とする。 設定電流は、電池容量の 1/10とする。通常鉛シール電池の最大充電電流は 0.3CA なので、充電容量の 3/10 までかけることができるが、電流を 4 倍としても充電完了までの時間は半分程度にとどまる。なぜなら鉛シール電池の充電後期は、定電圧状態で小電流を用いて充電するからである。図8.1に充電特性についての電流電圧特性図@<fn>{property}を示す。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image1.jpg}
\caption{鉛シール電池の充電地の電流電圧特性}
\end{figure}
//}

使用する安定化電源は、電流、電圧ともに制限をかけられるタイプを使用する。充電初期には大電流が流れるため、電流制限が必要である。電圧のみ制御するような AC アダプタなどは使用してはならない。以下に充電方法を述べる。

 1. まず電圧を設定電圧（12V 定格ならば 13.68V）に設定する。この時、出力電流はほぼ 0 に絞っておく。ただし、完全に 0 にした場合、出力電圧が不安定になる装置もあるので、小電流（0.1A 程度）が出力されている状態にしておく。
 2. 電圧印加状態にし、鉛シールバッテリーの端子を接続する。 電池のプラス端子をプラスのターミナルに、マイナス端子を電源装置のマイナスに接続する。このとき、端子電圧が下がっていると、それにあわせて出力電圧も下がるが、そういうものである。
 3. 電流つまみで設定電流値まで上げる。たとえば 8Ah のバッテリーに対しては、0.8A に設定する。時間が惜しい場合など、0.3 倍（8Ah なら 2.4A）までは印加してもよい。ただし、最大値は超えないようにする。
 4. そのまま数時間放置する。充電初期は、設定電流いっぱいの電流が流れるとともに、徐々に端子電圧が上昇する。端子電圧が 13.68V に達したところで、定電圧動作モードに切り替わる。その後充電が進むに従い、電流が小さくなってゆく。電源装置に制限がなければ、常に定電圧電源を接続して満充電状態を保つことが望ましい。

そのため、UPS など、実質的に放電されることが殆ど無くかつ定常的に充電が可能な装置には極めて使いやすい。もちろん、バッテリー自体が安価、充電回路も簡易などの特徴もある事は言うまでもない。また、電源から切り離して保管する場合、基本的に鉛シール電池は自己放電が小さいとされている。ただし、数ヶ月に一回は再充電することが望ましい。

//footnote[property][ Panasonic	制御弁式鉛シール電池の特性 http://industrial.panasonic.com/www-data/pdf/ACD4000/ACD4000PJ2.pdf]
 
===	ノートパソコン用 DC-DC コンバーターの選定
今回からノートパソコンについても、鉛バッテリーから取ることにしたので、DC-DC コンバータを作る必要がある。世の中的には Linear  Technology の LT1170 を用いた昇圧 DC-DC コンバータの製作例が公開されている。スペックとしては、100kHz  5A で、3~60V の範囲で出力電圧を変化させることが可能となる。

そこで Linear   Technology の LT1170 を入手したところまではよいのだが、さてサンプル回路でも調べるか、とおもって検索したところ、同じような完成品を見つけてしまった。使用しているICなどの情報は不明だが、スイッチング周波数が38kHzでLT1170 とは異なるようだが、入力8～32V、出力9～45V、最大15A（ピーク）で2300円であった。さて、どうしたものかな。アルミケース入りでこの価格は魅力だなぁ・・・と考えているうちに、更に安価なものを発見した。

ケースは付かないが、より安価なステップアップDC-DCモジュールを発見した。外観を図8.2	に示す。こちらは Amazon で 2 個で 1490 円である。使用しているチップは、XL6009 である。可変範囲は 5～35V とのこと。

Amazon で探したあと、Aliexpress でも引っかかり、2 個 3 ドル程度で売っていることがわかった。1 個 200 円弱である。トロイダルコイル 1 個で 100 円くらいするから買って作る手間を考えると断然安くなってしまった。せめて作り物をするならともかく、こういうことばっかりしていると脳みそバカになるよね・・・ほんとに。と思いつつも、購入した。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image2.jpg}
\caption{ノートパソコン用DC-DCコンバーター XL6009使用}
\end{figure}
//}

配線をして、電圧計で出力電圧を確認しながら、基板上の半固定抵抗を回してノートパソコンの電圧に合致する電圧に設定する。

この調整は当然ながら、事前に行っておくことが必要である。

===	ガルバノ電源用 DC-DC コンバーターの選定
次に必要となるのがガルバノスキャナ用の ±15V である。入力電圧は 12V～13V であり、出力電圧と必要な電流は +15V が 1A、-15V が 0.6A である。

そこで、ガルバノスキャナ電源として、 Cosel	MGW301215 を選択した。±15V、各 1A の出力が得られる。入力電圧は 9～18V、効率は Typ.90% である。入出力は絶縁されているので使いやすい構成となっている。また、±15Vを直列に使って30V電源としても使用することができる。価格は、フルタカパーツセンターオンラインで3410 円であった。外観を図 8.3に示す。またデータシートは以下の URL を参照されたい。 https://www.cosel.co.jp/product/powersupply/MGW/

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image3.jpg}
\caption{ガルバノ用DC-DCコンバーター　COSEL MGW30}
\end{figure}
//}

Vin+ を 12V に接続し、-Vin と RC を GND に接続する。これだけで ±15V が出力される。なお、型番にR が付いている場合、RC は反転しているので、＋ Vin に接続する必要がある。
 
===	レーザーポインター用 DC-DC コンバーターの選定
次にレーザポインタ用の電源の設計である。3.3V 出力の DC-DC コンバーターは比較的多いが、 3V 用はラインナップとしてそれほど多くない。今回、入手性より、12V → 5V → 3V の 2 段構成とし、12 → 5V にはCosel	SUS31205 を選択した（図 8.4）。3 端子レギュレータで直接 12V から 3Vを出力した場合、その差の 9V 分は熱として変換されてしまうため、エネルギー効率と発熱の観点より、5V を経由することとした。とは言え、SUS31205 の変換効率は 79 ％ Typ なので、MGW30の 90 ％には及ばない。入力 12V、出力 5V0.6A の DC-DC コンバータである。DIP 型のモジュール品であり、ブレッドボードの 5×10、すなわち 12.7mm×25.4mm に収まるコンパクトサイズである。価格は、フルタカパーツセンターオンラインで 1100 円であった。データシートは以下である。 https://www.cosel.co.jp/product/powersupply/SUS/

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image4.jpg}
\caption{レーザーポインター用DC-DCコンバーター　COSEL SUS3}
\end{figure}
//}

こちらも、＋ Vin を 12V に、RC と-Vin を GND に繋げば 5V が出力される。TRM 端子は出力可変とするときのみ使用し、使用しないときはオープンとすればよい。ただし、可変幅は ±5 ％と微調整しかできないようだ。

ところが、使用するレーザーポインタが、3.0V 定格のはずが、5V 程度まで電圧をかけないと動作しないことがわかった。結果、3 端子レギュレータで降圧する必要がなくなってしまった。

===	デモ用電源装置の組み立て
これで、ノートパソコン、ガルバノ、レーザモジュールについて DC-DC の選定が完了した。ついでこれらの 3 つのモジュールを配線する。せめて配線図を CAD で書けばまだしも、適当な図を書くだけである。全体構成としては、図 8.5 の通りである。次は、これらを一括してハンダ付けして、線をつなげば使えるようにしてしまう作業である。実際問題としてはこれまでファストン端子等を使って現地で配線していたため、バタバタやると外れたりショートしたりという問題があった。そこで今回は、前もって配線をやっておくこととする。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image5.jpg}
\caption{デモ用電源装置の構成}
\end{figure}
//}

それ以外に、電圧電流監視のためのパネルメーターやパイロットランプとしての LED などを追加して、電源装置を制作した。せっかく絶縁型のモジュールを使っているので、出力側の GND はそれぞれ独立している。LED の点灯回路は、適当に作っており、間違ってると恥ずかしいので載せない。 

パネルメーターは 3 個であり、入力電圧、入力電流、XL6009-DC-DC モジュールの出力電圧をモニタしている。チャンネルごとに ON/OFF スイッチを備える。パネルは、加工の簡単のために、 4mm シナ合板とした。シナ合板は、安価で加工が容易、木目や節がほとんどなく見た目はキレイ、強度はイマイチなどの特徴がある。入手性もよく、近所のホームセンターで普通に購入可能であり、サブロク板で 1000 円ちょっとで購入可能である。表面はシナ材、芯はラワンである。4mm 厚ならばカッターで繰り返し切込みを入れるなどでカットできるので、構造部材として使うには不安があるがちょっとしたものを作るには適している。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image6.jpg}
\caption{デモ用電源装置の前面}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image7.jpg}
\caption{デモ用電源装置の裏側}
\end{figure}
//}

展示机のサイズと、使ったパネルメーターのサイズから、幅 180mm、高さ 160mm とした。足は、手元にあった角度付きアルミフレームを使うこととした。全景写真を図に示す。

XL6009 の出力電圧は事前に調整しておく。レーザーポインターと PC の電源ケーブルは取り回しが面倒なので、現地で接続できるようにプッシュターミナルで受けることとした。スピーカーなどで使われることもあるが、バネを押さえると開き、ケーブルを入れて離すとロックされるやつである。秋月電子などで 1 個100 円程度で売っている。これをパネルのあいている領域に付けた。

パネル上の 3 つのメーターは、

 1. 電源電圧確認 (15V 電圧計)、
 2. 電源からの電流確認（5A 電流計）、
 3. ノート PC 用電源電圧

//noindent
であり、主電源と、3系統のON/OFFのためのトグルスイッチを備える。また、それぞれの LED は、左から、主電源、ガルバノ電源、PC 電源、デモ用 DPSSL の電源の ON 時に点灯する。裏は配線グチャグチャだが、メーター類への接続は圧着端子を使っているので多少なりとも安心感はある。一応はんだ不良などの対応としてみのむしクリップは何本か持っていく予定である。

==	定盤製作
コミケで展示するにあたり、デモ用定盤を製作する。また、デモ用のみならず、今後の光学系設計にも活用する予定である。精度などの観点から、最終的にはきちんとした光学定盤を購入する可能性はある。とはいえまずは、ガルバノスキャナとグリーンレーザモジュールを保持するだけの寸法があればよい。そこですのこタンを使用した。更に、光学部品を保持するためのマウントロッドやホルダーについても記載する。

===	光学定盤の選定
一般に光学定盤@<fn>{breadboard}とは、アルミハニカム材などを芯材とし、表面に格子状のネジ穴を備える。図 8.8に典型例を示す。定盤だけのものもあれば、テーブル様の足つきのものもある。定盤上の機器を固定し、長時間光軸を維持するため、変形が少なく、振動に対する減衰が大きくある必要がある。そのため一般的にはかなりの重量を有する。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image8.png}
\caption{光学定盤の例　明和精機HSBシリーズ}
\end{figure}
//}

//footnote[breadboard][市販の光学定盤の例として、明和精機 HSB シリーズ/LHS シリーズ(http://www.meiritz.jp/#sel-guide-table.html)を示す。図8.8引用元]

しかし、現時点ではこれほど大きな定盤を使用する必要はなく、ある程度固定できれば十分である。そこで、軽量で加工が容易であり、精度がそこそこ出ているものを検討した結果、すのこタンを用いることとした。

すのこタンとは、PC などの冷却用に有限会社マルダイが製造販売しているアルミ製のスノコである。数年前につい購入したものの、その後使い道がなかったため死蔵していたものである。軽量でそれなりの精度が出ており、加工が容易なため採用した。外観を図8.9に示す。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image9.jpg}
\caption{すのこたん(マルダイHPより)}
\end{figure}
//}

//quote{
商品名：すのこタン	株式会社マルダイ	http://www.sunokotan.com/item/lineup-001.html

材質：アルミニウム（A1100 ／ A1050）

寸法：たて 169mm よこ 273mm× 高さ 14mm

重さ：275g

価格：2,300 円（税込）
//}

//noindent
である。なお、すのこタン絶対領域であるのは、趣味であり、無地やノーマルすのこタンでも何ら問題ない。また、それ以外の素材、製品の使用を妨げるものではない。

なお、ここでは無地の「すのこタンイラスト無し」を表示した。現物はメーカーHPまたは現場で御覧頂きたい。蛇足ながら、すのこタン絶対領域は2012年10月で販売を終了したとのことである。

次に、すのこタンに穴を開ける。使用するドリルは 4mm であり、適当な位置に穴を開ければ良い。4mm 程度ならば、絵のほうには影響は殆ど無い。現時点では、レーザモジュールとガルバノの 2 本のみなので、位置はそれほど気にする必要はない。


===	マウントロッド
マウントに用いるロッドは、通常直径 1 インチないしは 0.5 インチのステンレスなどの棒である。上下または片側にネジが切ってある場合が多く、定盤に直接またはロッドホルダーを介して取り付ける。ロッドおよびロッドホルダーの例を図8.10に示す（画像出典：株式会社シグマ光機http://www.products-sigmakoki.com/）。典型的な価格としては、ロッドが1本1000円程度、ホルダーも 2～5千円程度の価格である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image10.jpg}
\caption{ロッドとマウント}
\end{figure}
//}

しかし、高精度な光学系ならいざしらず、今回のように単純に固定できれば良い場合は、自作すれば良い。もちろん、SUS棒を旋盤で削りだすなどして制作しても良いが、今回は手抜きするため樹脂パイプ（図 8.11）を利用した。ここで注意すべきことは、樹脂パイプは押出形成を行なっているため、多少の曲がりがあることと、自分で切断することから、端面の精度が低いため、垂直とはならない、という点である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image11.jpg}
\caption{株式会社光モール　硬質ABSパイプ}
\end{figure}
//}

所詮ガルバノスキャナとレーザモジュールだけである。さらに、展示の間だけ持てばよく、搬入時の軽さにも重点をおいた。
使用したものは、ABS 樹脂製のパイプであり、内径 8mm、外形 12mm のものを採用した。1m 定尺で 300 円程度である。ABS 樹脂は、硬質プラスチックの一種で、強度は高めだが、非常に安価である。例えば、株式会社光モール http://www.h-mol.co.jp/product/item.php?pid=1&mid=11などで製造されており、ホームセンターなどで購入可能である。

ただし、このままでは、定盤に立てることはできない。そこで、両端をメス相当にし、上下からネジ止めする形とする。しかし、ABS にネジを切ることは結構難しいとともに、内径が8mmもあるため、単純にネジを切った場合、M9程度のネジとする必要がある。M9 の穴を定盤に開けることは現実的ではない。なにより、せっかくのすのこタンの絵が消えてしまうではないか。

したがって、ABS パイプとコンクリート用エビプラグを使用したロッドを作成する。手順は以下のとおり。

 1. ABS パイプを指定長さに切断する。
 2. 端面を軽く研磨する。 
 3. エビプラグ（図 8.11）を挿入する。 
 4. 定盤裏から M4 のネジで止める。

ABSパイプの切断は、金鋸で全周に 1mm 程度の切り込みをいれ、折り取ることで実施すると簡単である。パイプカッターで切っても良いが、手持ちがない場合、あまり汎用的とはいえないので、パイプカッターの購入は見送った。今回は、1 本 200mm としたため、1m のパイプから 5 本のロッドを取ることができた。もともと、定尺 1m だが、1000mm より少し (5 ミリ程度) 長かったので、切り代を考えても、5 本取ることができる。また、切断後のABSパイプは数本まとめて紙やすりで研磨して、長さをそろえるとともに、両端の平面出しをしておくとよい。平面出しといっても、長さがそろっていればそれなりに平面は出るし、

エビプラグとは、コンクリートなどにネジ止めするために使用するもので、下穴に打ち込んで、エビプラグにネジを噛みこませることでネジを効かせるものである。8mm 下穴用を選ぶ。適切に挿入されれば、M4 のネジが入る隙間となる。パイプ内径 8mm 場合、7mm 下穴用のエビプラグを選んではならない。7mm 用ではほとんど抵抗なく入ってしまうため、簡単に抜けてしまう。とはいえ8mm のエビプラグは、手では挿入できないため、ハンマーで撃ちこむ必要がある。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap8/image12.jpg}
\caption{エビプラグ}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.8\linewidth]{images/chap8/image13.jpg}
\caption{ロッド端部製作の成功例と失敗例}
\end{figure}
//}

軽く何回も叩くのが良いのか、一気にやってしまうのが良いのかはわからない。一気にやるのと、軽く打ちこむのを繰り返すのとでどちらが良い野かはわからない。なぜなら、どちらでも成功したし、どちらも失敗した例があるからである。成功した場合は、図 8.13 左のようになる。

失敗した場合、図8.13右のようにパイプが割れるとともに、エビプラグの内径が大きくなってしまうため、M4 のネジが効かなくなってしまう。こうなった場合は、廃棄するしかない。

このような手順を踏めば、定盤用のロッドを作成することができる。実際に展示に使用しているロッドはこうして制作したものである。必ずしも歩留まりは良いとはいえないし、決して精度はよくないが、用途を絞れば使用出来ると考えられる。また、多少なりとも取り付け精度を向上させるためには、上下の研磨のときに長さをそろえるとよい。

==	レーザーモジュール熱対策
本節では、デモで使用しているレーザーモジュールの特性確認、水冷によるレーザーモジュール熱対策をおこなったのでこれについて述べる。

===	レーザーモジュール諸元
デモで使用している秋月グリーンレーザモジュール動特性について評価したので、ここで述べておく。秋月グリーンレーザは、添付のデータシート上は 3V 定格、3.3V 絶対最大定格とある。しかし、手元のモジュールは3V程度は発振しなかった。そこで、まずは IV 特性および目視による発振閾値を調査しておく。なお、この調査は、このグリーンモジュールに関した話であり、これを実施することで故障したりする可能性もある。仮に、実験によりグリーンレーザモジュールが故障したりしても、筆者およびサークルは責任を負いかねるのでご了承いただきたい。

安定化電源に接続し、定電圧駆動状態とし、通電電流の読み値を記録する形とする。安定化電源の表示パネルは 0.00 と小数点以下 2 桁なので計測精度は10mA単位である。図 8.13 に IV 特性を示す。また、グリーン発振の閾値は 3.65V にあった。感度の適切なパワーメーターが手元にないので発光強度についての調査はできない。しかし、いずれにせよ、絶対最大定格電圧を大きく超えたところで動作している。可能性としては 3 つあり、

 1. そもそもデータである 3V が間違っている、
 2. 過電圧をかけて壊してしまい電圧を上げないと動作しない、
 3. VR が変わってしまい 設定が変わった。

ただし、電流値は定格の約 200mA まで印加してちょうどよい輝度が得られることから、3 が怪しい。

グリーンレーザは、808nm の近赤外 LD の発振を波長変換により 532nm のグリーンに変換している。したがって、LD の発振閾値と、532nm の発振／変換における 2 つの閾値が存在する。LD の発振閾値は 2V そこそこであり、SHG に必要な光強度に達するには 160mA、電圧にしておよそ 3.65Vの印加が必要であるということがわかった。当初の特性を計測していないのでこれが購入当初と同じであったかは不明だが、とりあえず動作しているので良しとする。

===	熱対策方式の選定
グリーンレーザーモジュール内の半導体レーザーの熱効率は約 50 ％程度と推察されるし、基本波→ SHG への変換効率を考えると、実際上入力エネルギーのほとんどがロスになる。先ほどのグラフから、5V200mA とすると、1W の熱が発生する事になる。筐体は真鍮であり、それなりの大きさがあるが、それでも10 分程度の使用で筐体が熱を持つ程度に発熱する。秋月モジュールには温度監視があるようで、パイロットランプがグリーンから黄色に変わるとともに、ある程度以上の温度になると、出力が低下し、輝度が低下する。

これまで会場でデモをする場合、モジュールの上に濡れティッシュを置いて冷却するという形をとっていた。特に夏コミでは冷却をしないとあっという間発振しなくなった。このままつづけてもよいのだが、見た目にしょんぼりなので、今回水冷式熱対策システムを製作することにした。政策方針として、以下の方法を検討する。
 
 1. ペルチェ冷却
 2. 強制空冷
 3. 水冷
 
 それぞれのメリット・デメリットを述べる。

==== ペルチェ冷却

ペルチェ素子とは、二種類の金属の接合部に電流を流すと、片側の金属からもう片側に熱が移動するという現象を利用した板状の半導体素子である。一方が吸熱、一方が発熱となるため、冷却したいもの吸熱側に接触させることで冷却が可能となる。冷却装置の体積が小さく、可動部分がないから振動などが発生せず、信頼性が高いというメリットがあり、CPU の冷却や小型冷蔵庫やワインセラーなどに使用されている。一方、熱効率が低く 1W 移動させるのに 1.2W 消費すると言われている。すなわち、冷却側で吸熱した熱と素子自体の消費電力分の合計が放熱側で発熱するため、放熱側の冷却が大変となる。

==== 強制空冷

ファンを近くに設置するだけで良いから簡単ではあるが、外気温が高い状態では有効な冷却が期待できない。夏コミ会場内は非常な高温になることが予想されるため、冷却効率が低下する。また、現状のようなレーザーモジュール単体では熱交換の効率が低く、効果的な冷却は期待できない。

冷却量と風量の関係は、次式となる。*10

//texequation{
Q_1=\frac{0.05×P}{\Delta T}
//}

ここで、Q@<sub>{1} は風量（m@<sup>{3}/min）、P は発熱量 (W)、∆T は温度差を示す。またこの式が成立するのは、発熱体を含む空間について入る空気と出る空気の量が定義できる場合であり、開放空間で熱交換に寄与しない成分が含まれる場合には成立しない。今回のデモにおける熱交換の効率を考えてみると、わずかに 12mmφ のレーザーモジュールの冷却を行うためには大きな風量が必要であり、外気温が高いことも含め、かなりの困難が予想される。

==== 水冷
レーザーモジュールの周囲に水を還流させ、冷却を行う方法である。水で冷やすというとローテクではあるが、比熱はあらゆる物質の中で最大であり、冷却効率が高くなる。水の比熱は4.2J/g・Kであるのに対し、真鍮（黄銅）は0.39J/g・Kであるから、1g の水の温度を 1 ℃上げると、11g の真鍮の温度を1℃下げることができるという意味である。

したがって僅かな水を還流させることでレーザーモジュールを冷却することができる。水漏れなどの問題があるため、PC の水冷はいろいろノウハウがあるが、今回は完全自作でやってみることにする。

8.3.3	水冷の設計
まず、レーザーモジュールの寸法を確認しておく。全長 31mm、直径 12mm である。おしり 4mmに温度センサ用の穴があるから、ここに水が入ってはマズい。また、前から 3mm の位置に、レンズ固定モジュールとの分離のための線があり、モジュールの筒はそれらを除いた 24mm を水冷に使える範囲とする。レーザーダイオードは後ろがわから挿入するため、これらの範囲を冷却しておけば用は足りると考えられる。参考として、レーザーモジュールの写真を図に示す。
小型のセルにレーザーモジュールを取り付けるとともに、水の出入りのためのフランジ、パイプを取り付ける。使用するポンプは、Amazon で適当に検索して引っかかった最安品であ

*10 ファン  技術資料  -ミスミ	http://jp.misumi-ec.com/maker/misumi/el/tech/den/fan/gijyutu.html
 
 
図 8.14 秋月グリーンレーザーモジュール

り型番は WH-D12220 である。動作電圧 3.5∼12V、100∼400mA と表示されており、流量は 40∼220cc/min,100∼350 l /h との記載がある。また吐出孔の直径は 8mm、吸入口のパイプ外形が 10mm である。全水没で使用できるタイプであるが、水タンクの形状などを考えると、ポンプ本体は水槽外部とするほうが良さそうである。とおもっていたが、このポンプは吸口が水没していないと動き始めないタイプであることがわかった。ということがあとでわかったので作業のやり直しが発生してしまった。


まずは簡易水冷として、必要な水量について検討する。仮に 5V200mA で動作するとすると、レーザーモジュールからは 1W 程度の発熱があることになる。したがって、1g の水は 4.2 秒で 1 ℃温度上昇が起こることになる。水タンクとしてはペットボトル程度あれば十分と考え、循環に使う水量を 300mlとする。10℃温度が上昇したとするときに吸収できる熱量は、300g×10℃×4.2J=12.6kJとなる。レーザーポインターの発熱は約 1W であることから、12.6ks、すなわち 3.5時間となると想定される。こういう計算をしてみて、意外と持たないものであると感じた。

実用上はコミケの開場から閉幕まで連続動作してくれることがのぞましいものの、途中で一度交換するなどの対応を取ればよく、500ml程度の水を循環しながら使用する設計とする。水は現地調達とし、キャップ部分に給水・排水のホース2 本を取り付ける。水漏れがあっては大変なので、穴加工とともに、シリコンコーキングで埋める形とした。使うシリコンコーキング剤は、セメダイン社製バスコークである。近所のホームセンターで100mlで700円ほどであった。別件でおすすめされていたもので、コーキングガンがなくても使えるので採用してみた。
 
使用するホースは、透明塩ビの9mm内径、12mm外径のものとした。2mで450円@Amazonと安価である。今回は特に圧がかかるわけでもないため安価で良かろうと選択したものである。取り付けてみると、吐出孔の方は若干ゆるいが、ホースバンドで締めれば特に問題なく固定が可能であった。

水冷タンクとレーザー用セルは、100均のヨーグルト用タッパー(650ml、直径10.5cm、内寸約8cm)と、その近くにあった一番小さいタッパー(55L×80W×20H、80ml)とした。

=== 水冷モジュールの組み立て

水冷システムの構想図を図 8.18 に示す。結果的には、右の採用配置案となってしまったが、順に説明することとする。ポンプを水没させるのは、水を入れたり抜いたりする際に電源穴をさらに開ける必要があり避けたかったためである。ポンプの仕様上致し方なし、となったわけである。

まず、水タンクの蓋に穴を 2 個開け、水ホースを 2 本取り付ける。1 本は短め、1 本は長めにしておく。蓋の穴はホース外径であるところの 12mm 程度だが、手持ちドリルが 10mmφ が最大であったため、10mm 穴をカッターナイフで削り広げる形で穴を開けた。その後、塩ビ管を通し、バスコークで封止をする。

次に、水セル用のタッパーには、横に 2 つ水配管用と、前に 1 つレーザーモジュール用の 12mmの穴を開け、後ろ側に 2 個、3mm の穴を開けた。これはレーザーモジュールの電源用である。レーザーモジュールを取り付け、配線を引き出し、こちらもバスコークで封止する。レーザーモジュールの隙間およびプリント基板部分にもバスコークをぺたぺた塗っておく。裏表両面はもちろん、LD の隙間やレンズ部分の隙間にも塗っておく必要がある。

こうして完成したのが、図 8.19 および図 8.20 である。早速動作確認をしてみると、まず水が流れない。このポンプの仕様が、水没でないと起動しないタイプのようだ。となると、水タンクの中に入れる必要がある。すでに固めてあるので、一旦取り外す必要があるが、今回は先に動作チェックを行った。

ポンプを水没させ、タッパーの蓋を取り付け、通水する。パイプ分の水が減ってタンクの水が半分くらいになってしまうが、順調に循環されているようだ。次に、レーザーの電源を入れてみる。グリーン発振確認。長時間だとどうかわからないものの、短時間の動作には問題ないようである。

ところがこの動作確認において、動作中に水漏れすることがわかった。水漏れ箇所は、配管部分と、タッパーの蓋部分であった。タッパーに圧をかけて使うことはないので水圧がかかるような用途は想定外であり、小さいタッパーというところも含めて水漏れがしているのかもしれない。

この水漏れ問題については、接続部については内側・外側両面のバスコーク塗布にて対応することとした。蓋からの水漏れについては、蓋の溝にバスコークを塗布して、硬化前に蓋を嵌めてしまうことで水漏れを防ぐ形としてみた。最終的な全体構成は図 8.21 となる。なお、バスコークを含むシリコンコーキング剤は一度乾くと重ね塗りが出来ないので、再度打ち直す予定である。水冷モジュールの改善は当日までに実施するとし、当日をお楽しみに！
