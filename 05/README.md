#### ストリームに関わるシステムコール

`read`  
`write`  
`open`  
`close`

#### ファイル記述子

カーネルの中にはストリームがあるが、これを番号と対応づけ、プロセスは番号でストリームを指定する

#### STDIN, STDOUT, STDERR

この3つのストリームはどのプロセスにも用意され、ファイル記述子は0, 1, 2で固定されている

#### read(2)

ストリームからバイト列を読み込む

#### write(2)

ストリームにバイト列を書き込む

#### open(2)

ファイルに接続するストリームを作る

#### close(2)

ストリームを始末する

#### perror(3)

errnoの値に合わせたエラーメッセージを出力する

#### ファイルオフセット

ストリームがファイルとつながっている位置のこと

#### lseek(2)

ファイルオフセットを操作するシステムコール  
SEEK_SET: offsetに移動  
SEEK_CUR: 現在のオフセット+offsetに移動  
SEEK_END: ファイル末尾+offsetに移動

#### dup(2) dup2(2)

ファイル記述子を複製

#### ioctl(2)

デバイスに特化した操作（特殊な操作全般）  

#### fcntl(2)

特殊な操作のうち、ファイル記述子にかかわるものを分離して作られたもの