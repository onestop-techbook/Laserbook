= レーザ時計用アンプ基板作ってみた

==	オペアンプとは？
EPS-WROOM-32にはDACがついた。それは大変喜ばしいことであるが、出力は0～3.3V の8bitユニポーラである。一方で、現在使用中のガルバノの入力定格は±10Vであるから、描画可能範囲の1/6しか使えないということになる。描画面積でいうと1/36である。そこで前々から予定していたとおり、レベルシフトとアンプを実装し、描画可能範囲を拡大する。ここからしばらく、オペアンプに関するつまらない話になるので、オペアンプなんぞ常識だよね、という方は読み飛ばしていただいてかまわない。

アンプ設計についての参考文献：
すぐに使えるオペアンプ回路図100	富田豊 丸善株式会社(2006)

そのまま実用回路例も多く、非常に参考になったので、本文中に挙げておく。


オペアンプはオペレーショナルアンプリファイアの略で、日本語では演算増幅器とも呼ばれる。基本形は、2入力1出力の素子で、増幅回路、コンパレーター、積分回路、発振回路などに利用される。いずれの用途においても、数個の外付け部品を用いて出力をフィードバックして使うことで様々な機能が実装できる。市販品としても非常に安価で、1個あたり数円から数十円で購入することができる。以上は、電子工作界隈の方あれば知っている内容であろう。
一方で、詳細な設計となると案外よくわからないのではないだろうか。私自身の経験となるが、大学の「電子回路」などの講義において、オペアンプの動作原理や回路の勉強をしたときには、何に使うのかもさっぱりわからないし、なんかよくわからんなぁ、というのが実情である。そこで、多少冗長にはなるが、今回使うアンプの設計について、基本的な部分を説明する。(主に自分の理解のため)

==	アンプの詳細設計
まず、今回使用するアンプの設計を行う。

入力：0-3.3Vユニポーラ(ESP-WROOM-32のDAC出力)	2ch

出力：±10V バイポーラ(ガルバノの定格) 2ch

使用可能な電圧：3.3V、5V、±15V(DC-DC使用)

必要なシフト量 -1.65V

インピーダンス的にも周波数的にもそれほど厳しい信号ではないので、非反転回路で構築することにする。
 
//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-1.png}
\caption{オペアンプを用いたレベルシフト回路}
\end{figure}
//}

図7-2にオペアンプを用いたレベルシフト回路図を示す。次に、それぞれの入力電圧と出力電圧について立式する。まず、それぞれの入力端子における電圧は、以下のように書ける。

//texequation{
V_{minus}=\frac{R_2}{R_1+R_2}V_{ref}+\frac{R_1}{R_1+R_2}V_{out}
//}


//texequation{
V_{plus}=\frac{R_4}{R_3+R_4}V_{in}
//}

これが、オペアンプの基本動作である、イマジナリーショート(入力端子電圧が等しい)により、V@<sub>{minus}=V@<sub>{plus}であるから、
 
//texequation{
\frac{R_2}{R_1+R_2}V_{ref}+\frac{R_1}{R_1+R_2}V_{out}=\frac{R_4}{R_3+R_4}V_{in}
//}

//texequation{
\frac{R_1}{R_1+R_2}V_{out}=\frac{R_4}{R_3+R_4}V_{in}-\frac{R_2}{R_1+R_2}V_{ref}
//} 

//texequation{
V_{out}=\frac{R_4}{R_3+R_4}\frac{R_1+R_2}{R_1}V_{in}-\frac{R_2}{R_1}V_{ref}
//}

ここでシフト量は1.65V、V@<sub>{ref}= 3.3Vであるから、R@<sub>{2}=1/2となり、比に従って値を適当に定めると、R2=10kΩ、R1＝20kΩと決定することができる。また、初段でのゲインは1と設定したので、R4=20 kΩ、R3＝10kΩとなる。こうして、初段の定数が決まった。
 

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-2.png}
\caption{非反転増幅回路}
\end{figure}
//}

次に、2段目のアンプを非反転増幅回路で構成する。同様に書き下すと、

//texequation{
V_{minus}=\frac{R_2}{R_1+R_2}V_{ref}
//}

//texequation{
V_{plus}=V_{in}
//}


この両者がイマジナリーショートにより等しいとして、
//texequation{
V_{in}=\frac{R_2}{R_1+R_2}V_{out}
//}

//texequation{
V_{out}=1+\frac{R_2}{R_1}V_{in}
//}
 
