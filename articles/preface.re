= まえがき

本書を手に取っていただきありがとうございます。

本書は、2008年から書き始めたレーザー本をもとに、ここまで15年近い製作過程をまとめたものです。最近少々進捗的にご無沙汰していた部分も多いのですが、2023年4月開催のOSC ToKyoでの展示および展示の説明としての本書の配布を目的に編集を再開しました。

なにぶん情報が古い部分もありますし、画像などの解像度が低い(元データ紛失)などもあり、見づらい部分もあろうかと思いますが、本質部分は変わっていないと信じます。

それなりに手間と時間とお金をかけて作ってきたレーザープロジェクターですが、この後どこまで作業ができるかは、当日会場でご確認ください。

レーザープロジェクタを自作するための試行錯誤として、レーザーとは何かという教科書的内容、基板を起こしたり、水冷を作ったり、電源について調べたり、アクリル工作やったり、と幅広い分野について取り扱っています。これから何かを作ろうとする方の参考になれば幸いです。

何かを作り上げるには、様々な周辺知識が必要となります。本書では試行錯誤含めて、実装の過程をそのまま書いています。ですから、本書の内容はすでに時代遅れになった内容を含む可能性がありますが、それでも過去はこうだった、という観点で適宜読み替えていただければと思います。

また、ここから他のいろいろな機能を追加することも可能でしょう。今復活させたことをチャンスとして、もう少し遊んでみようと考えています。

最後に、本書を作り上げるにあたって、過去の分も含めてたくさんの方からフィードバックをいただいています。ありがとうございます。内容に関する指摘、日本語/文章的な校正などをいただきました。おかげさまで大変読みやすくなりました。

また、今回表紙は、トカゲさんに描いていただきました。ありがとうございます。いつもよりちょっと大人びた感じのワンストップくんちゃんです。プロジェクタっぽいものをモチーフに持ちつつ、ステキな感じにしていただきました。

それでは、レーザープロジェクタ自作の過程や試行錯誤をお楽しみいただき、よっしゃいっちょやってみよう、となっていただけることを期待してまえがきとしましょう。

//flushright{

2023年4月

親方＠親方Project　拝

//}

//pagebreak

== 免責事項

 * 本書の内容は、情報提供のみを目的としております。正確性には留意しておりますが、正確性を保証するものではありません。この本の記載内容に基づく一切の結果について、著者、編集者とも一切の責を負いません。
 * 特に、使用している機材の入手については海外からの個人輸入という形態ですから、入手可否、入手経路、金額等については、為替レートや入手ルートによって変わる可能性が高いことをご承知おきください。本書の記載情報に基づいて何らかの損害等が発生したとしても、筆者および当サークルは一切の責任を負いかねます。
 * 本書の中には、高出力レーザーを扱う部分が含まれます。レーザー取り扱いを間違えると、人の目や皮膚、周囲の物品に対して損傷を与える可能性があります。実験は実施者の責任において実施するとともに、適切な防護措置を講じてください。具体的には、レーザー管理区域を定める、レーザー保護めがねを着装する、レーザー光を覗きこまない、など、レーザーを取扱う上での十分な知識を前提としてください。
 * 本書の中には、バッテリーを扱う部分が含まれます。扱いを間違えると発熱、発火、感電などに至る可能性があります。ショート等の不適切な利用をなさらぬよう、十分にご注意ください。
 * 本書の一部または全部を著作権法の定める範囲を超えて無断で複写、複製、転載、Web上への転載・アップロードなどを行うことはおやめください。
 * 本書の内容について、間違いがあった場合、奥付の連絡先までご連絡頂けますと幸いです。なにもお礼はできませんが、今後の励みとなります。
 * 会社名、商品名については、一般に各社の登録商標です。TM表記等については記載しておりません。また、特定の会社、製品、案件について、不当に貶める意図はありません。
 * 本書の一部あるいは全部について、無断での複写・複製はお断りします。
 * 本書電子版をお読みの方へ。電子版の一部写真・画像に解像度の荒いもの、またモノクロになっているものがあります。(特に後半)。底本となった原稿の都合によるものであり、異常ではありません。具体的には。9章～17章については白黒画像になる可能性があります。また差し替え可能な画像については適宜差し替えを行ったため、一部唐突にカラーに戻ることがあります。ご了承ください。
