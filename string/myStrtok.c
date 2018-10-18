#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *mystrtok(char *str, const char *delim) {

    static int start = 0;
    static char *ptr = NULL;
    char *res = NULL;
    int delim_len = strlen(delim);

    if(str) {
        start = 1;
        ptr = str;
        res = str;       
    } else {
        if(1 == start) {            
            res = ptr;
        } else {
            ptr = NULL;
            res = NULL;           
        }
    }

    if(res) {
        char *tmp = ptr;
        while(strncmp(tmp, delim, delim_len) && *tmp != '\0') {
            tmp++;
        }

        if('\0' == *tmp) {
            start = 0;
        } else {
            *tmp = '\0';
            ptr = tmp + delim_len;
        }
    }
    
    return res;    
}




int main () {
   char str[80] = "This is - www.runoob.com - website";
   const char s[10] = "runoob";
   char *token;
   

   token = mystrtok(str, s);

   while( token != NULL ) {
      printf( "%s\n", token );
    
      token = mystrtok(NULL, s);
   }
   
   return(0);
}



