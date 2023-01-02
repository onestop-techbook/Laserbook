= レーザーとはなにか

まっすぐ進む光。コンサートなどで使われる赤や緑のやつ。レーザーポインターの光。CDやDVDの読み取りに使うやつ。このあたりがレーザー光のイメージかと思われる。一方で、普通の光と何が違うかと考えたとき答えは簡単には出てこないのではないだろうか。第一章ではレーザー光の特徴と理論について述べる。

レーザー光の特徴のひとつに単色であるという性質がある。これはある波長の光のみでできているということで、緑なら緑の光、赤なら赤の光だけからなる。逆に太陽光のような光は、いろいろな色=波長の光が含まれているため、プリズムなどで光を分けてやれば連続的に分布する光に分ける事ができる。では、たとえば太陽光をプリズムで分けて、緑の光を取り出したとする。また緑のレーザーポインターの光を持ってきたとする。この両者の差は？その差ついて、以下述べることにする。

その前にレーザーという言葉についての説明を行う。レーザー (あるいはレーザ：LASER) という言葉は、原子や分子による誘導放出を利用して光を増幅すること、あるいは増幅した光のことで、Light Amplification by Stimulated Emission of Radiationの頭文字を集めた言葉である。原理は後から詳しく説明するとして、最初に生まれたのが1960年であり、生まれてから50年以上経過した。その間いろいろなレーザーが開発され、いろいろな応用がなされてきた。20世紀はシリコンの時代、 21世紀は光の時代とも言われ、今となってはありとあらゆるところに使用されており、加工、計測、通信、記録・・・などなど、レーザーと無縁の産業や技術はいまとなってはほとんど無いといえるだろう。

レーザーは光の誘導放出が原理となるので、逆にいえば誘導放出が含まれれば原則としてレーザーと呼ばれる。したがってその波長に制限はなく、可視光は言うまでもなく、紫外から赤外まで、果てはマイクロ波領域まで発生させることができる。ただし一般にマイクロ波領域となると、Lightではなく、Microwave～となり、メーザーと呼ばれる事が多い。一方で、誘導放出を含むけれどもレーザーとは呼ばれないもの、逆に誘導放出を伴わないが慣例としてレーザーと呼ぶものがある。それらについては後述するとして、一旦は光の誘導放出がレーザーの必要条件であると考えて良い。

== レーザー光の特徴
それではまず、レーザー光の特徴から述べてみることにしよう。 直進性、単色性と指向性、エネルギー効率と輝度、パルスレーザーと連続レーザーという、それぞれの特徴から、レーザーが普通の光とどう違うのかを概説する。

=== 直進性
レーザー光の特徴として、まずなんといっても指向性が挙げられる。指向性がよいということは、長い距離を伝搬しても広がらないということで、反射や屈折させない限りほとんど一直線に進む。中でもガスレーザーなどは広がり角が小さく、一方で半導体レーザーなどはガスレーザなどに比べると広がり角が大きく指向性に劣る場合が多い。普通のレーザーの広がり角は 10@<sup>{−4}rad 前後であり、具体的には数ミリのビーム径を持つレーザー光が100m伝搬した後にビーム径が数cm程度になるということである。豆電球など普通の光と比較すれば、その差は明らかになろう。

=== 単色性と指向性
次の特徴として、単色性が挙げられる。

たとえば白色光の代表である太陽光はプリズムを通すと虹色に分かれることはご存知かと思う。これは太陽光がいろいろな色=波長の光でできていて、結果白く見えているということである。一方でレーザーは基本的に単色である。ただしこれもレーザーの種類によって大きな差があり、ガスレーザーなどは単色性が高く、半導体レーザーや超短パルスレーザなどは単色性が低い。普通のガスレーザーであれば、周波数で書くと1MHz～1GHzの幅を持つものが典型となる。より安定な気体レーザー、例えば外部の基準を用いて周波数を安定化したガスレーザーには、1Hz以下の周波数幅しか持たないものもあり、単色性が極めてよいといえる。なお光の周波数は100THzからPHz程度なので、スペクトル幅が1GHzあるといっても、波長で言うと0.01オングストロームの幅しかないため、どんなに性能のよい分光器を使っても分離することはできない。逆に半導体レーザーなどは比較的帯域が広く、波長数nmの幅を持つことがある。さらに超短パルスレーザーなどは、数十nmにわたる帯域幅を持つことがある。フーリエの関係から、パルス幅が短いものは、帯域幅が伸びるためである。

=== エネルギー出力と輝度

レーザーのパワーやエネルギー密度について述べる。レーザーの出力は一般に小さく、例えば気体レーザーの代表であるHe-Neレーザーの出力は1mW～40mW程度がせいぜいであり豆電球よりも弱いし、大型の固体レーザーでも出力は数Wから数10W程度で蛍光灯と同じくらいの光出力しかないことになる。半導体レーザーでは、1mWをきるものから数W～数100Wに達する半導体レーザーをスタックしたものがある。また金属切断に使うCO@<sub>{2}レーザーやファイバレーザーなどの加工用レーザーは出力が数KW程度に及ぶものがある。

さらにレーザー光は先ほど述べたとおり、指向性がよく、単色性もよいので、広がらずに利用する事ができる。さらに簡単な光学系で強く集光することができる。普通の凸レンズを使って直径数µm程度まで簡単に集光することができることから、集光部のエネルギー密度はMW/cm@<sup>{2}どころか、GW,TW の輝度が簡単に得られるということになる。また光が電界の振動であることを考えると集光点での光電場は 10@<sup>{10}V/m という強電界となる。世の中の話として、高圧電線直下の電界が健康への影響があるのではないか?とか、携帯電話の電磁界が体に影響を及ぼす、とかいった話があるが、その真偽はともかく、それらとは桁違いの強電界が得られることになる。このような強電界は原子のポテンシャルと同程度の電界強度になるため、たとえば光で直接電子を励起したり、化学結合を直接切断したりといったことが可能となる。

また強く集光できることから照射部位に集光することで局所的に素材の融点/沸点以上まで加熱することで加工を行う事ができる。これを利用してマーキング、穴あけ、切断など加工を行う「レーザー加工機」というジャンルの工作機械も市販されている。なお一般にレーザー加工といった場合は熱加工となり、加工対象を熱で溶かすまたは蒸発させることにより加工が行われる。光源としてCO@<sub>{2}レーザーや固体レーザーが多く利用されていたが、最近では比較的低出力なものでは半導体レーザーを利用した安価なシステムが、中出力ではメンテナンスが容易で、安価にできるファイバレーザーを利用したシステムが市販されている。またこれまでは CWからQCW、あるいはナノ秒のパルスレーザーによる熱加工が主流であったが、近年では短パルス化が進み、ピコ秒やフェムト秒レーザーといったいわゆる長短パルスレーザを利用するレーザー加工機も市販されるようになってきた。超短パルスレーザーを用いることで周囲に熱伝達する前に全エネルギーが注入され加工が行われるために、周辺への熱影響を低減したきれいな加工が行えたり、その高いピーク強度からこれまでレーザー加工の難しかった透明材料や金属材料への加工が行われるようになった。厚い金属の切断などのレーザ加工には酸素などのアシストガスを用いて溶断する場合もある。