となる。入力振幅と出力振幅を考えると、±1.65V→±10Vで、ゲインは6倍とする必要があり、調整可能なように可変抵抗としておく。

以上の思考からまずは片側の回路図を引く。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=1.0\linewidth]{images/chap15/image15-3.png}
\caption{オペアンプを用いたレベルシフト・増幅回路図(1ch)}
\end{figure}
//}


なお、これを実装している途中にパワーフラグの扱いがよくわからないという事態に直
 
面した。例えば、この図で言うところの、オペアンプの負電源側のパスコンのGNDは、パワーフラグを立てておかないと、ERCの未接続エラーが出る。一方で、オペアンプの正電源のほうは、パスコン、GNDの接続のみで特にERCエラーはでない、この辺は、原因がわかったらまとめるかもしれない。現状は、エラーが出たらパワーフラグを立てておき、ERCエラーを消す、という場当たり的対応である。

次に、この回路図をそのままコピーして、2ch目用の回路図を引く。そして、アノテーションを行い、ERCチェックをかける。その結果、パワーフラグを立てた4カ所でエラーが発生した。2ch側のパワーフラグをすべて削除すると、パワーフラグは消える。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=1.0\linewidth]{images/chap15/image15-5.png}
\caption{2chアンプの回路図}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-4.png}
\caption{回路図をコピーしたときのECRエラー例}
\end{figure}
//}

パワーフラグに関する理解は十分とはいえないが、同じ電源端子に接続しているのに、パワーフラグが複数存在していて、「電源の定義」が重複している、といった感じなのだろうと想像している。と、ここまで書いていて、回路中のGNDもどれか一つにパワーフラグが立っていればいいのだ！ということに気がついた。パワーフラグを立てておくことで、それぞれの電位を一致させることができ、GNDはGND、VccはVccから線を引くだけで明示的な線を引かなくても、電源としてつかえることになる。ようやく納得した。ということは、信号ラインもパワーフラグかそれに類するフラグがあって、信号線を別のところに引けるということだろう。信号フラグはあとで探してみよう。それに、最悪、適当な電位を指定しておけばよいということになる。

こんな感じで、とりあえず、アンプ部分は完成したことになる。出力は3芯フラットケーブルでガルバノの制御ボードに入力するので、CONN_01X03で取り出せばよい(図15.6では1×2になっているが、追って修正する)



== 電源部分の設計・実装
次に、電源部分を実装する。今回使うのは、ワンチップの昇圧DC-DCモジュール A0515S-2Wである。詳細は既刊@<fn>{56}に記載している。価格はAliexpress等で1個300円くらい、Aitendoで750円である。このデバイスはコンポーネントライブラリ内には存在しないので新規に登録する。手順はトラ技の記事@<fn>{57}等に公開されているのでそれを参考にする。

手順は、四角を1個、ピン5本を配置する。ピンの名前は 1:Vin、2:GND、3:ピンなし、4:-15V、5:GND、6:+15V とする。3 番ピンのところはピンなしのため、部品図上もあけておく。フットプリントとは直接リンクしないので詰めてもかまわないが、回路図上特に問題なければ実体図にあわせておくとよいと思われる。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-6.png}
\caption{電源部の設定}
\end{figure}
//}

なお、回路記号作成上の注意点としては、以下の通り。

 * 端子に丸がついている方がワイヤを接続する＝外につながる側、線だけが、素子側。最初それを間違えて、ERCチェックで未接続が出た。
 * 端子の指定は、パッシブにしておくと無難。入力や出力、入出力など複数の指定が可能だが、つなぐ信号種類によってはエラーが出ることがある。一方、パッシブならば、何をつないでもよいので、エラーが出る可能性が低下する。
 * 寸法はだいたいその通りにやっておいた方が良さげ。
 * ちゃんと保存するのを忘れないように。

5ピンのモジュールがちゃんとできていることを確認する。次に、回路図エディタに貼り付けて、電源周りの電源ポートに接続する。できたモジュールおよび回路図上に貼り付け、電源フラグと接続したところを図15.6に示す。


//footnote[56][2017 夏の薄い本 親方 Project	2017.08.13	C92 発行]
//footnote[57][http://toragi.cqpub.co.jp/tabid/673/Default.aspx KiCad の回路記号＆フットプリントを作る方法 2017.09.15 閲覧]
 
