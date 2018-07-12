#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* intToRoman(int num) {
    assert(num >= 1 && num <= 3999);
    char *roman[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                         {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                         {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                         {"", "M", "MM", "MMM", "", "", "", "", "", ""}}; 

    char *p = malloc(100);
    assert(p);
    memset(p, 0, 100);

    int a3, a2, a1, a0; //num = a3a2a1a0
    int tmp = num;

    a3 = num / 1000;
    tmp %= 1000;

    a2 = tmp / 100;
    tmp %= 100;

    a1 = tmp / 10;
    tmp %= 10;

    a0 = tmp;

    if(a3) { strcat(p, roman[3][a3]); }

    if(a2) { strcat(p, roman[2][a2]); }

    if(a1) { strcat(p, roman[1][a1]); }

    if(a0) { strcat(p, roman[0][a0]); }

    
    return p;    
}




int main()
{
    int num = 1994;
    char *res = NULL;

    res =  intToRoman(num);
    printf("%s\n", res);
    return 0;

}
