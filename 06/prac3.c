#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048

int main(int argc, char* argv[]) {
  for (int i=1;i<argc;++i) {
    FILE *f;
    int c;
    unsigned char buf[BUFFER_SIZE];
    size_t size = 1;
    size_t nmemb = sizeof buf;

    f = fopen(argv[i], "r");

    if(!f) {
      perror(argv[i]);
      exit(1);
    }

    for (;;) {
      c = fread(buf, size, nmemb, f);
      if (ferror(f)) {
        perror(argv[i]);
        exit(1);
      }

      size_t n = fwrite(buf, size, c, stdout);
      // 読めた分 c だけ書くのが大切だった
      if (n < c) {
        perror(argv[i]);
        exit(1);
      }
      if (c < nmemb) break;
    }

    fclose(f);
  }

  exit(0);
}