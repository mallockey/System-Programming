#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

void initializeFork() {
  
  int pid;
  pid = fork();
  if (pid == 0) {
    printf("Hello from the child --- PID %d --- Parent PID: %d\n", getpid(), getppid());
    sleep(10);
  } else {
    wait(NULL);
    printf("Hello from the Parent --- PID: %d --- Child PID: %d\n", getpid(), pid);
  }

}

void callFromProgram() {
  int pid,y,z; 
  char *arg[5] = {"gcc","-o","hello_world","HelloWorld.c", 0};
  pid = fork();

  if (pid == 0) {
    execv("/usr/bin/gcc", arg);
  }

  y = wait(&z);
  exit(0);
}

int main() {
  callFromProgram();
  return(0);
}

