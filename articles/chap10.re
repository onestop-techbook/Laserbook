= Arduino の環境構築

== Arduino 化の目的
レーザー本総集編においては、描画データの生成をPCで行っていた。動画や任意の画像 を用いて描画するといった事を考えた場合にはPCを利用することは非常に優位性があるが、消費電力が大きいという問題がある。現状描画しているアナログ時計程度のものであれば  計算力も小さいため、Arduino等のマイコンを用いることで大幅に消費電力低減とシステム の簡素化・小型化ができると考えた。そこで現状のパソコン制御をやめてArduinoを用いたデモシステムを制作することにした。

=== 従来システム
従来デモに使用していたノートパソコンはDell Mini9であり、ノートパソコン自体の消費電力は、システム全体としてはおよそ9W(フル充電時、純正AC アダプタ利用での実測値。サンワサプライワットチェッカーによる。) である。

CPUはAtom N270 Diamondville（ダイアモンドビル）1.6GHzの1コア2スレッドで、 CPU単体のTPDは2.5W である。デモ中の描画システム全体の消費電力15W(電源の電流モニタでの読み値。電源電圧を約12.5V、電流読み値約1.2Aから算出)に対して60%が制御用パソコンである状態は著しくバランスを欠くと言わざるを得ない。2014年ごろとしてもすでに割と型落ちではあるが、今となってはロートルにすぎる。

そこで、制御部をArduinoとしたレーザー時計を作ることとする。設計の思想は以下のとおりである。

RTC から時刻を取得し、DA により時計の描画を行う。文字にすれば25 文字であるが、ここから順次実装について述べていく。

== Arduino 事始め

まず購入したのはArduino Uno であり、実施当時のIDE のバージョンは1.6.5 である。秋月で2940 円であった。Lチカまでは非常にスムーズかつ簡単であったことを申し添えておく。ただし、やはりこの手の開発において、L チカの次に何を作るかという問題は非常に重要であり、「何かを作りたいからデバイスを買う」という風にモチベーション付をする必要があり、デバイスを買ってから何を作るか考えるという状態では積んでしまうこと請け合いと考える。さて、Arduino でレーザー時計を実装するためのステップは以下のとおりである。

 * 液晶の取り付け

I2C のテストと、出力結果の確認のため、I2C 接続の小型液晶を付ける。

 * RTC の取り付け

描画する現在時刻の基準として使用する。これもI2C 接続である。
 
 * PWMでアナログ出力をする

オンボードのアナログ出力があるので、これを使う。

 * 平滑化する。

PWMはパルスのDuty比を変化させてアナログ出力するため、平滑化が必要である。

このようにして、実装を進める。秋月でも安価に売っているI@<sup>{2}C 接続の小型液晶を使用して、Arduino にモニタを付ける。液晶画面には、現在時間を表示する。

使用した液晶はAQM0802A-RN-GBW2@<fn>{lcd}である。8 文字× 2 段の小型キャラクタ液晶で、 700円程度と非常に安価である。配線は、電源とGNDとI2Cの2線の合計4線のみ配線すればよく、配線も簡単である。これを用いて、時刻などをもろもろ表示させる。

HaruLabさんのHP@<fn>{harulab}を見ながら実装を進める。まずはライブラリを読み込む。ダウンロードしたライブラリ@<fn>{library} を、マイドキュメント>Arduino>Libraries> に格納する。スケッチ>Include Library で、Arduino_ST7032 が表示されていることを確認する。続いて、配線を行う。配線は、液晶変換モジュール使用前提で、1：3.3V、2：NC、３：A5/SCL、4：A4/SCA、 5:GND となる

図9-1はブレッドボードとジャンパワイヤでとりあえずのテスト実装したところである。 Arduino側はピンソケットになっているので、ジャンパ線を差し込む。液晶側はブレッドボードに差し込み、その隣にジャンパ線を差し込む。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-1.jpg}
\caption{Arduinoを用いた液晶表示テスト}
\end{figure}
//}

//footnote[lcd][http://akizukidenshi.com/catalog/g/gM-09109/（2015.11.23 閲覧）液晶単体なら320 円、ピッチ変換基板セットが600円、組み立て・半田済キットが700円。LCD 本体と変換基板がほぼ同額・・・・・・]
//footnote[harulab][http://harulabo.net/?p=354	AQM0802A をArduino で使ってみる。（2015.11.23 閲覧）]
//footnote[library][http://ore-kb.net/archives/195	オレ工房 電子工作やプログラミングの話題 ( 調整中) I2C 液晶の Arduino ライブラリST7032	（2015.11.23 閲覧）] 

