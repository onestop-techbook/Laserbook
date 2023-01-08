= ESP-WROOM-32 のDAC でレーザー時計
当初予定では、手持ちのArduino UnoにDACチップ(MCP4922等)をつないでアナログ出力をする予定であったが、ESP-WROOM-32にDACが2ch載っていることを知って、あっさり方針転換と相成った。

ESP-WROOM-32は旧モデルESP-WROOM-02の豊富な入出力、Wi-Fi付きは過去仕様を踏襲しつつ、MPUがスペックアップもされているようだし、メモリも増えているらしい。らしいらしい、といっているのは、そのあたりはあまり興味のないところだからである。詳細スペックについては、別途必要なリファレンス@<fn>{42}なりを確認いただきたい。

本用途に関連する最大の特徴は、DAが追加されているところである。外付け部品なしでアナログ出力が可能であり、動作検証および実装が非常にカンタンになる。ここで言うアナログ出力とは、PWM出力ではなく、DACによるリニアなアナログ出力である。

そこで今回は、レーザープロジェクター製作の進捗として、ESP-WROOM-32を用いたレーザー時計の実装概要について述べる。具体的には、ESP-WROOM-32の開発環境設定、 DA部分の実装、I@<sup>{2}Cを用いた液晶・RTCの実装（一応過去に実施済だから、要点と、ESP特有の内容について）、アンプの実装、ON/OFFの実装を行う。

あわせて、この機能を実装した基板を作ったので、その基板実装について解説する。


== ESP-WROOM の開発環境設定
現在一般に入手容易なモジュールは2つあり、ESP-WROOM-02とESP-WROOM-32である。いずれも、Espressif SystemsのSoCを搭載したWiFiモジュールであり、工事設計認証 (いわゆる技適)取得済みのため、日本国内で問題なく使えるモジュールである。-02のSoCは ESP8266EX、-32のSoCはESP32というらしい。このあたりの詳細は他の資料を当たっていただきたい。特筆すべきはその価格であり、-02が550円@<fn>{43}、-32が700円@<fn>{44}と非常に安価であるとともに、Arduino IDEで開発可能である特徴がある。過去、-02を入手したことはあったが特段琴線には触れなかった。

ところが今回の-32はもう、素晴らしいヒット具合である。とにかくDAオンボードすばらしい！（他のArduinoにはDAC積んでいるのもあるにはあるが・・・Arduino Due@<fn>{45}とかあったけど、高い！6264円＠スイッチサイエンス）

繰り返しになるが、今回実装するArduino時計の実装において、DAオンボードはとにかく便利である。というわけで、まずは開発ボードを46購入した。価格は秋月で1480円。驚異的な値段であると思う。秋月以外のベンダーからも開発ボードが販売されているが、以下の実装、基板製作については、秋月のESP-WROOM-32開発ボードを前提とする。（他社の開発ボードや秋月を含むDIP化ボードについては、調査・確認していないので、差があるのかないのかは不明である。また、モジュール単体での使用についても考慮しない。あしからず）

なお、ESP-WROOM-32をモジュール単体で使う場合は、USBシリアル変換、3.3Vを供給する電源も必要である。また、ピン間隔が1.27mmピッチなので、ピッチ変換も必要と、実際に使うのは割といろいろ面倒である。更に電源や入出力に絡む受動部品も必要であり、それらを実装するのも面倒である。それに対して、開発ボードならば電源や電源にかかわるパスコンの類、またUSBシリアル変換やそれに伴う配線など、実際に使用するために必要な実装内容がすべて完了していて、USBケーブルをつなぐだけで使用可能である。

開発ボードの写真を見ていただければわかるかと思うが、部品密度はかなり高い。これを読み解いて設計する必要があるのかと考えるとそれだけで萎えてしまう。今回の実装において、開発ボードを利用したおかげで、ESPモジュール周りの実装は非常にシンプルになっている。本節の後半で実装完了した基板を見ていただければわかるが、開発ボードから出ている線は、DAC出力2本、I2Cが2本、あとは電源のみである。また、開発ボードを利用したことで、同時に他の入出力を使ったり、取り外して別用途に使うなども可能となる。