ところで、レーザー発生におけるエネルギー効率についても考える。レーザーのエネルギー効率は一般に低く、入力したエネルギーに対して出力される光エネルギーはかなりに小さい。一般的なガスレーザーの場合通常 0.1% 以下であり、半導体レーザーなどでもせいぜい数十％程度が最大となる。光で励起する固体レーザーなどにおいても、入力光のエネルギーに対して出力光のパワーは非常に小さい。たとえばフラッシュランプ励起の固体レーザーなどでは、消費電力数 KW のフラッシュランプで励起して、せいぜい数 W のレーザー出力が得られる程度となる。

=== パルスレーザと連続発振レーザ
さて、パルスレーザーの話が出たので、連続(CW:Continuous Wave Laser)レーザーとパルスレーザーについてもここで少し触れることにする。水道の蛇口のように、常に連続的に光が出てくるものを連続レーザーと呼び、逆に水鉄砲のように間欠的に出力するようなレーザーをパルスレーザーと呼ぶ。世の中のレーザーには、CW動作しかできないレーザーと、パルス動作しかできないレーザーと、両方できるレーザーがある。原理的にCW/Pulse動作が決まっているものと、実用上の制限からくるものがあり、CWレーザーにはCWレーザーの、パルスレーザーにはパルスレーザーの利点がある。

CWレーザーは一般に周波数/波長が安定で低ノイズなどのメリットがあり、計測などの用途において力を発揮する一方、瞬間的なパワーは小さくなる。すべてのレーザーが連続発振できるわけではなく、エネルギー準位の制約という原理的なものや、熱設計上の困難から連続発振ができなかったり、CW動作時の出力に制限がかかることも多い。先述したとおり入力エネルギーに対する出力エネルギーが小さいため、入力したエネルギーのほとんどは熱となる。したがってその熱をなんらかの方法で系外に運び出さないと、効率が下がったり素子が壊れたりする。そこで自然放冷だけでなく、ファンを用いた強制空冷、ペルチェ素子や水を用いた強制冷却を行う場合がある。また熱により効率が落ちるだけでなく、発振波長が変化する場合がある。原因は蓄積した熱により共振器長が変化するためや、半導体レーザなどではバンドギャップが変化するなどの理由による。

一方、パルス的に光を出すような動作モードがあり、これらをパルスレーザーと呼ぶ。レーザー媒質の励起強度を直接変調するとか、Qスイッチをかけるとか、モードロックをかけるなど、方法は様々あるが、一口にパルスレーザーと言ってもその時間幅は多様で、擬似連続波(QCW) と呼ばれることもあるような数マイクロ秒から数ミリ秒の矩形波状パルスとなるものから、ナノ(10@<sup>{−9})秒、ピコ(10@<sup>{−12})秒、フェムト(10@<sup>{−15})秒のオーダーの時間幅を持つレーザーもある。実験室レベルでは、フェムト秒以下のアト(10@<sup>{−18})秒のパルスレーザーも存在し、計測などへの応用が期待されている。

これらのパルスレーザーのメリットを述べる。まずパルスレーザーはCW レーザーに比較して、尖頭出力(Peak Power)が高いことが挙げられる。ここでいう尖頭出力とは、パルスエネルギー(単位：ジュール)をパルス幅(単位：時間)で割ったものであり、J/s=W の次元を持つことからもわかるように、瞬間的な出力を表すものである。たとえば30nsのパルス幅を持つレーザーで、1パルスあたりのエネルギーが30mJのパルスレーザーを考えると、ピーク出力は1MWとなる。またフェムト秒レーザーになれば、TWオーダーの出力が得られることになる。さらに通常レーザーを加工に用いる場合はレンズ等で集光するため、焦点での出力は更に向上する。したがってパルスレーザーを使用すれば、通常のCWレーザーでは加工できないような材料なども含めて、ほぼあらゆる材質にたいして加工を行うことができる。例えば、ガラスなどの透明材料では、光に対する損傷閾値が高い上に光の吸収が小さいため、CWレーザーでの加工は困難であった。ところがフェムト秒レーザなどの超短パルスレーザーを用いることで、多光子吸収を起こし加工することができる。多光子吸収を利用すると、光の弱い領域では加工が行われず、集光している焦点のみが加工されることから、透明材料の内部加工や、難加工材料の微細加工が行える。

またパルスレーザーを用いた計測技術に、時間領域計測またはポンププローブ法がある。イメージ的には、ごく短い時間幅を持つフラッシュのようなもので観察するということになり、化学反応などの超高速現象を計測出来る技術である。特にフェムト秒レーザーのパルス幅は電子の移動よりも短い時間となるので、カメラなどでは捉えられなかった超高速現象を計測できる。市販のいわゆる高速度カメラであってもkHz～MHzのフレームレートが限界@<fn>{highspeedcam}であるから、時間分解能も同程度の1msとか1µsが限界となる。1nsの分解のためにはGHzのフレームレートが必要となる。一方でフェムト秒レーザを用いたポンププローブ法ではfsオーダーの時間分解能が得られ、超高速現象も捉えられる。ポンププローブ法は観察したい現象に対して少しづつずらしたレーザー光（プローブ光）を照射し、現象を再構成する。最初の光（ポンプ光）で物質を励起し、プローブ光に時間差をつけて照射・計測することで現象発生(=ポンプ光照射)のから一定時間後の現象を解析することができる。時間を距離に直すと 1秒=3×10@<sup>{8}m なので、0.3mmが1psの時間差となる。同様に100fsは30@<m>{\mu}mに相当する。電子機器等で1psを制御することはほぼ不可能であるが、機械制御で位置精度 0.3mmといった程度なら市販の自動ステージで十分に達成可能である。装置構成をごく簡単に言えば、マイケルソン干渉計の片方の腕のミラーを可動鏡とすることで達成される。ポンプ光が入射しその直後にプローブ光が入射することで、その瞬間瞬間の現象を撮影/観測することができる。そしてポンプ光とプローブ光の間隔を少しづつ変化させ、アニメーションのように再構成するものである。

//footnote[highspeedcam][高速度カメラで有名なフォトロンのハイエンド機で 2Mfps、民生用デジカメの高速撮影モードもあり、たとえば CASIO EXILIM	EX-ZR1600 で 1kfps。十分すごいけれども。]

さてここでパルスレーザーのスペックに関するパラメータについて説明する。まずはパルス幅。これはそのままの意味で時間的なパルスの幅であり、パルスの持続時間である。半値全幅などで定義することが多い。レーザーによってナノ秒であったりフェムト秒であったりし、その時間幅でもってナノ秒レーザーとかフェムト秒レーザー（多少サバを読むことはある）と呼ぶ。次に平均出力がある。平均出力の単位はW(J/s)であり、1秒当たりの放射エネルギーである。CWであろうとパルスレーザーであろうと定義は同じである。ただしパルスレーザーにおいてはパルスエネルギーと繰り返し周波数が重要なパラメータとなる。パルスエネルギーは1パルスあたりのエネルギーで、J/Pulse で表現される。また繰り返し周波数は1秒間に何回パルス出射するかの値であり、パルスエネルギー×繰り返し周波数=パルスレーザーの平均出力となる。概して加工用などパルスあたりのエネルギーが重要な利用例ではパルスエネルギーを表示する事が多いと思われるが、一方で出力が高いほど高く売れるので数値が大きくなるように表示されることが多い。

==	レーザーの種類
主なレーザーについてその特徴について述べていく。レーザーにはたくさんの種類がありそれぞれが特徴を持つ。パルス動作ができるもの、大きなパワーが出せるもの、取り扱いが簡単なものなどなどあり、その特徴を述べる。

