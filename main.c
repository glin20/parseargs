#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_space(char *line){
  int i = 0;
  while (*line){
    if (*line == ' '){
      i++;
    }
    line++;
  }
  printf("%d\n", i);
  return i;
}

char **parse_args(char *line){
  char **args = malloc(sizeof(char *) * (count_space(line) + 2));
  char **front = args;
  char *seg;
  seg = strsep(&line, " ");
  while (seg){
    *args = seg;
    args++;
    seg = strsep(&line, " ");
  }
  return front;
}

int main(){
  char line[] = "ls -a -l";
  char **args = parse_args(line);
  execvp(args[0], args);
}