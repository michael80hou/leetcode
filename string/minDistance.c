#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int minDistance(char* word1, char* word2) {
    
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


