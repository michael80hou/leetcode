#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int reverse(int x) {
    long long  res = 0;
    while(x) { 
        res = res * 10 +x % 10;
        if(res > INT_MAX || res < INT_MIN) {return 0;}
        x /= 10;
    }

    return res;    
}


int main()
{
    int i = -2147483648;
    int res = reverse(i);

    printf("res %d\n", res);
    return 0;
}