電源を入れれば、指定された文字列が表示される。当然であるが、スケッチの中のPrintの中の文字列を変更することで任意の表示が可能となる。

当初テストした時は全く何も表示されなかったので、ハンダ付けで壊したか？と思ったが、なんのことはない。配線を間違っていただけであった。I2C接続は、操作、実装が非常に簡単になるメリットが有る一方で、電源を入れても、正しい信号を送らないと全く何の表示もなされないから、表示されない場合に故障なのか設定ミスなのか何なのかさっぱりわからないというデメリットある。電源入れたら何かしらパターンでも全点灯して消えるくらいのアクションがあればいいのに・・・と思う。いずれにせよ、配線が汚いとか、そのあたりはご容赦いただくとして、次のテストに進む。

@<list>{code1}に、ストップウォッチ的に、ただ1 秒毎に数字をカウントアップするコードを書いた。次に実装するRTCから時刻を取ってきて表示する前準備として実施した。いずれにせよ、たったこれだけのコードで液晶が使えるのはありがたいことである。

//listnum[code1][I2C接続の液晶の表示サンプル1]{
#include <ST7032.h> 
#include <Wire.h> 
ST7032 lcd;
void setup() {
// put your setup code here, to run once: 
    lcd.begin(8,2);
    lcd.setContrast(30);
    lcd.print("test");
}
void loop() {
// put your main code here, to run repeatedly: 
    lcd.setCursor(0,1);
    lcd.print("1234");
}
//}

//listnum[code2][カウントアップするコード]{
    void loop() {
    // put your main code here, to run repeatedly: delay(1000);
    a++;
       lcd.setCursor(0, 1); lcd.print(a);
}
//}

== RTC の接続
RTC のモジュールとして、RTC-8564NB@<fn>{RTC}を使用した。同時に、電気二重層コンデンサを利用して時間を保持する仕様としている。一旦、時刻設定はSetup内にハードコーディングし、リセット時に設定するものとする。

これも基本的には他の開発例をそのまま実装するだけである。RTC8564 の使い方@<fn>{rtc1} @<fn>{rtc2}を参照しつつ、ライブラリをダウンロード@<fn>{rtcdownload}する。書式が少し変わっているので、Arduino IDE が最近のものならば少し修正が必要である。解凍して、RTC8564.cpp に対して以下の修正を行う。テキストエディタで一括変換したほうが楽かつ漏れがない。

//footnote[RTC][http://akizukidenshi.com/catalog/g/gI-00233/	RTC モジュール 500 円（2015.11.23閲覧）]


//table[RTCrepair][RTC8564を使用するためのRTC8564.cppの修正箇所]{
修正前	修正後	修正箇所の数
----------------------------
#include <WConstats.h>	#include <Arduino.h>	1か所
Wire.send	Wire.write	26か所
Wire.recieve	Wire.read	2か所
//}

あとは、いつもどおりライブラリとして登録するとともに、スケッチを作る。まずは@<list>{code3}に示すようにRTCから時刻を読み取って、シリアルで表示する。読み取りはシリアルモニタを開くことで動作確認できる。シリアルモニタの起動は、ArduinoIDE のツール> シリアルモニタで別ウィンドウが開く。うまく動いていれば、シリアルモニタに1秒毎にRTC の時刻が表示されるはずである。

コード自体は複雑なものではなく、Rtc.available()で現在時刻を取得し、各要素に格納されたものをつなぎあわせてシリアルで表示するという手順を1 秒おきに繰り返すものである。


//footnote[rtc1][http://arms22.blog91.fc2.com/blog-entry-232.html	なんでも作っちゃう、かも。Arduino で遊ぼう- リアルタイムクロック （2015.11.23 閲覧）]
//footnote[rtc2][http://baticadila.dip.jp/arduino_104.htm Arduino で実験（RTCモジュール）（2015.11.23閲覧）]
//footnote[rtcdownload][http://code.google.com/p/arms22/downloads/detail?name=RTC8564-001.zip（2015.11.23 閲覧）]

//listnum[code3][RTCの時刻をシリアルモニタに表示するスケッチ]{ 
#include <RTC8564.h> 
#include <Wire.h> 
void setup()
{
    Serial.begin(9600); Rtc.begin();
}
void loop()
{ 
    delay(1000); 
    Rtc.available();
    Serial.print(0x2000+Rtc.years(),HEX); 
    Serial.print("/"); 
    Serial.print(Rtc.months(),HEX); 
    Serial.print("/"); 
    Serial.print(Rtc.days(),HEX); 
    Serial.print(" "); 
    Serial.print(Rtc.hours(),HEX); 
    Serial.print(":"); 
    Serial.print(Rtc.minutes(),HEX); 
    Serial.print(":"); 
    Serial.println(Rtc.seconds(),HEX);
}
//}