===	固体レーザー
強い蛍光を持つ結晶やガラスを光で励起し、蛍光波長で発振するレーザーを固体レーザーと呼ぶ。媒質は固体でも半導体レーザーやプラスチックを活性媒質とするレーザーは普通固体レーザーには含まない。歴史的に最初に発振したレーザーはルビーレーザーであり、サファイア基材に Cr@<sup>{3+}を含んだものである。一般的な結晶の基材としては、YAG(Yttrium	Aluminum Garnet:Y@<sub>{3}Al@<sub>{5}O@<sub>{12})やルビー/サファイア (Sapphire:Al@<sub>{2}O@<sub>{3})、YLF(Yttrium Lithium Tetrafluoride:YLiF@<sub>{4})、アレキサンドライト(Alexandrite:BeAl@<sub>{2}O@<sub>{4})、YVO@<sub>{4}(Yttrium Orthovanadate) などがある。基材に必要とされる条件は、熱伝導性、機械的強度、耐熱性、透明度などである。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/img1.png}
\caption{レーザーの模式図}
\end{figure}
//}


Cr@<sup>{3+} や Nd@<sup>{3+}などの蛍光を発する遷移金属や希土類元素を活性原子イオンと呼び、主な活性原子イオンとしては、Nd@<sup>{3+}(1.06@<m>{\mu}m)、Ho@<sup>{3+}(3.9@<m>{\mu}m)、Er@<sup>{3+}(1.55@<m>{\mu}m)、Ti@<sup>{3+}(700-900nm) などがある。カッコ内は主な発振波長である。これらのなかでも Nd:YAG は最も幅広く利用されているレーザー結晶であるといって差し支えない。固体レーザーの構成は図 1.1 のようになっている。この図はもっとも簡単なレーザー共振器であり、ほとんどのレーザーの原理的な構造はこの共振器の形を取る。レーザー結晶を円柱に研磨し、その両端面を並行となる様に研磨したものレーザーロッドとも呼ぶ。これを2枚の並行鏡で挟み、フラッシュランプやレーザーダイオードなどで励起する。固体レーザーはパルス動作するものが多いが、YAGやYVO@<sub>{4}など、一部のレーザー結晶は連続励起でCW動作させることもできる。また近年母材をガラスとしたレーザーロッドも作製されており、一般のレーザー結晶よりも光学的に均一なレーザーロッドを簡単に作ることができるというメリットがある。また活性原子イオンのドープ(添加)量を比較的自由に選択することができるので、高ドープロッドを作成することができる。さらに2種類以上の活性原子イオンをドープしたコドープレーザーロッドなども容易に作成することができる。

またレーザー結晶をロッド形状ではなく薄いディスクの形とし、結晶内部に熱が蓄積しないように設計したThin Disk Laserも実用化されている。また近年のレーザーダイオードの低価格化、高性能化に伴い、DPSSLと呼ばれる小型・安価なレーザーが多数市販されるようになっている。Diode	Pumped Solid State Laserの略で、レーザー結晶をレーザーダイオードで励起する構成となっている。レーザーダイオードは小型かつ高効率であるので、小型のレーザー光源として使用することが可能となる。排熱も小さいので完全空冷動作が可能となっている例が多く、出力の割に電源装置も小型であったり、バッテリー駆動が可能となっている製品も多い。動作波長は、Nd:YAGなどの第2高調波である532nmの製品が多い。通常、中心波長808nm動作のレーザーダイオードをポンプ光とし、Nd:YAGやNd:YVO@<sub>{4}などのレーザー結晶とKTPやLBOなどの非線形結晶を組み合わせた活性媒質からなる。なおDPSSL用の結晶は一体型かつ両端面にコーティングを行い、それ自体で共振器を構成することにより光学アライメントのコストを低減することができる。出力は数mW～数W程度である。また、グリーンレーザーポインターとして非常に安価な製品も市販されている。ただし、安価な製品には出力が不安定なものが含まれることがある。またDPSSL励起用のレーザーダイオードは、ある程度のパワーがあればその品質はあまり問われないため非常に安価なものが手に入りやすい。

=== 気体レーザー
気体レーザーは、その名の通り気体を活性媒質とするレーザーである。最初に連続発振したレーザーはHe-Neレーザーであり、ヘリウムとネオンの混合ガス中での放電により1.15@<m>{\mu}mの発振線を持つ。今日では気体レーザーの種類は増え、数千本の発振線が知られている。気体レーザーには中性原子レーザー、分子レーザー、エキシマレーザー、イオンレーザーなどがある。励起方法にも放電励起、光励起、電子ビーム励起などがある。放電励起の方法にも直流放電、高周波放電、パルス放電などがある。

=== 分子レーザー(ガスレーザー)
分子レーザーとは、固体レーザーのように原子における電子遷移を用いるのではなく、ガス分子の振動及び回転のエネルギーを用い発振する。振動及び回転のエネルギーは多数の準位を持ち、紫外から赤外までをカバーする。レーザー媒質になる気体分子の数はもちろん多いが、その中でも特に実用的ないくつかに絞って説明する。

==== He-Neレーザー

最も代表的な中性気体原子レーザーはHe-Neレーザーであって、波長633nmの赤色で発振するガスレーザーである。出力は比較的小さく、50mW程度が上限である場合が多い。ガス管の中に75%以上のHeガスと15%未満のNeガスが封入されており、放電励起を行う。放電のエネルギーはHe原子が受け取り、衝突によりNe原子に渡され、反転分布が生じる。定常発振時には極めて安定であるとともに、良質なガウスビームが得られることも知られている。歴史的には、1960年にBell研究所のJavan、Bennet 及び Herriott の三人により開発された当時のHe-Neレーザーの発振波長は1152nmだったが、1962年にWhiteとRigdenにより632.8nm の赤色発振への遷移が達成されてからはこの波長が最も一般的である。その後、外部共振器型He-Neレーザーとヨウ素吸収セルを組み合わせたヨウ素安定化He-Neレーザーの開発により、標準光源として利用されるほどの安定性を有する。

==== N@<sub>{2}レーザー
短パルス放電励起により337nmの紫外域でパルス発振する。通常数nsのパルスが得られ、10MW以上の出力が得られる。電源には40kV程度の高圧電源が必要であるが、それ以外の構成は比較的簡単である。
 
==== CO@<sub>{2}レーザー
10.6@<m>{\mu}m などの波長で発振する。CO@<sub>{2}と N@<sub>{2}の混合ガス中での放電を行う。N@<sub>{2}の振動準位と CO@<sub>{2}の振動順位が非常に近接していることから、CO@<sub>{2}分子に効率的にエネルギーが伝達され、高出力が得られる。連続発振でkW以上の出力が得られ、レーザー溶接などにも使用される。複数の振動回転準位が近接しているので、単一波長で動作させるため回折格子を組み込んだレーザー共振器を使うのが普通である。ガスの圧力や励起方向でいくつかの種類に分類される。普通の連続発振の CO@<sub>{2}レーザーは全圧力 10@<sup>{2}～10@<sup>{3}Paで直流放電を用いて励起したものであるが、大気圧に近い 10@<sup>{4}～10@<sup>{5}Paという大気圧に近い圧力で多数の電極を用いて全域をパルス励起することで、巨大なパルス出力を持つレーザーができる。これを横励起大気圧レーザー(TEA レーザー)と呼ぶ。なお先に CO@<sub>{2}とN@<sub>{2}の振動準位が近接していると述べたが、これが地球温暖化のメカニズムの一部でもある。大気中の CO@<sub>{2}が赤外線を吸収し、そのエネルギーをN@<sub>{2}分子に与えることで、大気全体の温度が上昇するというメカニズムによる。

