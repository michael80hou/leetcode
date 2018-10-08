#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


bool isValid(char* s) {
    assert(s);
    int len = strlen(s);
    bool res = false;

    if(0 == len) {
        res = true;
    } else if(len % 2) {
        res = false;
    } else {
        res = true;
        int *stack = NULL;
        stack = calloc(sizeof(int), len);
        if(NULL == stack) {
            printf("calloc fails, fatal error!\n");
            res = false;
        } else {            
            char input = '\0';
            int index = 0;
            while((input = *s++)) {
                int stop = 0;
                switch(input) {
                    case '(':
                        stack[index++] = 0;
                        break;
                    case '[':
                        stack[index++] = 1;
                        break;                        
                    case '{':
                        stack[index++] = 2;
                        break;                         
                    case ')':
                        if(0 == index) {
                            stop = 1;
                        } else if(0 != stack[--index]){
                            stop = 1;
                        }
                        break;
                        
                    case ']':
                        if(0 == index) {
                            stop = 1;
                        } else if(1 != stack[--index]){
                            stop = 1;
                        }
                        break;                      
                    case '}':  
                        if(0 == index) {
                            stop = 1;
                        } else if(2 != stack[--index]){
                            stop = 1;
                        }

                        break;                    
                    default: 
                        stop = 1;
                        break;
                }

                if(1 == stop) {
                    res = false;
                    break;
                }
                
            }

            if(index != 0) {
                res = false;
            }
                
        }
    }

    return res;
}



int main()
{
    char *test = "()[]{}[][][}][][][][][]";

    int res =  isValid(test) == true ? 1 : 0;
    printf("%d \n", res);
    return 0;

}

