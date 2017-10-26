
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 30
#define MAXARR 11



int main(int argc, char * argv[]){
  pid_t pid;
  char *s=malloc(sizeof(char)*MAX);
  char *token1;
  int elem=0, status=0;
  char path[MAX]="/bin/";
  char *buf;
  char **array=malloc(sizeof(char*)*MAXARR);
  int ex=0;
  while(1){
    fgets(s,MAX,stdin);
    s[strlen(s)-1]='\0';
    if(strcmp(s,"exit")==0){
      exit(0);
    }


    if((pid=fork())==-1){
      perror("Error");
      exit(EXIT_FAILURE);
    }

    else if(pid==0){
      if((token1=strtok_r(s," ",&buf))!=NULL){
        array[elem]=malloc(sizeof(char)*MAX);
        array[elem]=token1;
        elem++;
      }
      while(token1){
        if((token1=strtok_r(NULL," ",&buf))!=NULL){
          array[elem]=malloc(sizeof(char)*MAX);
          array[elem]=token1;
          elem++;
        }
      }


  

      strcat(path, array[0]);
      errno=0;
      int i=0;

      execv(path,array);
      if(errno!=0){
        printf("errore");
      }


    }

    else{
      waitpid(pid,&status,0);
    }
  }


  return 0;
}
