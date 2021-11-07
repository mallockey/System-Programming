#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

void writeToFile() {

  int fd, fd2, numOfReads;
  char buffer[100];

  fd = open("./testfiles/RandomText.txt", O_RDWR | O_CREAT, 0777);
  fd2 = open("./testfiles/modified_text.txt", O_RDWR | O_CREAT, 0777);

  if ((fd | fd2) < 0) {
    printf("Error opening file\n");
  }

  int readCount = read(fd, buffer, 100);

  while(readCount > 0) {
    //Logic for writing to modified_text.txt

    write(fd2, buffer, 100);

    readCount = read(fd, buffer, 1);
    numOfReads++;
  }

  if (close(fd) | close(fd2) < 0) {
    printf("Error closing the files");
    exit(1);
  }
}

void readFromFile() {
  int fd;
  char buffer[100];

  fd = open("./testfiles/RandomText.txt", O_RDONLY, 0777);

  if (fd < 0) {
    printf("Error, reading file");
    exit(1);
  }

  int readCount;
  readCount = read(fd, buffer, 100);

  if (readCount < 0) {
    printf("Error");
    exit(1);
  } else {
    printf("%i", readCount);
    printf("%.*s\n", readCount, buffer);
  }
}

int main()
{
  writeToFile();
  readFromFile();
  return 0;
}