== ESP 開発ボードと RTC モジュールの登録
次に、ESP-WROOM-32開発ボードのライブラリを登録する。少し調べてみたところ、 ESP-WROOM-32のモジュールのライブラリは有志公開@<fn>{58}されていたが、開発ボードは見つけられなかった。そこで、図15.7のような、開発ボードのライブラリを作る。そのままピンNoを読み取って並べただけなので、他社の開発ボードはそのままでは使えない可能性がある。デザイン・結線によって変わるので、メーカーごとにピンアサインが異なる可能性があるからである。改めて明記しておくと、秋月のESP-WROOM-32開発ボード用である。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-7.png}
\caption{ESP32開発ボードの回路}
\end{figure}
//}

ESP32のDACは25と26なので、25と26から配線を引き出し、アンプの入力に接続する。そして、開発ボードの他端子も使えるように引き出し可能とする。そのために、ピンヘッダの隣にもう一つソケットを一列設ける。実際に使う3.3Vや5Vもブレッドボードに引き出せるようになるし、ジャンパーピンで引き出すことで、他の入出力も使用できるようになる。単純なピンヘッダ－（一列×19本）を用いればよいので、パターンだけ作っておいて、実装してもしなくてもよい。ピンヘッダーおよび配線引き出しの様子を図15.8に示す。ほとんど図15.7と同じだが、両側にピンヘッダーが追加されたのがわかるかと思う

//footnote[58][http://daiwa-c.blog.jp/archives/1065186580.html	SP-WROOM-32 モジュール KiCadのライブラリー 大和通信の技術力 2017.09.15 閲覧]

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-8.png}
\caption{ESP開発ボードからのアナログ信号取り出しとピンヘッダ追加}
\end{figure}
//}


次に、液晶モジュールとRTCモジュールも同様に実装・登録する。秋月のRTCモジュールはDIP化済の2.54mmピッチの8ピンのモジュールであり、2列のピン列を作る。データシートを見ながらピンを並べるのも同様。作成したRTCモジュールを図15.9に、液晶変換モジュールを図15.10に示す。使うピン使わないピンがあるが、部品図登録の段階では正直にやっておくのがよい。 

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-10.png}
\caption{RTCモジュールの回路図}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-9.png}
\caption{液晶モジュールの回路図}
\end{figure}
//}


登録した部品は次にRTCモジュールおよび液晶モジュールを追加する。今回使うのは、Vcc、GND、SDA、SCLの4本である。それぞれ、液晶モジュールから配線を引き出して接続する。

電源は電源ポートで与えれば良い。次に、RTCモジュールのバッテリーバックアップを実装する。RTCは電源がつながっている間時刻をカウントアップし続けるデバイスだが、電源が切れてしまうと、時刻を忘れる。

そこで、小型大容量のキャパシタである電気二 重層コンデンサ(ELDC)を接続して、電源バックアップをおこなう。接続するのが5Vであ るから、5.5V1FのEDLCを接続することとする。部品としては、有極キャパシタを選択し定数に1Fと入れておく。また、EDLCには充電が早いという特徴があるが、裏を返すと電流吸い込み能力が高いということであるから、すっからかんのEDLCをいきなり電源につなぐと、大電流が流れることになる。

電流供給が太い場合は問題ないが、細い場合にはショートに近い状況になり、思わぬ事故を起こす可能性がある。そこで、電流制限抵抗を付けておく。充電には時間がかかることになるものの、電源ショートは素子焼損などのトラブルの原因ともなりかねない。秋月開発ボードの回路図を見ると、今回キャパシタを繋いでいる5VはExt5Vであるから、EPS32モジュールを経由せず、USBの5Vとショットキーダイオードを経由して接続されていることがわかる。したがって、供給能力はUSBに依存することになるため、ESP32の供給能力には依存しないと言える。しかし、逆に言えば、PC側や電源などの上流側を壊す危険があるということであるから、やはり何らかの安全措置をとってお くことが望ましい。

そこで、1kΩ程度の抵抗を付けておくこととした。特に根拠ある値ではないが、電流制限抵抗をつけておくと安全である。1kΩのとき電流は5mAに制限され負荷は小さくなるとともに、Arduino側へ電流が逆流しないよう、適当なダイオードを付けた上で、RTCの電源とした。あわせて、RTCモジュールから線を引き出し、液晶にも接続する。RTC、液晶周りの結線を図15.11に示す。
 
//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-11.png}
\caption{RTCおよび液晶部分の回路図}
\end{figure}
//}

