#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>


int myAtoi(char* str) {
    assert(str);

    int sign = 1;
    long long res = 0;
    char e;
    while(*str == ' ') {
        str++;
    }

    if(*str == '-') {
        sign = -1;
        str++;
    } else if(*str == '+') {
        str++;
    }
    

    while((e = *str++)) {
        if(e >= '0' && e <= '9') {
            if(sign == 1) {
                res = (e - '0') + res * 10;
                if(res >= INT_MAX) {
                    res = INT_MAX;
                    break;
                }
            } else {
                res = -(e - '0') + res * 10;
                if(res <= INT_MIN) {
                    res = INT_MIN;
                    break;
                }
            }
            
        } else {
            break;
        }
    }
    
    return (int)res;
    
}





int main()
{
    char test[] = {"-91283472332"};
    int res = 0;
    res =  myAtoi((char *) &test);
    printf("%d\n", res);

    return 0;

}


