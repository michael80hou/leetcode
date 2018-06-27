#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


int maxArea(int* height, int heightSize) {
    assert(height != NULL && heightSize >= 2);

    int l = 0, r = heightSize - 1;
    int max = 0;

    while(l < r) {
        int tmp = (r - l) * (height[r] > height[l] ? height[l] : height[r]);
        max = max > tmp ? max : tmp;

        if(height[r] > height[l]) {
            l++;
        } else {
            r--;
        }
    }

    return max;

}


int main()
{
    int test[] = {1, 2, 3, 4, 5};
    int size = sizeof(test)/sizeof(int);
    int res = 0;

    res =  maxArea(test, size);
    printf("%d \n", res);
    return 0;

}