また、オペアンプの片側に集まっているパワーフラグを、電源部分に移しておく。単純に、回路図部分がスッキリするというだけの理由であるから、あまり意味はない。また、回路図を変更するたびに、アノテーションとERCをかけておくと、ミスが出づらい気がする。特に未接続は見えづらいのと、明示的に接続が必要なピンが抜けている場合などがよく分かる。ただし、「配線ミスという名の設計ミス」まではERCではわからないので、その点は注意する必要がある。

RTCがバッテリーバックアップされたということは、RTCをリセットしたりするスイッチがあると便利かと思われる。なので、これも追加しておく。RTCのリセットについての基本的な挙動としては、そのスイッチを押しながらリセットすると、指定時刻にリセットされる、というかんたんな仕様である。具体的には、コミケ開場の10時などに設定すると良いのではなかろうか。あまり複雑な時刻合わせは今はせず、せっかくWi-Fiがあるのだから、NTPでの時刻合わせを行えばよい。今回は基板へのハード実装および他の用途でも使うかも、ということで、スイッチを一個だけ実装しておくことにした。ここまでの実装で、主要な部品が実装されたことになる。多少冗長にはなるが、回路図全体を図15.12に示す。
 
//embed{
\begin{figure}[h]
\centering
\includegraphics[width=1.0\linewidth]{images/chap15/image15-12.png}
\caption{回路図全体(最終版)}
\end{figure}
//}

このあたりで、回路全体をみながら、微調整を行う。順次実装していると、いろいろ気持ち悪いところが出てくるからである。思いついた順になってしまうが、順次修正する。

まず、2端子のVRを使用していた、後段アンプの可変抵抗は、3端子のポテンショメーター に変更する。さらに、3番ピンを不使用としていたが、これは間違い。動作上は差はないが、 フェイルセーフ的には必要だからである。なひたふさんのコラム@<fn>{59}を読んで非常に納得した。要点を書くと、機械摺動部の不良に伴い、絶縁状態になる可能性があり、ゲインが不安定に なるため、バリオームの抵抗値以上の値が絶対に出ないようにしている、とのこと。なるほ ど。というわけで、こちらの図も、そのように修正する。2番と3番をショートしておく。

//footnote[59][http://www.nahitech.com/nahitafu/mame/mame1/vr23.html	部品の豆知識 バリオーム なんで 2 番と 3 番のピンをつなぐ？]

ここまでで、回路図上はすべての構成要素が記載されたことになる。なお、予定としていた、トランジスタによるオンオフ制御の実装は、時間の都合により、次回まわしとなる。ご了承いただきたい。今回の基板がちゃんと動く保証はないので、とりあえず10枚だけ作ってテストしてからとする。

次は、フットプリントの登録と、配置である。

== フットプリントの登録
ESPWROOM-32開発ボード、RTCモジュールおよび液晶ボードについては、部品ライブラリに登録されていない部品であるので、フットプリントを登録する必要がある。幸いなことに、いずれもSIPまたはDIPモジュールとなっている。注意すべきは、液晶ボードであり、接続は5ピンのSIPだが、液晶本体がかなりの大きさになることである。この範囲の部品の干渉について、予め気をつけておく必要がある。例えば、この実装例の中で言えば、電気二重層コンデンサを縦型を使うと干渉するし、その他のデバイス、あるいはコネクタ等と干渉するといろいろ面倒である。逆に、薄型のキャパシタを使って、液晶ボードの下に配置するなどの方法を取ると、安定するかも知れない。

登録したEPS-WROOM-32開発ボードのフットプリントの画像を図15.13に示す。なんと地味な・・・なお、KiCADのフットプリントエディタの背景を白にする方法がわからなかったので、雑に背景をペイントで白にした結果、文字の中とかに黒が残ってしまった。雑で申し訳ない・・・寸法に合わせてピンを並べればよいので、かんたんではある。背景を白にする方法はあるらしいが・・・わからなかった・・・

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-13.png}
\caption{ESP開発ボードのフットプリント}
\end{figure}
//}

