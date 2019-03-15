#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  pid_t pid;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <command> <arg>\n", argv[0]);
    exit(1);
  }

  pid = fork();
  /* fork() 失敗時 */
  if (pid < 0) {
    fprintf(stderr, "fork(2) failed\n");
  }
  if (pid == 0) { /* 子プロセス */
    execl(argv[1], argv[1], argv[2], NULL);
    /* execl() が呼び出しから戻ったら失敗 */
    perror(argv[1]);
    exit(99);
  } else { /* 親プロセス */
    int status;

    waitpid(pid, &status, 0);
    printf("child (PID=%d) finished", pid);

    /**
     * WIFEXITED は exit で終了していたら非0 
     * WEXITSTATUS は exit で終了していたとき、終了コードを返す
     * 
     * WIFSIGNALED はシグナルで終了していたら非0
     * WTERMSIG はシグナルで終了していたとき、シグナル番号を返す
     */
    if (WIFEXITED(status))
      printf("exit, status=%d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
      printf("signal, sig=%d\n", WTERMSIG(status));
    else
      printf("abnoraml exit\n");

    exit(0);
  }
}