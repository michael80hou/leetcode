#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* convert(char* s, int numRows) {
    assert(s && numRows > 0);
    if(numRows == 1) {return s;}

    int len = strlen(s);
    int i = 0, j = 0;
    char *res = malloc(len + 1);
    assert(res);
    res[len] = '\0';
    char *p = res;
    
    for(i = 0; i < numRows; i++) {
        for(j = 0; 2 * j * (numRows - 1) + i < len; j++) {
            *p++ = s[2 * j * (numRows - 1) + i];
            if(i != 0 && i != numRows -1 &&  2 * (j + 1) * (numRows - 1) - i < len) {
                *p++ = s[2 * (j + 1) * (numRows - 1) - i];
            }
        }     
    }

    return res;     
}




int main()
{
    char test[] = {"PAYPALISHIRING"};
    char* res = NULL;
    res =  convert((char *) &test, 4);
    printf("%s\n", res);
    if(res) {
        free(res);
        res = NULL;
    }
    return 0;

}


