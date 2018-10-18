#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *mystrtok(char *str, const char *delim) {
    if('\0' == *delim) {
        return str;
    }

    static char *_buffer = NULL;
    char *ret = NULL;
    _buffer = str ? str: _buffer;
    
    if(NULL == _buffer || '\0' == _buffer[0]) {
        return NULL;
    }

    int stop = 0, found = 0;
    ret = _buffer;

    for(char *b = _buffer; *b != '\0'; b++) {
        for(const char *d = delim; *d != '\0'; d++) {
            if(*b == *d) {
                found = 1;
                *b = '\0';
                _buffer = b + 1;

                if(b == ret) {
                    ret++;
                } else {
                    stop = 1;
                }
                
                break;
            }          
        }

        if(stop) break;
   }


    if(0 == found)
        _buffer = NULL;

    if('\0' == *ret) {
        ret = NULL;
    }
    
    return ret;    
}




int main () {
   char str[80] = "AAAA";
   const char s[10] = "A";
   char *token;
   

   token = strtok(str, s);

   while( token != NULL ) {
      printf( "%s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}



