#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

void sighandler(int sig){
  if (sig == SIGINT){
    int file = open("sigmsg.txt", O_CREAT|O_RDWR|O_APPEND, 0644);
    char msg[] = "main.c exited due to SIGINT\n";
    write(file, msg, sizeof(msg));
    close(file);
    exit(1);
  }
  else if (sig == SIGUSR1){
    printf("Parent PID: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);  
  signal(SIGUSR1, sighandler);
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
