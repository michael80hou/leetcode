#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int rotatedString(char *s, char *d)
{
    assert(s);
    assert(d);

    int len_s = strlen(s);
    int len_d = strlen(d);
    int res = 0;

    if(len_s != len_d) {
        return res;
    }

    char *rotatedStr = calloc(sizeof(char), (len_s + 1));
    assert(rotatedStr);

    char *tmpd = calloc(sizeof(char), (len_s + 1));
    assert(tmpd);

    strncpy(tmpd, d, len_d + 1);

    for(int j = 0; j < len_s; j++) {    
        for(int i = 0; i < len_s; i++) {
            if(i == len_s - 1) {
                rotatedStr[i] = tmpd[0];
            } else {
                rotatedStr[i] = tmpd[i + 1];
            }        
        }

        strncpy(tmpd, rotatedStr, len_d + 1);
        if(strncmp(s, rotatedStr, len_s) == 0) {
            res = 1;
            break;
        }
           
    }

    if(rotatedStr) {
        free(rotatedStr);
        rotatedStr = NULL;
    }

    if(tmpd) {
        free(tmpd);
        tmpd = NULL;
    }

    return res;
}




int main()
{
    char s[] = {"ABBFG"};
    char d[] = {"GABBF"};
    int res = 0;
    res =  rotatedString((char *) &s, (char *) &d);
    printf("%d\n", res);

    return 0;

}


