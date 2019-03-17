## プロセスの属性

- カレントディレクトリ
- クレデンシャル
- 環境変数
- 使用リソース

## カレントディレクトリ

プロセスには「今いるディレクトリ」という属性が用意されている。

#### getcwd(3)

カレントディレクトリのパスを得る関数

パスのためのバッファの確保の仕方は、とりあえず malloc() である程度確保し、足りなかったら realloc() でバッファを増やすのが正しい。使い終わったら free() する

#### chdir(2)

自プロセスのカレントディレクトリを変更する

## 環境変数

プロセスの親子関係を通じて伝播するグローバル変数、と言える

#### environ

環境変数を指し示す。char** 型

```c
extern char **environ;
```

と宣言する必要がある。

#### getenv(3)

環境変数 name の値を検索して返す

#### putenv(3)

環境変数の値をセットする

## クレデンシャル

#### set-uidビット

ファイルパーミッションのset-uidビットを立てると、そのプログラムを、起動したユーザにかかわらずプログラムファイルのオーナーの権限で起動される。  
起動した方のユーザIDを**実ユーザID（real user ID）**、set-uidプログラムのオーナーのIDの方を**実効ユーザID（effective user ID）**と呼ぶ。  
ユーザーだけでなくグループにも同様のものがある。

#### クレデンシャルを得るシステムコール

- `getuid()` 自プロセスの実ユーザID
- `geteuid()` 自プロセスの実効ユーザID
- `getgid()` 自プロセスの実グループID
- `getegid()` 自プロセスの実効グループID
- `getgroups()` 自プロセスの補足グループIDをbufに書き込む

#### 別のクレデンシャルへの以降

- `setuid()`
- `setgid()`
- `initgroups()`

## ユーザ・グループ

クレデンシャルはプロセスの属性であり、管理しているのはカーネル。一方、ユーザやグループそれ自体の情報とカーネルは関係無い。

#### getpwuid(3), getpwnam(3)

`getpwuid()` はユーザ情報をユーザIDから検索する。`getpwnam()` はユーザ情報をユーザ名から検索する。

#### getgrgid(3), getgrnam(3)

`getgrgid()` はグループ情報をグループIDから検索する。`getgrnam()` はグループ情報をグループ名から検索する。

## リソース

#### getrusage(2)

自プロセスや子プロセスのリソース少量を得る。

**システム時間**: そのプロセスのためにカーネルが働いた時間  
**ユーザ時間**: プロセスが自分で消費した時間  
**メジャーフォールト**: 物理アドレスに結び付けられていない仮想アドレスにアクセスして、その結果として物理アドレスの割り当てが起こったもののうち、ストレージとの入出力が伴うもの  
**マイナーフォールト**: 物理アドレスに結び付けられていない仮想アドレスにアクセスして、その結果として物理アドレスの割り当てが起こったもののうち、ストレージとの入出力が伴わないもの

## 日付・時刻

1970年1月1日午前0時・・・**UNIXエポック**

#### time(2)

UNIXエポックから現在までの経過秒数を返す

#### gettimeofday(2)

UNIXエポックから現在までの経過時間を返す（time()より精度が高い）

#### localtime(3), gmtime(3)

人間にわかりやすい表記で年月日時分秒を返す  
localtime() がシステムのローカルゾーン、gmtime() が協定世界時

#### mktime(3)

struct tm で著された時刻を time_t に変換

#### asctime(3), ctime(3)

時刻を文字列に変換

#### strftime(3)

任意のフォーマットで時刻を文字列化する

#### 時刻フォーマット

**ISO 8601**が汎用的

## ログイン

流れ

1. systemd または init が端末の数だけ getty コマンドを起動
2. getty コマンドは端末からユーザ名が入力されるのを待ち、login コマンドを起動
3. loginコマンドがユーザを認証
4. シェルを起動