//listnum[code4][時刻を液晶モニタに表示するスケッチ]{
#include <ST7032.h> 
#include <RTC8564.h> 
#include <Wire.h> 
ST7032 lcd;
void setup()
{
    lcd.begin(8, 2); 
    lcd.setContrast(30); 
    lcd.print("Oyakata"); 
    Rtc.begin();
}
void loop() 
{ 
    delay(1000); 
    Rtc.available(); 
    lcd.setCursor(0, 1); 
    if (Rtc.hours() < 10) {
        lcd.print("0");
    }
    lcd.print(Rtc.hours(), HEX); 
    lcd.print(":");
    if (Rtc.minutes() < 10) { 
        lcd.print("0");
    }
    lcd.print(Rtc.minutes(), HEX); 
    lcd.print(":");
    if (Rtc.seconds() < 10) { 
        lcd.print("0");
    }
    lcd.print(Rtc.seconds(), HEX);
}
//}

続いて、シリアルモニタではなく、液晶に表示させるスケッチを@<list>{code4}に実装する。基本的な記述はたいした内容ではなく、RTCから取得した時刻を表示ごとにlcd.print() で液晶画面に表示するだけである。なお、Code4ではそれぞれ、時、分、秒について、一桁の範囲では桁数がずれてしまうため桁数を合わせる操作も行っている。具体的には、取得した値が 10 未満であればあたまに0を付加するという操作である。

== スルーホール基板への実装

一旦液晶とRTCを接続することができた。この状態ではブレッドボードに接続しているので、配線の見通しが悪かったり、接触したり、外れたりなど、トラブルの原因となる。また、Arduino自体の固定も難しいという問題があるため、第一ステップとして、初期費用も安く、簡単に実装可能なArduino用のスルーホール基板を用いて基板を作る。いわゆる自作基板については後ほど触れる予定である。

一旦は、手書きの回路図を引く。このArduino 時計Ver1 で使用し、今回ユニバーサル基板上に配置するパーツは以下の通りである。なお、今回使用した部品はすべて秋月電子通商で販売されている。

 * Arduino Uno Rev3@<fn>{ArduinoUno}
 * 液晶モジュールAE-AQM0802@<fn>{akilcd}
 * RTC モジュール RTC-8564NB@<fn>{akirtc}
 * 電気二重層キャパシタ 5.5V1.5F@<fn>{akicap}
・逆流防止用ダイオード（とりあえず手元にあった1S3 30V1A の整流用ダイオード）@<fn>{diode}
・メイン基板Arduino 用ユニバーサル基板 ガラスコンポジット（赤）@<fn>{board}

ユニバーサル基板のPDF 適当に拾ってきて、印刷して、手書きでパーツの配置と配線ルートを考える。ものを適当に並べてみて、配線を適当に引く。大きいものから並べて、展示・設置の方向も考えて、端から置いていく。次に配線をする。両面スルーホールなので配線をまたぐのは極力減らしたい、という思想で配線をする。I2Cデバイスに必要な配線は、VCC、 SDA、SCL、GND の4 線である。





//footnote[ArduinoUno][http://akizukidenshi.com/catalog/g/gM-07385/ Ａｒｄｕｉｎｏ Ｕｎｏ Ｒｅｖ３ 2940 円] 
//footnote[akilcd][http://akizukidenshi.com/catalog/g/gK-06795/ I2C 接続小型LCD モジュール（8x2 行）ピッチ変換キット 600 円]
//footnote[akirtc][http://akizukidenshi.com/catalog/g/gI-00233/ リアルタイムクロックモジュール 500 円]
//footnote[akicap][http://akizukidenshi.com/catalog/g/gP-04250/ 電気二重層コンデンサ 150 円]
//footnote[diode][http://akizukidenshi.com/catalog/g/gI-01707/ ショットキーダイオード1S3 130 円(10本)]
//footnote[board][http://akizukidenshi.com/catalog/g/gP-09624/ Arduino 用ユニバーサル基板 ガラスコンポジット（赤） 180 円]
 
//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-2.jpg}
\caption{Arduino時計の配線図(手書き)}
\end{figure}
//}

とりあえずの配線パターンは図10.2に示す。基板CAD で清書する気力がないのでデジカメ撮影のみで示す。

このレベルであれば、基板CAD等やっている間に手書きでささっとやってしまうと良いと考える。もちろん使いまわしや今回のように文章にまとめるなどの時にに困るのだが。

