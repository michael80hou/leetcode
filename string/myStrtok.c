#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *mystrtok(char *str, const char *delim) {
    

    return NULL;
    

    
}




int main () {
   char str[80] = "This is - www.runoob.com - website";
   const char s[2] = "-";
   char *token;
   

   token = strtok(str, s);

   while( token != NULL ) {
      printf( "%s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}



