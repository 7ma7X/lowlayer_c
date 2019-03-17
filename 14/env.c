#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/* 自プロセスの環境変数一覧を表示する */

int main(int argc, char *argv[]) {
  char **p;

  for (p = environ; *p; p++) {
    printf("%s\n", *p);
  }

  exit(0);
}