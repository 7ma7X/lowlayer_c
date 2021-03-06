## ネットワークプログラミンング

インターネットにおいても、ストリームを相手にするという意味ではこれまでと変わらない

インターネットにおいて、ファイルシステムのファイル名に相当するのが、IPアドレスとポート番号

接続を待っていて何かをしてくれるプロセスが**サーバ（プロセス）**、サーバに接続して何かをしてもらうプロセスが**クライアント（プロセス）**

一般に、どのサーバがどのポート番号で待ち受けているかはよくわからないが、デフォルトのポート番号（ **ウェルノウンポート** ）は決まっていて、`/etc/services` で確認できる

## ホスト名、リゾルバ

IPアドレスは分かりにくいのでホスト名を使う

ホスト名はドメインに分割され、DNS(Domain Name System)によって管理  
`www.example.com` のIPアドレスは `example.com` のDNSサーバに尋ねればよい、`example.com` のIPアドレスは `com` のDNSサーバに尋ねればよい、 `com` のIPアドレスはルートドメインのDNSサーバに尋ねればよい、ルートドメインのIPアドレスは全てのDNSサーバに直接書かれている

ホスト名をIPアドレスに変換する機構全体をリゾルバと呼ぶ

## ソケット

ストリームをそこに接続できるための口

## クライアント側の socket API

流れ

1. socket(2)
2. connect(2)


#### socket(2)

ソケットを作成し、それに対応するファイルディスクリプタを返す

#### connect(2)

ソケット sock からストリームを伸ばし、アドレス addr で示すサーバにストリームを接続する

## サーバ側の socket API

流れ

1. socket(2)
2. bind(2)
3. listen(2)
4. accept(2)

## 名前解決

#### getaddrinfo(3)

ホスト名・サービス名からIPアドレス、ポート番号を得る

## インターネットスーパーサーバ inetd, xinetd

ネットワーク接続部分だけを引き受けることができる特別なサーバ  
指定されたポートで待ち、クライアントが接続してくるのを待つ

