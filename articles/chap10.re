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

このようにして、実装を進める。秋月でも安価に売っているI2C 接続の小型液晶を使用して、Arduino にモニタを付ける。液晶画面には、現在時間を表示する。

使用した液晶はAQM0802A-RN-GBW2@<fn>{lcd}である。8 文字× 2 段の小型キャラクタ液晶で、 700円程度と非常に安価である。配線は、電源とGNDとI2Cの2線の合計4線のみ配線すればよく、配線も簡単である。これを用いて、時刻などをもろもろ表示させる。

HaruLabさんのHP@<fn>{harulab}を見ながら実装を進める。まずはライブラリを読み込む。ダウンロードしたライブラリ@<fn>{library} を、マイドキュメント>Arduino>Libraries> に格納する。スケッチ>Include Library で、Arduino_ST7032 が表示されていることを確認する。続いて、配線を行う。配線は、液晶変換モジュール使用前提で、1：3.3V、2：NC、３：A5/SCL、4：A4/SCA、 5:GND となる

図9-1はブレッドボードとジャンパワイヤでとりあえずのテスト実装したところである。 Arduino側はピンソケットになっているので、ジャンパ線を差し込む。液晶側はブレッドボードに差し込み、その隣にジャンパ線を差し込む。

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

//listnum[code4][]{
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
 * 液晶モジュールAE-AQN0802@<fn>{akilcd}
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
 