配線図中の文字が汚いとか、配置をこうしたらとか、この渡り線はないわとか、もろもろとりあえず横に置いてもらって実装を進める。電気二重層キャパシタは裏側(ハンダ面)に配置した。ちょうどArduinoのソケットの隙間に入ったためである。

次に、買ってきたユニバーサル基板にコネクタ・部品付けをするとともに配線を引く。銅の裸線をランドにくっつけて、ある程度ハンダを盛る形で配線をした。スズメッキ線の手持ちがなかったのと、電流もたいしたことないし、失敗した時にやり直しがきくからということで、銅撚り線をバラした細い線を使ってみた。

完成品が図10.3および図10.4である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-3.jpg}
\caption{Arduino時計　表側}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-4.jpg}
\caption{Arduino時計　裏側}
\end{figure}
//}

このときの裏話として、とりあえず作ってみたところではうまく動かなかった。症状としては、

 1. 電源が入ったり入らなかったりする。
 2. 表示が文字化けする。

//noindent
であり、原因は2 箇所の配線ミスであった
 
1の不具合原因はSCLとVCCが交差するところで、裏と表の裸線が交差するのだが、スルーホールを介してショートしていたためである。カプトンを貼って応急処置した。このときArduino用基板といっしょになんとなく買ったカプトンテープ@<fn>{capton}がその日のうちに早速役に立ったこととなる。

2の原因はRTCのGNDが浮いていたためである。そのため読み出しデータが不定となって、文字化けした。上段のOyakataは正常に表示されているのに対し、下段の時間が不定だったことから、RTC 周りが疑わしいことは想像できたのだが、こういうこともあるという参考のために記載する。

この2点を修正することで、安定動作するPC時計ができた。が、この間、配線の試行錯誤のために液晶コネクタ部分に直接ハンダゴテを当てていたところ、熱で壊れてしまった・・・壊れるほど当てるんじゃないよ、と我ながら思うが。


//footnote[capton][http://akizukidenshi.com/catalog/g/gT-09379/ 耐熱テープ(ポリイミドテープ)10mm幅 250 円]
 
=== DA 方法の検討
いよいよ本題のArduino を使ったDA の検討にうつる。DA の方法は2 つあり、一つは本体内蔵のPWMを利用したアナログ出力、もう一つはDAC-IC を使ってアナログ出力する方法である。当然それぞれメリット・デメリットがある。そこでまずはそれぞれのメリット・デメリットを述べる。

==== 内蔵 DA を利用するメリット

 * 追加部品なく、本体のみで動作可能。したがって安価。（ただし、後述のとおりPWM なので、平滑化は必要である。動かしてみればわかるけど。）
 * 実装が超簡単。数行のスケッチでとりあえずの出力が可能。LED の明るさ制御などであればはこれで全く問題ない。Duty 比制御により明るさを制御するが、50%点灯、50%消灯など、明るさ制御の用途では超簡単に実装可能である。

==== 内蔵 DA を利用するデメリット

 * PWM なので、適当なフィルタを利用して平滑化する必要がある。純正Arduino のキャリア周波数は約490Hz なので、過去に調査したガルバノの動作周波数上限（およそ800Hz）に以下の周波数であることから、振幅にもよるが、追従してしまう可能性がある。この点については追って調査する。
 * PWM なので、0～電源電圧までのユニポーラ出力となる。ガルバノはバイポーラで入力可能なので、レベルシフトが必要。

==== Arduino 制御の外部 DA チップを使うメリット

 * PWM ではないので、電圧出力を平滑化等する必要はない。
 * 出力チャンネル数も、分解能もチップ選定次第で自由自在

==== Arduino 制御の外部 DA チップを使うデメリット

 * 追加の配線、追加部品が必要。配線があるということは、実装も大変だし、動作不良時の原因切り分けが大変。ライブラリ取り込みが必要で、DA チップごとに実装を変更する必要がある。

 * ユニポーラのチップが多く、レベルシフトが必要。バイポーラの場合、両電源が必要な場合も多い。

なお、ネタバレとなってしまうが、最終的にEPS32を用いる事となり、内蔵の2chDACが使用できる事になったため、上記のメリットデメリットの議論はほとんど意味がなくなってしまったことを付記しておく。とはいえ、アナログ出力と平滑化の実装ニーズはあるはずなので、そのまま記述を続けるものとする。

=== Arduino の PWM 出力の実際

まずはアナログ出力としてのPWM を使ってみることにする。まずは出力波形を確認する。オシロで確認すると、確かにキャリア周波数は490Hz であった。もっと高周波だったらフィ ルタ製作とか簡単なのに・・・と思うが、通常のLED の明るさ制御などでは十分な用途で あるから、直接ガルバノ駆動のような用途に使うべきではないのだろうな、と思う。

