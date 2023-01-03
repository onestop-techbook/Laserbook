# Re:VIEWテンプレート

## 概要説明
レーザー本

## この本の目的
レーザー本最終版作業用


## 執筆・配布スケジュール
2023年4月OSCTokyo向けに頑張る。

### Dockerを使う方法

build-in-docker.batを叩く。

### 数式対応
数式の採番がされなかったので、review-ext.rb作って、数式採番するようにした。

### 上付き文字・下つき文字
Cr@<sup>{3+}

log@<sub>{2}(1000)

ありがたい！

http://my-web-site.iobb.net/~yuki/2018-07/e-book/review-sup-sub/

### なぜか画像が貼れない件。

//embed{
\begin{figure}[h]
\centering
\includegraphics[width=0.5\linewidth]{images/chap1/img1.png}
\caption{レーザーの模式図}
\end{figure}
//}

https://github.com/kmuto/review/issues/1161
これのせいか！
Listnumマクロも使えない・・・

Review2に落として成功。

### 権利

ベースには、[TechBooster/ReVIEW\-Template: TechBoosterで利用しているRe:VIEWのテンプレート（B5/A5/電子書籍）](https://github.com/TechBooster/ReVIEW-Template) を使っています。

  * 設定ファイル、テンプレートなど制作環境（techbooster-doujin.styなど）はMITライセンスです
    * 再配布などMITライセンスで定める範囲で権利者表記をおねがいします