また、光励起遠赤外レーザーは、分子の共鳴吸収波長をCO@<sub>{2}レーザーで励起して遠赤外線を発振するものであり、遠赤外線の研究用に重用されている。レーザー媒質としては、CH@<sub>{3}OHやHCOOHといった有機分子を用いる。このあたりの波長は有機分子のセンシングなどに利用でき、メーザーの波長帯域にも含まれる。

光励起遠赤外レーザーと発生原理は異なる場合が多いが、レーザーを用いて発生させた周波数1THz前後の電磁波はテラヘルツ波と呼ばれ、様々な応用に向け再び注目を浴びている。

=== エキシマレーザー
エキシマーとは、基底状態では不安定分子であるが電子励起状態では安定になる二原子分子のことを呼ぶ。希ガスである Xe や Kr、Ar がそれぞれ Xe@<sub>{2}(173nm)、Kr@<sub>{2}(146nm)、Ar@<sub>{2}(126nm)となり発振する。カッコ内の値は発振波長であり、いずれも真空紫外域である。ただし普通エキシマレーザーと言った場合は希ガスハライドエキシマレーザーのことを指し、希ガスエキシマーより高い性能が得られている。希ガスハライドとは、ハロゲン化された希ガスという意味で、XeCl(308nm)、KrF(248nm)、ArF(193nm)などのことを言う。異種原子のエキシマーは、ヘテロエキシマーやエキサイプレックスとも呼ばれ、数nsのパルス幅で GW以上のピーク出力がある。

===	色素レーザー・液体レーザー
有機蛍光色素の蛍光を用いるレーザーである。特にレーザー色素と呼ばれる色素は効率が高く蛍光が強い。また蛍光スペクトルが広く、回折格子やプリズムなどと組み合わせて波長可変レーザーとして利用される。また、広い蛍光スペクトルを利用してモードロックをかけることで超短パルス発生が可能という特徴がある。一般に有機色素は有機溶媒によく溶け、溶液の状態で使用する場合が多いため、液体レーザーとも呼ぶ。ただし色素が分解されて退色(photo bleaching)するため、一般に低繰り返しにて動作させる場合が多い。蛍光色素を溶かした有機溶媒を環流させることで、退色を防ぎながら連続的に動作させるといった工夫がなされている場合もある。ローダミンやクマリンといった有名な色素があり、色素を変えることにより発振波長を変化させることができる。さらにその誘導体により蛍光波長が変化するため、可視域全域をカバーすることができる。励起にはフラッシュランプやN@<sub>{2}レーザー、YAGレーザーの第二高調波など、可視光のパルスレーザーが利用される。色素レーザーのパルス発振は簡単である一方、CW動作のできる色素の種類はかなり少ない。
 
=== 半導体レーザー
半導体レーザーの特徴は、pn接合への電流注入によって発振すること、デバイスの大きさが極めて小さいことである。もちろん光励起や電子ビーム励起でも発振するが、あまり一般的とは言えない。半導体レーザーは1957年に提案され、1962年に低温でのパルス発振が確認され、1970年に室温での連続発振が実現された。

半導体のエネルギー準位は、禁制帯(Band gap)を挟んで上に伝導帯、下に荷電子帯がある。半導体は伝導帯にはほとんど電子がなく、荷電子帯はほとんど完全に充満している。そのため、電流のキャリアとなる電子も正孔もほとんど存在しないことから、電流はほとんど流れない。不純物をドープすることで、電子が伝導帯に多数存在する状態とした半導体をn型半導体と呼び、他方電子が不純物準位にトラップされることで多数の正孔が存在する状態となっている半導体をp型半導体と呼ぶ。いずれも比較的電流は流れやすい。

さてp型半導体ととn型半導体を接合したものをpn接合と呼び、整流作用をもつ。この素子をダイオードと呼ぶが、n型のほうを正に、p型のほうを負極としたときには電流がほとんど流れないが、逆にp型のほうを正極としたときには電流がよく流れる。このとき、p型半導体の正孔がn型層に流れ込み、n層の電子がp層に流入し、pn接合面で再結合する。電子と正孔が再結合するときに、フォノンと光子を放出する半導体を間接遷移半導体、光子だけを放出する半導体を直接遷移半導体と呼ぶ。なおこのとき放出される光子のエネルギーは禁制帯幅に一致する。化学組成比や温度変化によりバンドギャップが変化するので、それにともなって発振波長は変化する。

半導体レーザーは、直接遷移半導体のpn接合面に垂直な両端面をへき開により並行平面とし、レーザー共振器を構成する。GaAsの場合は活性層における電流密度が数十kA/cm@<sup>{2}、液体窒素温度では1kA/cm@<sup>{2}程度を閾値として、およそ850nmの発振が起こる。半導体レーザーの出力光は、5°～30°程度の広がり角を持つ場合があり、指向性は低い。活性層の厚さは通常2～20μm程度であるので、回折により広がってしまうためである。注入電流と光強度には閾値があり、閾値電流以下ではLEDと同等の弱くてスペクトル幅の広い発光が起こるが、閾値を超えたところでスペクトルが狭く、指向性の高いレーザー光が出る。閾値電流以上では、電流と光出力は概ね比例する。

初期の半導体レーザーはpn接合だけからなるホモ接合であったが、現在では2種類の半導体でヘテロ接合を作ったり、多重量子井戸構造をとる場合が多い。先ほどのGaAsでは Al@<sub>{x}Ga@<sub>{1?x}As などを使うことでヘテロ接合を作る。AlGaAsはGaAsと比較してバンドギャップが広く屈折率が小さいので、GaAs層に光が集まり、電子と正孔がバンドギャップの狭いGaAsの側に集中する。そこでGaAsの活性層をp型およびn型のAlGaAsで挟むことで、キャリアと光のとじこめを強くすることができ効率が上がる。このようなpn接合をダブルヘテロ接合と呼び、活性層での電流密度を下げることができる。電流密度が下がると発熱が低下するので、冷却なしでもCW動作の半導体レーザーを作成することができる。また半導体レーザーを積層することで数W～数100Wにいたる大きな出力を持つレーザーダイオードアレイ/バーを作成することができる。最近の市販品で光出力効率は数10%程度である。注入エネルギーの残りは熱になり、非常に微小な半導体レーザーの活性領域に集中するため、レーザダイオードは熱設計を厳重に行う必要がある。

なお、半導体レーザーの注入電流を高速変調することにより、高速のパルス動作を行うことができる。また、直接ピコ秒の発振ができる半導体レーザーも市販されている。
 
=== その他のレーザー
その他のレーザーとして、コヒーレントな光を発するものの誘導放出による増幅過程を経ないものもある。誘導放出を経ないため、厳密にはレーザーと呼べないが、コヒーレント光の発生という意味で、レーザーと呼ぶことが多い。ここでは、ラマンレーザーと自由電子レーザーについて述べる。

ラマンレーザーとは、物質の誘導ラマン散乱を利用して入射レーザー光の波長変換を行うものである。これに類似する現象として、非線形光学結晶による光パラメトリック発振という現象がある。ある周波数@<m>{\nu_p}のレーザー光を入射した時、シグナル光@<m>{\nu_s}とアイドラー光@<m>{\nu_i}が、@<m>{\nu_p=\nu_s+\nu_i} となる関係を満たすように生じ、適当な共振器を用いることでそれを増幅することができる。