AD 出力のスケッチをCode1 に示す。といっても、なんら特殊なものではなく、どこにで も書いてある。ピンを指定し、analogWrite(pin,duty)で出力する。引数はピンNoとDuty比である。Duty比は0～255の256 階調で、およそ0.4%刻みとなる。出力電圧は電源電圧とほぼ同じ5Vである。Duty設定値とオシロで測定したDuty比とrms値(Root means square。ほぼ実効値と考えて良い) の関係を図10.5 に示す。Duty はほぼ直線比例だが、rmsは非線形的に上昇する。

//listnum[code5][PWMアナログ出力のコード]{
void setup() {
// put your setup code here, to run once: 
pinMode(9, OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly: 
analogWrite(9,128);
}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-5.png}
\caption{ArduinoのPWM出力。引数128(Duty比50％)の波形}
\end{figure}
//}


//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-6.png}
\caption{PWM出力波形の設定値とDuty比およびRMS値}
\end{figure}
//}

次に、実際に平滑化したときにどうなるかについて試行する。PWM の平滑化にも幾つかの方法がある。最も簡単なのは抵抗R とコンデンサC を用いたCR ローパスフィルタを用いることである。CR ローパスフィルタのカットオフ周波数と振幅は以下の式で与えられる。

//texequation{
f_c=\frac{1}{2\pi c R}
//}


//texequation{
|\frac{V_{out}}{V_{in}}|=\frac{1}{\sqrt{1+(\omega C R)^2}}
//}


C とR が大きいほどより平滑化されることがわかる。また、振幅はカットオフ周波数において1/√2すなわち-3dB となる。またカットオフ周波数以下で透過する振幅は入力信号のほぼ1 倍となり、カットオフ周波数以上では、同じ意味であるが、-6dB/oct あるいは-20dB/decとなる。周波数2 倍でゲインが1/2、1 桁上がる(=10 倍)で1/10となる。ただし、今回の目的はガルバノスキャナ制御用信号の生成であるから、あまり平滑化をし過ぎるとDC成分しか含まれない事になり、制御に使えなくなる。

Arduino のPWM のキャリア周波数は490Hz なので、RC フィルタを組んでみる。使ったのは手元にあった1kΩと1uF である。適当に組み合わせて、フィルタを作ることを考えた。まずは、1kΩ、1uF を1 個づつ使ったフィルタのゲイン特性を見てみる。

1kΩ、1uF を使った時のカットオフ周波数を計算すると159Hz となり、Arduino のPWM出力を平滑化できそうな事がわかる。最近はネット上にも便利なツールがたくさんあり、特性値を入力するだけで伝達関数を計算してカットオフ周波数Bode線図のグラフまで出力してくれるサイト@<fn>{keisan}がある。下の図は当該サイトで計算し、出力のボード線図を拝借したものである。縦軸が大きいのでわかりづらいが、100Hzより少し上で落ち始め、その後-20dB/dec で落ちている事がわかる

//footnote[keisan][http://sim.okawa-denshi.jp/CRtool.php CRローパス・フィルタ数計算ツール]


//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-7.png}
\caption{RCフィルタのボード線図 R=1kΩ、C=1μF}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-8.png}
\caption{RC フィルタ適用後の波形 fc=159Hz}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-9.png}
\caption{RC フィルタ適用後の波形 fc=53Hz}
\end{figure}
//}


図2-8に1kΩ、1uF を使ったカットオフ159Hzのフィルタを適用したDuty比50.2%の波形を入力してみたところを示す。

電源電圧4.78Vに対し、平均値で2.41Vとほぼ半分、残っているゆらぎの成分は最大値3.56V、最小値1.24Vと2.32Vの振幅を持つことがわかった。流石にこの振幅は大きすぎるので、まずはコンデンサ容量を増やしてみる。1kΩと3uFを使うと、カットオフ周波数は 53Hzになる。その波形を図2-9に示す。平均値は変化せず2.41V、変動振幅は0.88Vまで低減した。また、5kΩ,3uF(カットオフ周波数=10.6Hz)では、変動の振幅は0.2V まで抑えられる。ただし、あまりカットオフを下げ過ぎると今度は通過させたい信号が低下する事になる。したがって、実信号で試す必要がある。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-10.jpg}
\caption{RCフィルタの実装例とArduino基板}
\end{figure}
//}

