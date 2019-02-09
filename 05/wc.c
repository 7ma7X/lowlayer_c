#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

static void do_wc(const char *path);
static void die(const char *path);

int main(int argc, char *argv[]) {
  int i;
  if (argc < 2) {
    fprintf(stderr, "%s: file name not given\n", argv[0]);
    exit(1);
  }
  for (i=1;i<argc;++i) do_wc(argv[i]);
  exit(0);
}

static void do_wc(const char *path) {
  int fd;
  unsigned char buffer[BUFFER_SIZE];
  int n;
  int line_num = 0;

  fd = open(path, O_RDONLY);
  if (fd < 0) die(path);

  for(;;) {
    n = read(fd, buffer, sizeof buffer);
    if (n < 0) die(path);
    if (n == 0) break;

    for(int i=0;i<BUFFER_SIZE;++i) {
      if(buffer[i] == 10) ++line_num;
    }
  }

  fprintf(stdout, "%d", line_num+1);
}

static void die(const char *s) {
  perror(s);
  exit(1);
}