また、自由電子レーザー(FEL:Free Electron Laser)は、高速の電子ビームを空間変調した静磁場や高周波電磁波中を通すことによって変調し、チェレンコフ効果によってコヒーレント光を発生するものである。X 線から中赤外を含む幅広い波長可変光源として利用され、フェムト秒パルスの発生が可能であることから、バイオ領域を含む様々な領域、特にポストゲノムとして重要視されている糖鎖解析などに利用されている。また、SACLA@<fn>{sacla}という名前のX線自由電子レーザーがSPring8に隣接している。

//footnote[sacla][SPring-8 Angstrom Compact Free Electron Laser http://xfel.riken.jp/sacla/index00.html]

== レーザーの原理
ここまで様々なレーザーのレーザー媒質、すなわち光を増幅する媒質部分の種類や特徴について述べてきた。次にレーザーの原理であるところの光の増幅について、理論的な部分を概説する。まずは光と物質の相互作用について説明する。ついで自然放出と誘導放出について説明し、反転分布とレーザー共振器について説明する。

=== 光の吸収と放出
ある原子が二つのエネルギー準位、W@<sub>{U}と W@<sub>{L}の間を遷移するとき、上の準位 W@<sub>{U} にある原子は光子を放出し、下の準位 W@<sub>{L}にある原子は光を吸収する。このとき、吸収・放出する光のエネルギーは、

//texequation{
h\nu=W_{U}-W_{L}
//}

//noindent
なる関係を満たす。なお、ここでは「原子」と言った場合、原子だけでなく、分子、イオン、ラジカルなども含めて、エネルギー遷移をとりうるものを代表して言っている。

さて、下の準位にある原子による光の吸収は入射光の強さに比例する。これに対して、上の準位にある原子からの光の放出は入射光がなくても起こり、これを自然放出(spontaneous emission)と呼ぶ。一方で、入射光があったときにその入射光に刺激されて放射をおこすことを、誘導放出(stimulated emission)と呼ぶ。誘導放出は入射光の強さに比例して起こる。自然放出の確率をAとすると、入射光@<m>{W(\omega)}があるときに上の準位にある原子が光を放出する確率pは@<m>{p=A_{UL\}+B_{UL\}W(\omega)}となる。また、下の準位にある原子が光を吸収する確率は、@<m>{p = B_{LU\} W (ω) }となるので、あるひとつの準位のみを考えた場合、@<m>{B_{UL\} = B_{LU\} となる。なおこの関係は、アインシュタインが 1916 年に導いた関係であるので、それぞれアインシュタインの A 係数、B 係数と呼ぶ。

さて、下の準位に@<m>{N_L} の原子があったとした場合、単位時間に吸収する光のエネルギーは

//texequation{
P_{abs}=h\nu B W(\omega)N_L
//}

//noindent
とあらわされる。また、上準位にある@<m>{N_U}個の原子から単位時間に放出される光のエネルギーは、

//texequation{
P_{abs}=h\nu(A+B W(\omega))N_U
//}

//noindent
であらわされる。原子系が熱平衡になっているときは、ボルツマン分布となるので、

//texequation{
N_U=N_L \exp(- \frac{h\nu}{k_B T})
//}

//noindent
となる。


誘導放出と吸収は、媒質の原子が上下の準位に分布する限り同時に起こる。また各準位の間の誘導遷移の確率は、上から下への遷移と、下から上への遷移とで等しい。普通の状態の媒質では下の準位にある原子数が上の準位にある原子数よりも多いので、差し引きでは吸収のほうが強くなる。一方で適当な方法で下準位にある原子数より上準位にある原子数のほうが数が多いという状態を作ってやることができれば、媒質に入射した光は誘導放出によって増幅される。これがレーザー増幅である。

===	反転分布
熱平衡状態では常に@<m>{N_L > N_U}となるが、逆に@<m>{N_U > N_L}となる状態を反転分布と呼ぶ。この状態をボルツマン分布の式にあてはめて温度の解を求めてみると、温度Tが負の値をとる。したがって、反転分布は負温度であるということができるが、もちろん熱力学的な温度ではなく、反転分布強度のパラメータを表すにすぎない。

反転分布を作るためには、媒質に適当な方法でエネルギーを与えて原子を励起し、下の準位にある原子数@<m>{N_L}を減らし、上の準位にある原子数@<m>{N_U}増やすことが必要である。これは下の準位から上の準位へ原子をくみ上げることだと考え、ポンピング (pumping)と呼ぶ。ポンピングには光で励起する光励起のほかに、ガスレーザーで主に用いられるように放電による励起、半導体レーザーのように電流注入でキャリアを注入する励起方法があり、ほかにも電子線による励起や化学反応を用いるなど、いろいろな方法がある。

しかし反転分布を作ることは原理的に不可能であると考えられていた。なぜならある二つの準位を考えた場合、光の周波数に対しては @<m>{h \nu \gg k_B T}であるので@<m>{N_U}が非常に小さい値となる。最初のうちは上の準位の原子は増えていくが、それにつれて上の準位にせっかく励起した原子が下の準位に遷移する確率が増えるため、どれだけ強く励起しても反転分布は得られない。

当初マイクロ波波長においてメーザーが確立した理由は、下準位から上準位にポンプするのではなく、下準位にある原子数を減らすことができたからである。すなわち、マイクロ波周波数においては @<m>{h \nu \ll k_B T}であるので、@<m>{N_U}と@<m>{N_L}の数は非常に近い値となる。したがって熱平衡の分子集団のある二つの準位において、下の準位の分子を除去し、上の準位の分子を集めることで反転分布を作った。

一方レーザーにおいては、原子の3つの準位または4つの準位を利用してポンピングを行い、反転分布を作る。用いるエネルギー準位が必ずしも離散的な準位ではなく、バンドの場合もある。したがってバンド準位を取る色素レーザーや半導体レーザーは、4準位系のレーザーであるといえる。

===	3 準位レーザーの反転分布
3準位レーザーは、ルビーレーザーや光励起気体レーザーが相当する。本節では、3準位レーザーの原理を述べる。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/img2.png}
\caption{3準位系レーザーの準位の模式図}
\end{figure}
//}


図に、3準位系のレーザー準位の模式図を示す。ここでレーザー作用をする3つの準位を考える。それぞれのエネルギーを@<m>{W_1}、@<m>{W_2}、@<m>{W_3} とし、原子数を@<m>{N_1}、@<m>{N_2}、@<m>{N_3} とする。@<m>{W_3 > W_2 > W_1}とすると、熱平衡状態では @<m>{N_1 > N_2 > N_3}である。ただし @<m>{W_1} は必ずしも基底状態であるとは限らない。さてここで@<m>{W_1} の原子をポンピングし、@<m>{W_3}に励起するとする。励起方法は何でもかまわないので、とりあえず何らかの方法で@<m>{W_1}の原子を@<m>{W_3}に確率@<m>{\Gamma}でポンピングしたとする。

励起された原子は励起を止めると次第に熱平衡状態に戻る。これを緩和 (relaxation) と呼ぶ。全体としては励起されていても、個々の原子を見ると、常に緩和過程は起こっている。緩和過程には、励起状態の原子が光を放出してエネルギーの低い準位に移る放射過程と、光を放射せず、分子衝突や格子振動などにエネルギーを移しエネルギーの低い状態に遷移する無放射過程がある。緩和はこの両者の統計的過程を経るので、励起原子が単位時間に緩和する割合の統計平均を考え、それを緩和速度あるいは緩和定数と呼ぶ。緩和速度の逆数は励起原子の平均寿命を表し、励起原子が発する蛍光の減衰時間に一致するので、蛍光寿命と呼ぶこともある。