7.6	プリント基板のレイアウト
プリント基板のレイアウトは、単純に試行錯誤するしかなかろう。筆者自身、基板を起こした経験は過去に2回、今回が3回目なので、こうすればよい、というのを言いづらい状況にはあるが、それでもせっかくなので、説明してみる。
 
 1. まず、大きいパーツ、あるいは重要なパーツから配置する。向きがあるパーツ（液晶など）もここに入る。
 2. とりあえず引いてみる。（GNDは引かない）信号の流れを考えながら、順に引っ張る。衝突して2層になる部分は後回し。
 3. 部品を回して、何かできないか考える。きれいに配列したほうが、わかりやすいし、実装もしやすい。
 4. 外形枠を引く実寸にあわせて引く。ただし、5cmとか10cmとか超えると値段が上がるので、できるだけその範囲に収まるように、微調整する。今回、横が若干広くなってしまい、当初110mmであったが、ピンヘッダとの隙間の調整等により、100mmに収めることができた。
 5. ドリルホールを置く（四隅）四隅に基板固定用のドリルホールを置く。Mounting Hole 3.2 M3 DIN965 Padあたりを選んでおけばよかろう。(適当)
 6. GNDベタを引く。塗りつぶしゾーンの追加>GNDを選択し、外形いっぱいを選択すればよい。表導体(F.Cu)と、裏導体(B.Cu)の2回実施することで、両面のベタGNDが完成する。これで、未結線だったGNDも自動的に結線が行われる。(図15.14、図15.15参照)
 7. DRCをかけて、未結線チェックを行う。オートDRCが効いているのでDRCに引っかかるようなことにはならないと思われるが、このDRCを一度かけるとともに、未結線チェックも行い、未結線がないことをここで確認しておくとよい。
 8. シルク位置を調整する。部品にかかっているとか、シルク同士が重なっているなどがあるので、見やすいように微調整する。
 9. 刻印など入れる （ボード名、署名、日付など）
記入は任意ではあるが、自分の名前くらい入れておこう。ロゴとか作ろうかな・・・

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-14.png}
\caption{塗りつぶしゾーンの追加}
\end{figure}
//}

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap15/image15-15.png}
\caption{塗りつぶしでGNDベタを作る}
\end{figure}
//}

//noindent
といえば簡単だが・・・まあ、試行錯誤あるのみ。

というわけで、要点ごとのコメントを幾つか示してみたので、ヘボい例として参考にしていただければ幸いである。とにかくトライアンドエラーと経験である。

なお、今回の作成で得た知識の一つが、GNDベタである。ノイズ対策と、基板の見た目上、GNDベタをやっておくとよい。また、GND線をわざわざ引かなくても自動で結線されるというメリットもある。なお、特に指定しなくても、GNDのランドは自動的にサーマルランドになるようである。

なお、配線を開始した直後などにはGND周りの結線がこんがらがってしまったり、未結線エラーは出てしまうため、わかりづらいところは仮配線をひいておくとよい。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=1.0\linewidth]{images/chap15/image15-16.png}
\caption{ESP32-レーザ時計基板 Ver1の最終配置図}
\end{figure}
//}

最終的な部品配置と寸法は、図15.16のとおりとなった。モノクロ印刷したときにこれがきれいに出てくれるかは微妙なところだが・・・2層基板の両面を使って配線を行った。もっと考えれば、もう少し小さくできたかもしれないが、試行錯誤の時間を削って本文執筆に回したと考えていただければ幸いである。

最終寸法は、図中にあるとおり、99.06mm×86.36mmの基板となった。ESPボードの上方の空間はUSBケーブルの部分、下側は、アンテナを置く場所である。また、ボードの右下の方にも少し開いている部分があるが、将来トランジスタを追加したりするのに使いたいと考えている。
 
== 基板の発注
今回は、PCB-gogoに出してみることにする。前回まで発注していたFusionPCBに不満があるわけではないが、新しいところも試してみよう。あと、Fusionより安そうなので・・・また、完全日本語対応というのもそれはそれで良いところである。

今回の基板は100mm×87mmであったが、なんと1200円(さらに10%オフクーポン適用！)であった。送料は1624円で、合計2704円と計算であった。Fusionよりだいぶ安い。

発注が10月7日深夜で、製造に3-4日、発送は10月10日予定とのこと、Fedexで2-4日で到着とのことから、10月中旬到着見込みのスケジュールである。本稿執筆時点ではその成否は不明である。当日ギリギリなので、実装も間に合うか微妙なところであろうか。うまく動いていれば、技術書典にて展示＆現物配布としたい。なお、配布価格は、次回、冬コミ以降の予定である。ミスがあれば、ミスがあるまま・・・なにかコメントはつけるかもしれない。どうなったかは乞うご期待。

なお、FusionPCBではデータ確認の前に、見積もり、ガーバー入稿後に即決済画面に入るが、PCBGogoではメーカーでのデータ確認後に決済可能となるようである。当初、決済画面に遷移できなくてとまどった。データ確認が先というのはありがたいかもしれない
 
