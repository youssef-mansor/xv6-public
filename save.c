#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  if(argc != 3){
    printf(2, "Usage: save <file_name> <string>\n");
    exit();
  }

  char *file_name = argv[1];
  char *string = argv[2];

  int fd = open(file_name, O_WRONLY | O_CREATE);
  if(fd < 0){
    printf(2, "save: cannot open %s\n", file_name);
    exit();
  }

  if(write(fd, string, strlen(string)) != strlen(string)){
    printf(2, "save: write error\n");
    exit();
  }

  close(fd);
  exit();
}