さて、レーザー媒質の温度を@<m>{T}とすれば、エネルギーの低い@<m>{W_L}の準位からエネルギーの高い@<m>{W_U}の準位に熱的に励起される確率と、その逆に@<m>{W_U}から@<m>{W_L}に熱的に緩和される確率は等しく、次のような関係がある。


//texequation{
N_U \gamma_{UL}=N_L \gamma_{LU}
//}


//texequation{
N_U=N_L \exp(- \frac{W_U-W_L}{k_B T})
//}

//noindent
であるから、
 
//texequation{
\frac{\gamma_{LU}}{\gamma_{UL}}=\exp(- \frac{W_U-W_L}{k_B T})
//}


//noindent 
となる。この関係は、熱平衡状態でなくても一般になりたつ。  さてこれらの確率がポンピングやレーザー発振の過程で一定であると仮定した上で、それぞれの準位にある原子数の増減の時間変化を表す式として、レート方程式を立てる。


//texequation{
\frac{d N_1}{dt}=-(\Gamma + \gamma_{12}+\gamma_{13})N_1+\gamma_{21} N_2 + \gamma_{21}N_2
//}

//texequation{
\frac{d N_2}{dt}=\gamma_{12}N_1-(\gamma_{21}+\gamma_{23})N_2+\gamma_{32}N_3
//}


//texequation{
\frac{d N_3}{dt}=(\Gamma+\gamma_{13})N_1+\gamma_{23}N_2-(\gamma_{31}+\gamma_{32})N_3
//}

//noindent
となる。ここで、@<m>{N_1+N_2+N_3=N=const}であって、@<m>{N}は系の原子の総数を表す。
定常状態を考え、各原子の準位の変化がつりあっているので各辺の左辺を0とおいて、定常ポンピングされているときの原子数を求める。ここでは数式の簡略化のため、それぞれの準位の間隔が熱エネルギー@<m>{k_BT}よりも十分大きいとし、熱的に励起されることで遷移することがないと仮定した。したがって、@<m>{\gamma_{12\}}、@<m>{\gamma_{13\}}、@<m>{\gamma_{23\}}を無視することができ、定常解として、

//texequation{
N_1=\frac{\gamma_{21}(\gamma_{31}+\gamma_{32})}{\gamma_{21}(\gamma_{31}+\gamma_{32})+(\gamma_{21}+\gamma_{32}) \Gamma}N
//}

//texequation{
N_2=\frac{\gamma_{32}\Gamma}{\gamma_{21}(\gamma_{31}+\gamma_{32})+(\gamma_{21}+\gamma_{32}) \Gamma}N
//}

となる。ここで@<m>{N_2 > N_1} となるためには、

//texequation{
\Gamma>\gamma_{21}(1+\frac{\gamma_{31}}{\gamma_{32}})
//}

//noindent 
が必要となる。なるべく弱い励起で反転分布を作るためには、@<m>{\gamma_{21\}}が小さいほどよく、また @<m>{\gamma_{32\}}は@<m>{\gamma_{31\}}より大きいことが必要となる。すなわち、レーザー遷移の上準位から下準位への緩和が遅いこと、最初に励起される準位3からレーザー準位の上準位2への緩和が早いことが望ましい。

===	4 準位レーザーの反転分布
3準位系レーザーではレーザー遷移の下準位がもっともエネルギーが低いので、熱平衡状態では大部分の原子がこの準位にあり、反転分布を起こすには下準位を半分以下にしなければならない。そこでより簡単に反転分布を作ることができるのが4準位レーザーである。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/img3.png}
\caption{4準位系レーザーの準位の模式図}
\end{figure}
//}

エネルギー準位図を図1.3に示す。このような4つの準位を持つ原子を考え、準位0から準位3へ励起し、準位2と準位1の間に反転分布を作る場合を考える。なおこのとき、レーザー遷移の下準位1と、基底準位0の間は、熱エネルギー@<m>{k_BT}よりも大きいとする。この間隔が熱エネルギーより大きいことで、熱的に下準位1に励起される原子が少なくなるので、少数の原子のポンピングにより反転分布が作られる。先ほどと同様の手順でレート方程式を立て、定常状態の解を求め、そこから反転分布条件を求める。


//texequation{
\frac{d N_1}{dt}=\gamma_{01}N_0-\gamma_{10}N_1+\gamma_{21} N_2 + \gamma_{31}N_3
//}

//texequation{
\frac{d N_2}{dt}=-(\gamma_{20}+\gamma_{21})N_2+\gamma_{32}N_3
//}


//texequation{
\frac{d N_3}{dt}=\Gamma N_0-(\gamma_{30}+\gamma_{31}+\gamma_{32})N_3
//}

//texequation{
-\frac{dN_0}{dt}=\frac{dN_1}{dt}+\frac{dN_2}{dt}+\frac{dN_3}{dt}
//}

//noindent
なお、各準位の間隔は熱エネルギーより十分に大きいとしたので、準位1と準位2、準位1と準位3の間の熱による励起は無視した。ただし、基底準位0からレーザーの下準位1への熱による励起のみ考慮に入れた。ここから、定常解を求めると、

//texequation{
N_1=(\frac{\gamma_{01}}{\gamma_{10}}+\frac{\gamma_{21}\gamma_{32}+\gamma_2\gamma_{31}}{\gamma_{10}\gamma_{2}\gamma_3}\Gamma)N_0
//}

//texequation{
N_2=\frac{\gamma_{32}\Gamma}{\gamma_2\gamma_3}N_0
//}

//texequation{
N_3=\frac{\Gamma}{\gamma_3}N_0
//}

なお、式の簡単のため、@<m>{\gamma_3 = \gamma_{30\}+\gamma_{31\} + \gamma_{32\}}および @<m>{\gamma_2 = \gamma_{20\}+\gamma_{21\}}とおいた。さらに ここから反転分布を与える条件を求めると、

//texequation{
\Gamma>\frac{\gamma_{01}\gamma_2 \gamma_3}{\gamma_{32}\gamma_{10}-\gamma_{21}\gamma_{32}-\gamma_2\gamma_{31}}
//}

//noindent
である。

@<m>{\gamma_{01\}}は基底準位から準位1への熱的励起過程であり、@<m>{\gamma_{01\} = \gamma_{10\} \exp(-\frac{W_1\}{k_BT\})}であるので、非常に小さい値である。したがって反転分布を作るのに必要な励起の強度が小さい値になる。ここで、@<m>{\gamma_{01\}\gg\gamma_2}であると仮定する。すなわち、準位2の寿命が十分に長いと仮定した場合、近似的に

//texequation{
\Gamma>\frac{\gamma_{01}\gamma_2 \gamma_3}{\gamma_{32}\gamma_{10}}=\exp(-\frac{W_1}{k_BT})\gamma_2(1+\frac{\gamma_{31}+\gamma_{30}}{\gamma_{32}})
//}

//noindent
とあらわされる。ここで重要なのは@<m>{\exp(-\frac{W_1\}{k_BT\})}での項であり、準位1が基底準位より@<m>{k_BT}以上高
い準位にあれば、きわめて弱いポンピングでも反転分布を作り出すことができる。

