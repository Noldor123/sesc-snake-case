#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char * str;
  char newstr[1000];
  int underline = 0, shift = 0;
  size_t strSize = 1000*sizeof(char);
  while (getline(&str, &strSize, stdin)){
    for(int i=0;i<strlen(str)-1;i++){
      if (str[i]<='Z' && str[i]>='A'){
        if (i>=1 && str[i-1]!='_'){
          newstr[i+shift]='_';
          shift++;
        }
        newstr[i+shift]=str[i]+32;
        underline = 0;
      }else if(str[i]=='_'){
        if (underline == 0){
          newstr[i-shift]=str[i];
          underline = 1;
        }else{
          shift++;
        }
      }else if (str[i]<='z' && str[i]>='a'){
        newstr[i+shift]=str[i];
        underline = 0;
      }
    }
    printf("%s\n", newstr);
    memset(&newstr, 0, strSize);
    shift = 0;
    free(str);
  }
}