図2-10にRCフィルタの実装例を示す。アナログ出力を一旦ブレッドボードで受け、RCを適当に接続し、出力部分にプローブを接続する。特性確定するまでの試行であるから、暫定的なものである。

ところで、フィルタに使うコンデンサって、アルミ電解コンデンサ使って問題なかったのだろうか。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-11.png}
\caption{平滑化後の出力電圧とリップル fc=8.8Hz(R=6kΩ、C=3uF)}
\end{figure}
//}

次に、手元にあった6kΩ(1kΩの抵抗と5kΩの可変抵抗)と3uF 分(1uF×3)のコンデンサを用いてカットオフ周波数を8.8Hzまで下げて、Duty 比と出力電圧および残リップルを調査した。ブレッドボードに回路を作り、オシロで出力信号振幅を調べる。結果を図2-11に示す。出力電圧は電源電圧である4.78V までリニアに増加するとともに、50%付近の残リップルが最も高いというリーズナブルな結果となった。Duty比50%で100mV 以上のリップルが残っているが、5Vフルスケールとすると、2%である。これがどの程度影響するか、あるいは、カットオフ8.8Hzで十分なのかは追って確認する。周波数特性を考える必要があるこういう用途が増えるなら、ネットワークアナライザーや、スペアナが欲しくなる。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-12.jpg}
\caption{平滑化後の出力電圧とリップル fc=8.8Hz(R=6kΩ、C=3uF)}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-13.jpg}
\caption{平滑化後の出力電圧とリップル fc=8.8Hz(R=6kΩ、C=3uF)}
\end{figure}
//}

次に、RTC と液晶を載せたユニバーサル基板上にフィルタを実装する。回路図と実装状況を図2-12、図2-13 に示す。カットオフは一旦低周波側とし、5kΩ（金皮）、4.7uF（積層セラミックコンデンサ）を使った。

次にArduino で時計を出力するために、アナログ出力部分のコーディングを行う。

== Arduino 時計の実装
過去、C84において、DAボードを使った時計を作った。それをArduinoに移植する。改めて、基本的な考え方と実装の詳細を示す。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-14.jpg}
\caption{アナログ時計のイメージ}
\end{figure}
//}

//listnum[codeArduinoClock][Arduinoを用いたアナログ時計実装例]{
Rtc.available();
int waittime = 100;
double hour = 2*M_PI*30*Rtc.hours()/360; 
int Xhour = int((sin(hour)*128+128)*0.5); 
int Yhour = int((cos(hour)*128+128)*0.5);
double min = 2*M_PI*30*Rtc.minutes()/360; 
int Xmin = int((sin(min)*128+128)*0.8);
int Ymin = int((cos(min)*128+128)*0.8;
double second = 2*M_PI*30*Rtc.seconds()/360; 
int Xsecond = int(sin(second)*128+128);
int Ysecond = int(cos(second)*128+128);

analogWrite(9,0); //X 軸原点 
analogWrite(10,0); //Y 軸 
delay(waittime); 
analogWrite(9,Xhour); //X 軸hour 
analogWrite(10,Yhour); //Y 軸 
hour delay(waittime);
analogWrite(9,0); //X 軸原点 
analogWrite(10,0); //Y 軸 
delay(waittime);
analogWrite(9,Xmin); //X 軸min 
analogWrite(10,Ymin); //Y 軸min 
delay(waittime);
analogWrite(9,0); //X 軸原点 
analogWrite(10,0); //Y 軸 
delay(waittime); 
analogWrite(9,Xsecond); //X 軸second 
analogWrite(10,Ysecond); //Y 軸second 
delay(waittime);
analogWrite(9,0); //X 軸 
analogWrite(10,0); //Y 軸 
delay(waittime);
for (int i=0; i<13; i++){ 
    analogWrite(9,int(sin(2*M_PI*30*i/360)*128+128));
    analogWrite(10,int(cos(2*M_PI*30*i/360)*128+128));
    delay(waittime);
}
//}

描画の方針は以下の通り。

 * 文字盤を示す点を12個と針を3本描画する。文字盤と針は順次描画し、残像を利用して全体を表示する。
 * 1周の時間は積み上げで決定され、繰り返し周波数から決定するものとする。
 * （とりあえずは）レベルシフトなく描画する、0V～5V(正確には 4.8V 程度)をフルスケールとする。
 * レーザーの ON/OFF なし。

これで、実装すると、@<list>{codeArduinoClock}のように実装できる。ベタうちなので、微妙・・・と思う人もいるかもしれないが、とりあえずのテストはこんな感じで実装し、様子を見ることにする。秒針は100%、分針は80%、時針は50%の長さとした。さて、このコードには、たくさんの間違い・バグがある。頭の体操を兼ねて、バグ取りの経緯を追ってみることにする。その前に、基本的な思想を確認しておく。

まず Rtc.available();で RTC から時刻取得し、時、分、秒の各項目を抽出し、描画位置に変換する。X軸とY軸の出力はそれぞれ、取得した時刻を0時から始まる角度（ラジアン）に変換し、sinまたはcosをとり平面座標にとる。さらに128をかけて、128を加え、Intで丸めて整数値とし、Duty比として出力すべきアナログ値の引数とする。X軸Y軸のそれぞれの座標に対応するアナログ出力を analogWrite(ch,Duty)で設定し、アナログ出力を行う。delay(waittime)で一定時間を待ち、次の点にいく。時針、分針、秒針、文字盤の 12 個の点、と順々に描画する。

X成分のアナログ出力波形を図10-15および図10-16に示す。手持ち素子の都合からRCフィルタの定数をそれぞれ5kΩ、4.7uFとし計算すると、カットオフ周波数は7.2Hzとなる。上段がPWMの生波形、下段が平滑化後の波形である。鈍らせすぎかな、と思うのが正直なところである。このあたりは試行錯誤で調整する必要がある。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-15.png}
\caption{平滑化前後のX成分のアナログ出力 fc=7.2Hz(R=5kΩ、C=4.4uF)}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-16.png}
\caption{平滑化後出力波形 2ch 併記 fc=7.2Hz(R=5kΩ、C=4.4uF)}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-17.png}
\caption{リサージュ表示 fc=7.2Hz(R=5kΩ、C=4.4uF)}
\end{figure}
//}

