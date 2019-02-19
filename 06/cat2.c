#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  for (int i=1;i<argc;i++) {
    FILE *f;
    int c;

    f = fopen(argv[i], "r"); // 失敗時にはNULLを返す

    if (!f) {
      perror(argv[i]); // perror は errno の値に合わせたエラーメッセージを返す
      exit(1);
    }

    while ((c = fgetc(f)) != EOF) {
      if (putchar(c) < 0) exit(1);
      // putcharはエラーの時 EOF(-1) を返す
    }
    fclose(f);
  }
  exit(0);
}