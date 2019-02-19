#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  for (int i=1;i<argc;++i) {
    int c;
    FILE *f;

    f = fopen(argv[i], "r");

    if (!f) {
      perror(argv[i]);
      exit(1);
    }

    int count = 1;
    int tmp = 0;

    while ((c = fgetc(f)) != EOF) {
      if (c == '\n') {
        ++count;
        tmp = 1;
      } else {
        tmp = 0;
      }
    }

    if (tmp == 1) {
      --count;
    }

    fclose(f);

    printf("%d", count);
  }

  exit(0);
}