==== バグ1:値が飛ぶ(Dity 比設定のミスによる)
出力設定値をint(sin(2*M_PI*30*i/360)*128+128)としたため、Duty比256 が入ってしまい、0に折り返されるため異常値となる。（範囲を超えても、コンパイラ上も動作上もエラーにならない。）

図2-16に縦横2chそれぞれの波形を示す。ズレた V 字がふたつあり、ここが周りの文字盤のところと推測されるが、下のほうで V 字が途中で折れている事がわかる。針を表示して、一周回るコーディングになっているはずができてない。また、図 2-17 に示すリサージュ表示においても、0 時のところと 3 時のところに謎の V 字が存在する

これは、@<list>{codeArduinoClock}でシフトのために+127にしようと言った尻から、+128と実装したミスによるもので、Duty=256=0となってしまったためである。そこで、+127に変更したところ、今度は6時と9時に-1が出てしまい、点対称な図形ができてしまった。面白いのは、Duty に-1を入れると、255相当に循環するというところか。
 
これは、単純なバグではあるが、見た目上の影響は重要なバグである。そこで与える振幅を127とし、0～254の範囲とした。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-18.png}
\caption{バグ 1修正後の平滑化波形 fc=7.2Hz(R=5kΩ、C=4.4uF), Delay=100ms}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap10/image10-17.png}
\caption{バグ 1修正後のリサージュ表示 fc=7.2Hz(R=5kΩ、C=4.4uF), Delay=100ms}
\end{figure}
//}

バグ1 を修正したところで、あらためて平滑化後の生波形(図10-18)と、リサージュ(図10-19)を示す。オシロ上は意外ときれいな円になってるじゃないですか。

==== バグ2:原点位置がおかしい。
続いてバグ2を発見。時計の針の原点が左隅になっている。

原点を Code6 のように与えているためである。

そう、原点は、127、127である。
そこで、原点部分を修正する。

//listnum[codeClockOrigin][原点指定についてのバグ]{
//間違い
analogWrite(9,0);	//X 軸原点 
analogWrite(10,0); //Y 軸 
delay(waittime);
//修正
analogWrite(9,127);	//X 軸原点 
analogWrite(10,127); //Y 軸 
delay(waittime);
//}

修正後の挙動を確認したところ、一見問題ないが、秒針の挙動ががおかしい。時計回りの方向、時針、分針は問題ないのだが、なぜか 10 秒毎に秒針がジャンプするという問題が発生した。

==== バグ3:針がジャンプする
原因は、Rtc.Available（）で取得した時刻はBCD（Binary Code Decimal：二進化十進数）であり、そのまま位置座標用に代入するとバグるという点にある。

気づく過程として、以下の試行錯誤を経た。

 1. まず、取得している RTC をそのまま液晶に表示させてみた。