=== レーザー増幅
媒質に反転分布を作ったときの光の増幅の様子について考える。吸収のある厚さ z の媒質において、Lambert-Beer の法則から、光の吸収を@<m>{I=I_0\exp(-\alpha z)}と表すことができる。ここで、@<m>{\alpha} は単位長さあたりの吸収の大きさである。さて反転分布の媒質中では、光が進むにしたがって増幅される。このとき @<m>{\alpha < 0} となる。パワーの増幅を@<m>{\exp(Gz)} と書くとすると、長さzの媒質によるパワーの増幅度、すなわち利得となる。そこでGを利得定数という。なお、G/2 を電界の増幅定数と呼ぶ。反転分布が@<m>{N = N_2 - N_1} となっている媒質においては、利得定数が

//texequation{
G=\Delta N\frac{\hbar\nu}{c}B(\omega)
//}
 
//noindent
となる。この B はアインシュタインの B 係数である。

=== レーザー発振の条件
増幅器に正のフィードバックをかけると、増幅により信号がだんだんと大きくなる。ある周波数において増幅率 A を持つ増幅器にフィードバックをかけたときを考える。出力電圧は

//texequation{
V_O=A(V_I+\beta V_O)
//}

//noindent
となり、フィードバック増幅器の増幅率は、

//texequation{
\frac{V_O}{V_I}=\frac{A}{1-\beta A}
//}
 
//noindent
と書ける。入出力電圧は交流であるので A も β も一般に複素数であり、位相の変化を含む。話の簡単のため、@<m>{A} も@<m>{\beta}も実数であり位相の変化がないものとする。@<m>{\beta A > 0}で正のフィードバックとなり、出力電圧はフィードバックがないときより大きくなる。@<m>{\beta A = 1}となったとき、増幅率は無限大となる。実験的には入力がなくても、ノイズなどを増幅しある周波数で発振する。

実際には増幅率もフィードバック係数も周波数特性を持つので、@<m>{\beta A}が最大となる周波数で発振が起こる。発振して振幅が大きくなると、増幅器の非線形特性が現れてきて増幅率が低下し、また周波数特性が変化する。そのため発振振幅は最初指数関数的に立ち上がったあと、次第に振幅の増加が飽和し、周波数も多少変化する。やがて@<m>{\beta A = 1}となるような振幅と周波数に達したときに安定した発振が続く。ただし、いつも一定振幅の発振になるとは限らず、振幅や周波数が周期的に変動するような発振状態となることがある。この状態を緩和発振と呼び、実際のレーザーの発振においても頻繁に見られる現象である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/img1.png}
\caption{レーザーの模式図}
\end{figure}
//}

それでは、レーザー共振器における発振を考える。図 1.4 に再度レーザー共振器の模式図を示す。2枚のミラー、Mirror1と Mirror2の間に長さL、利得定数Gの反転分布を持つレーザー媒質があるとする。反射鏡のパワー反射率を@<m>{R_1}と@<m>{R_2}とする。光が2枚の鏡の間を1往復するときレーザー媒質を2回通過するので、往復の振幅増幅率をAとすると往復の利得は

//texequation{
A^2=\exp(2GL)
//}

//noindent
となる。増幅出力振幅の@<m>{\sqrt{R_1R_2\}}倍がフィードバックされるので、
 
//texequation{
\beta = \sqrt{R_1 R_2} e^{i \theta}
//}
 
//noindent
となる。@<m>{e^{i\theta\}}は、フィードバックされる光の位相と入射光の位相が大きく変化しうるため、位相項が無視できないからである。しかし位相が変化すると干渉して発振が起こらない。したがって、レーザー発振はこの位相変化が起こらないような周波数で発振が起こる。そこで@<m>{\theta=0}とおいて、発振条件である@<m>{\beta A = 1}に代入すると、

//texequation{
GL>-\frac{1}{2}\ln (R_1 R_2)
//}

//noindent
となる。実際のレーザー媒質においてはほかにも損失要因がいろいろあるため、反射鏡以外の損失をすべてひとまとめとして実効的なロス@<m>{L_{eff\}}として導入する。一往復でパワーがK倍になるとして、

//texequation{
L_{eff}=-\frac{1}{2L}\ln K
//}

//noindent
を用いる。したがってレーザー発振の条件は、

//texequation{
(G-L_{eff})L+\frac{1}{2}\ln R_1 R_2 =0
//}
 

//noindent
または
 
//texequation{
G=\frac{1}{2L}|\ln R_1 R_2| + L_{eff}
//}

//noindent
とあらわされる。これらの式で @<m>{R_1 < 1},@<m>{R_2 < 1}は自明であるので@<m>{\ln R_1 R_2 < 0} である。すなわちその絶対値が小さいほど小さな利得でレーザー発振が可能となる。そこでなるべく反射率が 1 に近いほうがよい。ミラーの反射率がともに 1 に近い状況を近似し、式を書き換えることにより、
 
//texequation{
G=\frac{1-R_1 R_2}{2L}+L_{eff}
//}

//noindent
となる。左辺は利得 G、右辺は系の損失を表すので、利得と損失がつりあうところで発振が起こることを示している。

利得が損失より小さければ、共振器内の光電場は急速に減衰する。逆に利得が損失より大きければ、自然放出光が種光となり、指数関数的に発振が立ち上がる、このときの増加率は利得と損失の差で与えられる。光電場が強くなるにつれて、レーザー媒質の上準位の原子数が減少し、利得が小さくなる。一方損失は光の強さにほとんど依存しないため、光の強さが増すにつれて利得と損失の差が減少し、増幅率は小さくなり、最終的には利得と損失がつりあう。この点がレーザー発振開始のための利得定数の閾値を与え、同時に定常発振時の値を示す。以上がレーザー発振に関しての理論の基本的な部分となる。

過渡特性や発振モード、Qスイッチやモード同期など、レーザーに関する様々な現象、理論は多数あるが、レーザーがどんなもので、どういう理論が背景にあるかを理解するため、まずはレーザー発振の範囲について簡単に述べた。より詳細な内容については、レーザーに関する教科書はたくさんあるのでそちらを参照されたい@<fn>{laserbook}。これらの本には、パルス発振や高出力化など、よりダイナミックな現象についても様々書いてあるので、おもしろいよ！

//footnote[laserbook][たとえば、レーザー物理入門や YARIV の Quantum Electronics などが古典中の古典になるか。ところで、AMNON YARIV “QUANTUM ELECTRONICS” 3rd Ed の全文（700P 弱）が Web 上に公開されていた。驚いた。違法なやつじゃないよね？同タイトルで検索すると、2 番めに出てくる。(2015年頃の話)]

== レーザーの実際
ここまででレーザーの理論の基本的な部分をなぞり、レーザーが発振するところまできた。ここからは、市販のレーザーを分解して、レーザーの構造を確認する。用いたのは発振波長532nmのグリーンDPSSLである。比較的安価かつコンパクトであり、基本的にメンテナンスフリーなため様々な分野で利用されている。

本節では、市販のDPSSLについて、どのような動作をするのか、あるいは中身がどうなっているのかについて確認する。

===	DPSSL の動作例
今回動作状況の確認および分解をするDPSSはAOTKの製品である。AOTK は、Abal	OptoTek の略であり、中国の厦門にある会社である。Web によると結晶も自社製作しているようで、自社の結晶を組み上げてこのような DPSSL として販売している。国内での取扱いメーカーは、Broadband	INC であり、勝手な印象ではあるが、国内のレーザー関係の商社としては中堅どころと考える。Broadband は、いろいろおもしろいモノを売っているので、時々チェックすると幸せになれる。さて、AOTK は結晶などにおいてはそれなりに実績のあるメーカーのようであり、最近レーザ関係の中国メーカーが増えているので、安くなることはいいことだと感じる。

