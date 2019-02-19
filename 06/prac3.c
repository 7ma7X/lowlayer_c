#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048

int main(int argc, char* argv[]) {
  for (int i=1;i<argc;++i) {
    FILE *f;
    int c;
    unsigned char buf[BUFFER_SIZE];
    size_t size = 4;
    size_t nmemb = 4;

    f = fopen(argv[i], "r");

    if(!f) {
      perror(argv[i]);
      exit(1);
    }

    while ((c = fread(buf, size, nmemb, f)) == nmemb) {
      fwrite(buf, size, nmemb, stdout);
    }

    if (ferror(f)) {
      exit(1);
    }

    fclose(f);
  }

  exit(0);
}