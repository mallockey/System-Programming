#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

int main()
{
  // Attempting to print out directories
  DIR *dirp = opendir("./test");  
  struct dirent * dir = readdir(dirp);

  // Write to file using System Calls
  int file;
  file = open("newfile.txt", O_RDWR | O_CREAT, 0750);
             //Name of file, File Descriptors, Permissions

  if (file < 0) {
    printf("Error!\n");
    exit(1);
  } else {
    char *outMessage = "We have written to the system correctly!\n";
    // Print to console with system calls
    write(STDOUT_FILENO, outMessage, strlen(outMessage));
  }
  return 0;
}