以上の観点から、モジュール寸法は多少大きくなるが、わずかな金額差を補って余りある開発スピードが得られるため、開発ボードを使っておくのが幸せと思われる。改めて述べておくが、今回購入した開発ボードは、秋月のESP-WROOM- 32開発ボードである。購入したモジュールの写真を図1に示す。

モジュール単体は、写真中の銀色の部分+左側のアンテナ部分で、およそ 20mm×25mmの寸法である。ちっちゃいね。


//footnote[42][http://akizukidenshi.com/download/ds/espressifsystems/esp_wroom_32_datasheet_en.pdf 秋月電子通商 ESP-WROOM-32 データシート(2017.09.25 閲覧)]
//footnote[43][http://akizukidenshi.com/catalog/g/gM-09607/	ESP-WROOM-02	秋月電子通商(2017.09.25 閲覧)]
//footnote[44][http://akizukidenshi.com/catalog/g/gM-11647/	ESP-WROOM-32	秋月電子通商(2017.09.25 閲覧)]
//footnote[45][https://www.switch-science.com/catalog/1096/	Arduino Due	スイッチサイエンス(2017/09/24 閲覧)]
//footnote[46][http://akizukidenshi.com/catalog/g/gM-11819/	ESP32-DevKitC	ESP-WROOM-32 開発ボード 1480 円 秋月電子通商(2017.09.25 閲覧)]

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap14/image14-1.jpg}
\caption{ESP-WROOM-32開発ボード(秋月)}
\end{figure}
//}

まずは入手したESP-WROOM-32開発ボードの開発環境構築を行う。ネット上の先人の知恵をありがたく拝借することにし、そのとおりにやったらできた。
参考にしたところ。 http://qiita.com/rukihena/items/6a904368700eb1c7d2a3 ESP32(ESP-WROOM-32)でLチカ (WindowsでArduino IDE使用)
基本当該HPを見ればよいが、単体モジュールから開始しているため単体モジュールに関する内容も少なくない。従って、特に前半で電源等の手当もやっているため若干見通しがよくない。そこで、開発ボードを使うことを前提としているため、不要な部分は端折って実施亜に必要な点のみを以下に抽出する。

 1. ArduinoIDEをインストールする。インストール済ならスキップ。最新版にしておくと無難。
 2. ArduinoIDEにESP-WROOM-32を使えるようにするため、ESP32用のArduino Coreをダウンロードする。
 3. 解凍したArduino CoreをArduinoのフォルダに解凍する。 
 4. Arduino/hardware/espressif/esp32/toolsの中にあるget.exeをダブルクリックして起動する。DOS窓が開いて何やら処理・ダウンロードが行われるので、1分程待つ。
 5. ArduinoIDEからボードを選択する。ツール＞ボード＞ESP32 dev Boardを選択。
 6. 適当なLチカを行い、動作確認する。

https://github.com/espressif/arduino-esp32
から、ダウンロードする。(緑のClone or Downloadをクリックするとデスクトップ等へダウンロードできる)

C:/Users/[YOUR_USER_NAME]/Documents/Arduino/hardware/espressif/esp32 に解凍する。設定変更していれば、そこへ。この時、含まれる一切のファイル(cores,docs,その他フォルダー・ファイル)がesp32直下に来るようにする。

Lチカのスケッチ例をCode1に示す。IO4にLEDを接続、抵抗も忘れずに。（忘れてもまあ壊れはしないと思うが）

//listnum[codeesp32][Lチカのテストコード]{
void setup() { 
    pinMode(4, OUTPUT);
}
void loop() { 
    digitalWrite(4, HIGH); 
    delay(500); 
    digitalWrite(4, LOW); 
    delay(500);
}
//}

Arduino IDEでの認識が正常であれば、コンパイルおよび転送が行われ、LEDが0.5秒ごとについたり消えたりする。コンパイルできない場合は、そもそもボードが認識してないとか、Arduino Coreがダメとか、ボードが死んでいるとか、であろうか。Syntaxエラーにも注意は必要。コンパイルはできるのに、Lチカが動かない場合は・・・LEDの逆刺しか、配線ミスか・・・あたりがチェックポイントとなろうか。幸いにして、当方環境では、上記の方法で問題なく動作した。