lcd.print(Rtc.seconds(), HEX);
当然そのまま表示される。

 2. なぜ HEX？と思いつく。 lcd.print(Rtc.seconds(), DEC）; と変更し 10 進数表示にしてみる。

0～9 は良いが、10 を表示すべきところで 16 にジャンプすることがわかった。この挙動は、オシロで表示した時にジャンプする挙動に一致する。

 3. RTC の説明サイトをいくつか回る。結果、実装のネタ元@<fn>{netamoto}の下のほうに、 @<em>{RTCはBCD形式で値を返す}という記述があったので、10 進数にするには Rtc.seconds(RTC8564::Decimal)とする必要があることがわかった。これで、10 進数でデータを取得することができ、そのままその後の計算に使うことができる。

//footnote[netamoto][http://arms22.blog91.fc2.com/?tag=RTC 何でも作っちゃうかも （2016.08.12 閲覧）]

//listnum[bcdcode][RTCの数値の問題部のコード]{
lcd.print(Rtc.seconds(), HEX);  //OK
lcd.print(Rtc.seconds(), DEC);  //NG
second = Rtc.seconds(RTC8564::Decimal);	//OK
second = Rtc.seconds();                 //NG
//}

//table[bcdtodec][BCDと10進数の関係]{
値	BCD	BCD→DEC	値	BCD	BCD→DEC
--------------------------
0	0000	0	10	0001 0000	16
1	0001	1	11	0001 0001	17
2	0010	2	12	0001 0010	18
3	0011	3	中略		
4	0100	4	19	0001 1001	25
5	0101	5	20	0010 0000	32
6	0110	6	30	0011 0000	48
7	0111	7	40	0100 0000	64
8	1000	8	50	0101 0000	80
9	1001	9	59	0101 1001	89
//}

なお、BCD 形式を 2 進数として読み取り 10 進数に変換すると、表 1 のようになり、値のジャンプの状態、挙動とも一致する。なるほどなるほど。今回は初めて BCD なるものを知ったので前回の本の入稿までには上記バグが取れず、前回の本文にはバグがあったままであったが、今回、エラッタを兼ねてここに記載する。結果としてこの問題が解決し、オシロ上は正確な時計が描かれるようになった。

==== PWMの周波数について
バグというわけではないが、併せて、PWM 周波数について新たな情報を得たので記載する。

ここまで、アナログ出力はPWMの標準的出力端子である9、10 ピンを使った。サンプル例も多いのでそのまま実装したが、そのキャリア周波数は 490Hz であった。ネット上の実装例の情報@<fn>{freq}によれば、PWM 周波数は可変であり、また出力ピンによって異なることが示されている。具体的には 5,6 ピンのキャリア周波数は 976Hz でありそれ以外のピン（9,10,3番、11番）が490Hzとなる。さらには PWM 周波数の変更まで可能であり、CPU クロックに分周比を変更することにより行う。とりあえずは 5.6 ピンに変更しておよそ 2 倍の周波数とした。

//footnote[freq][日々 ほげほげ 研究所 Arduino	PWM 周波数の高周波化https://theoriesblog.blogspot.jp/2014/05/arduino-pwm.html（2016.08.12 閲覧）]

針のジャンプの問題が解決し、PWM 周波数を上げたところでいよいよ描画を行ってみる。実験に利用するのはいつもの構成である。すのこタンに設置した自作水冷付きのレーザー  モジュールとガルバノスキャナで行う。入力信号はArduino 時計の出力である。
とここで、入力信号用のケーブルが短くて（現状約 15 ㎝）取り回しが悪いことに気付いた。動作チェックの前にこっちを何とかする。準備したもの。

 * JST  XH コネクタ 2.5 ㎜ピッチ 3 ピン用 20 円19
 * JST  XH コネクタ用コンタクト 100 個入り 800 円
 * 精密圧着ペンチ エンジニア PA-09  3063 円@Amazon
 * 10 芯すだれケーブル 1m  150 円（のうち 3 本を取り出して使う）

//footnote[jhcon][千石ネット通販 電子工作部品 > コネクタ・端子 > 小信号用 圧着・圧接コネクタ > JST XH(2.5mm ピッチ) https://www.sengoku.co.jp/mod/sgk_cart/search.php?cid=3378  (2016.11.28 閲覧)]

これで、入力信号用のケーブルを作る。50cmくらいに切って両端にコネクタをつける。 Arduino時計の基板の方には、平滑化後の出力付近に 3本のピンヘッダを立てこのコネクタを取り付ける部分とする。精密圧着ペンチ便利。ちゃんと専用のツール使うこと重要。いろいろ使えるので、やっぱり使いやすいツールを買うこと、超重要。あと欲しいツールとしては、よく切れるニッパーと、細めのラジペン、ピンセット、あとはワイヤストリッパーかな・・・メモメモ。