ヘッドと付属のDPSSL DRIVERの写真を示す。DPSSL ドライバーの外観はシンプルな作りで、前面には電流調整つまみと、スイッチのみがある。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/image42.png}
\caption{レーザーのヘッドの外観}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/image41.png}
\caption{レーザードライバの外観}
\end{figure}
//}

レーザヘッドのサイズは 145×95×45mm@<sup>{3}と手のひらサイズである。ユニットとの接続は 7ピンのケーブルであり、中でレーザモジュールとつながっているのは6芯である。円筒形のレーザモジュールは二つに分かれて、前にはコリメートレンズが入っている。コリメートレンズを取り外すと、ビームの広がり角がかなり大きくなる。レーザーモジュールの中身を示す。レーザモジュールの直径はおよそ 25mm、長さがおよそ 40mm である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/image43.png}
\caption{レーザーモジュールの中身}
\end{figure}
//}


次に、このレーザモジュールの評価を行う。まずはグリーンレーザのパワーを測定した。DPSSL ドライバの電源を入れ、つまみを回す。しばらくはレーザ光は出てこない。LD のドライブ電流が 300mA を越えたあたりで、目視で確認可能なグリーンの発振が始まる。最大電流値は、このドライバでは 784mA であり、このときのグリーンレーザのパワーは最大で 8mW 程度であった。ただし、使用したパワーメータが大出力用 (10W まで計測可能なもの) であり、精度は不十分である。

ついでビームプロファイラを用いてビームプロファイルを測定した。なおビームプロファイルとは空間的な強度分布やビーム径など、そのビームの振る舞いをあらわすレーザ特性である。同じ強度、おなじビーム径を持つビームでも、ビームプロファイルが異なれば集光特性は異なる。CCD や CMOS などのカメラ素子を用いたビームプロファイラは一般に低出力向けではあるが比較的安価に購入できるし、実質的には自作も可能であろう。ただし、可視化は出来ても、自動でフィッティングをするなどの機能は追加する必要がある。ビームプロファイルを測定したところ、ガウシアン近似で1.9mm*2.4mm であることがわかった。ビーム品質としては、ほぼガウシアンといっていいかと考えられる。ビームプロファイルの測定結果を以下に示す。

//embed{
\begin{figure}[h]
\centering
\includegraphics{images/chap1/image44.png}
\caption{DPSSのビームプロファイル測定例}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics{images/chap1/image45.png}
\caption{DPSSのビームプロファイル測定例(数値編)}
\end{figure}
//}



===	レーザヘッドの分解
次に、レーザヘッドの分解を行う。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/image46.jpeg}
\caption{レーザーヘッドの中身}
\end{figure}
//}

まずは外装ケースを外した写真である。アルミのブロックに、ペルチェ素子、スペーサープレート、レーザダイオード、レーザ結晶をマウントした筒という順番である。ねじ止めしてあるので、まずはそれをはずす。 6ピンのケーブルの内訳は以下のとおり。

 * LD のドライブ用ケーブル
 * LD   冷却用ペルチェ素子のドライブ用ケーブル
 * 温度センサの信号ケーブル

//noindent
以上 3 対 6 本であった。分解したところの写真のとおり。大きい球( 黄土色) はノイズフィルタのコンデンサであり、温度センサは小さい白い玉である。LD と結晶は接着剤で一体化しており、ユーザ調整は不可能である。ペルチェと温度センサは大量のシリコングリスを塗布してあった。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/image47.jpeg}
\caption{レーザーヘッドを分解したところ}
\end{figure}
//}



一般論ではあるがレーザダイオードは非常に熱に敏感であり、簡単に発振波長が変化したり、出力が変化したりする。温度変動は 10 ℃以内に安定化することが望ましいとされる。ここでレーザダイオードのエネルギー効率をごくごく簡単に見積もってみる。別の LD のスペックシートから引っ張ってくると、500mW の定格動作時で、順方向電流 500mA、順方向電圧 1.8V とある。0.9W の電力入力に対して 0.5W の光が取り出せるのだから出力の効率は 55 ％となり、かなり高効率であると考えられる。しかし同時に 0.4W が熱となる。テストしたレーザヘッドでは 700mA の駆動電流であったので、ここでの廃熱を考えると効率が同じとしても 0.75W 程度の発熱があることになる。先にも述べたが、半導体レーザの素子は非常に小さいため、活性層付近の熱密度は非常に高くなる。そこで大きなヒートシンクですみやかに冷却する必要がある。

さて分解・観察に戻る。次はレーザヘッドをバラす。接着なのではずすのが難しい。1個犠牲にするつもりでモンキレンチとペンチで無理やりひねると外れる。はずしたところを見ると、レーザダイオードがベースプレートにネジ止めされている。レーザ本体は写真に撮るのが難しいほど小さいが、カソードリードと金色のワイヤでボンディングされている。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/image48.jpeg}
\caption{DPSSのレーザーダイオード}
\end{figure}
//}


レーザ結晶は、筒の中にシリコンコーキングのような接着剤で取り付けてある。肉眼では紫色に見える。結晶は 3mm の正方形。穴の直径はおよそ 2mm。取り外すのはかなり困難であると考えられる。レーザ結晶の厚みはおよそ 1mm であり、両端の反射防止膜の状態は不明である。

レーザの動作状態から、Nd:YVO@<sub>{4} の結晶と、非線形結晶が一体化された結晶であると考えられる。またキャビティミラーが個別には存在しないことから、両端コーティングもありと考えられる。したがって、レーザ結晶と非線形結晶が一体化したマイクロチップタイプのレーザ結晶を使っていることとなる。市販品としてNd:YVO@<sub>{4}と KTP 結晶を接着し両端にコーティングを施したコンポジット結晶が存在する。http://www.aotk.com/products-list.asp?id=110 に、Green Laser	Core	(GLC)	という商品名にて存在する。この一覧中のものとは厚みは合わないがいずれにせよ、Nd:YVO@<sub>{4}と KTP 結晶と考えられる。

そこで基本的なレーザ共振器の構成を考えながら本レーザ共振器の構成を推定しておく。まずNd@<sup>{3+} の基本波に対する共振器を構成するため、両端に 1064nm に対する反射コーティングが必要である。次に共振器内に非線形結晶を入れて、第二高調波を発生させる。LD 側への出力はそもそもエネルギー損失であり、かつ直接 LD に戻り光があると動作が不安定になることがあるため発生した第二高調波は LD 側に出てはならない。そこで LD 側には 1064nm と 532nm の HR を、出力側には 1064nm の HR、532 の無反射(AR：Anti efrection Coating) としていると考えられる。また LD 側については、励起波長 (808nm 付近) に対して、透過コーティングとする必要がある。反射が残っていれば、励起効率が低下するのみならず、戻り光のエネルギーで LD が加熱されるためである。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/image49.png}
\caption{DPSSのレーザー結晶の構成(想定)}
\end{figure}
//}


さてここで結晶を確認すると、結晶に傷が入っている事を確認した。せっかくなので結晶を取り外してみることにする。カッターナイフで周りのシリコーンっぽい接着剤をほじくってみる。結局結晶は粉砕に近い状態まで破砕してしまった。当然の結果とも言えるが、結晶を取り出すことは困難であり、やはり結晶はマウントしたまま使うか、新しく購入するしかないようである。

なお本装置では 700mA のドライブ電流から、700mW の LD 出力が出ているという仮定をおくと、8mW 程度の Green 出力が得られていることから、808 → 532 の変換効率は 1% 程度となる。
 