== ESP-WROOM-32 の DAC を利用したアナログ出力
前述の通り、ESP-WROOM-32には、2chの8ピットDACが載っている。今回のArduino時計には、このDACを使う。まずは、DACのテストを行う。

アナログ出力の方法には2つあり、PWMによるアナログ出力と、DACを用いたアナログ出力がある。PWMは、Pulse Width Modulationの略で、一定周波数の矩形波のDuty比を変えることで、模擬的にアナログ値を出力するものである。LEDの輝度制御といった用途には、点灯時間の比率を直接制御する事ができるので、設定値と輝度がよく比例するため便利である。また、比較的どこにでも(小規模なチップでも)搭載されているので、おそらくハードウエア的に実装も簡単なのだと推測する。しかし、今回の目的の描画信号源に使う場合は、平滑化が必要である。デバイスの周波数特性とキャリア周波数の関係にもよるが、実際過去 の実装においては、平滑化を行っていた。また平滑化をしても、キャリア周波数が約490Hz（Arduino Unoの標準PWMの場合）と比較的低いため、若干のリップルが残ってしまうという問題がある。PWMによるアナログ出力は、@<chap>{chap10}を参照されたい。

これに対し、DACを用いたアナログ出力は設定したアナログ値をそのまま出力するものであり、平滑化等を行う必要がなく、(ノイズを除けば)リップルは生じない。

これまでArduinoでアナログ出力を用いる場合は、外付けのDACチップ(実装例が多いものではたとえばMCP4922など)を用いる事が多かったが、内蔵機能だけでアナログ出力が可能となった。しかも2chあるので描画目的には申し分ない。

ESP-WROOM-32の内蔵DACの分解能は8ビットなので、それほど高分解能とは言えないが、追加部品なしでDACが使えるというのは非常に便利である。便利便利と、何度でも繰り返す。出力の分解能については、0V～3.3Vのユニポーラ出力で8bit＝256階調ということで、LSB（量子化単位）は約12mVとなる。音声用途には厳しいかな・・・といったところだが、描画目的には十分な精度である。原理的には256×256ポイントの描画が可能という意味であるからである。

Arduino化したESP-WROOM-32を用いたDAC利用のアナログ出力の書式は、以下の通りである。

//listnum[dac][ESP32のDACコード]{
void dacWrite( pin, value );
//}

DACの出力ピンは25または26なので、pinにはこれを指定する必要がある。また、値の範囲は8bit なので 0～255である。とりあえずのDACのテスト用のスケッチをCode2に示す。電圧をリニアに10msごとに増やしていくスケッチである。10msごとに値を1増やし、上限 (256)になったら0に戻し、再度0から増やしていく動作を記述したスケッチである。

//listnum[dac2][ESP32のDACのテストコード]{
void loop() {
    for(i=0;i<255;i++){
        dacWrite(25,i); 
        delay(10); 
        if(i>255){
            i=0;
            }
        }
    }
//}

きちんと動いていることを確認するには、

 1. テスタを当てる
 2. LEDをつなぐ の二つが簡単であろう。

1.ならば、約2.5秒周期で電圧が0から3.3Vまで上昇していく様子が見られる。ざっくり0
＝0V、128＝1.66V、255＝3.3Vである。テスタを当てる場合は、2.5秒ではテスタの時間応答により指示値にズレが生じるため、変化時間をもう少しゆっくりするなどの対応を取ると、より確実に確認することが可能となる
。
2.ならば、LEDの閾値電圧を超えたところでぼやっと光ってくる様子が確認できる。ただし、PWMでの明るさ制御と挙動が異なることは覚えておく必要がある。

PWMでは、Duty比を指定するため、出力と明るさはほぼ比例するが、dacWrite()では電圧指定のため、閾値までは全く光らず、閾値を超えたところで少しずつ明るくなり、ある程度以降は輝度一定となる。明るさ制御という意味では、PWM出力のほうが直線的に制御可能であるため、直感的に使える面がある。しかし、今回の用途である時計描画のようなアナログ出力においては非常に便利であることは繰り返し述べておく。

