#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    assert(s);
    int slide_left = 0, slide_right = 0;
    int max = 0;
    char hash[256] = {0};    
    
    while(*(s + slide_right) != '\0')
    {
        if(hash[(int)*(s + slide_right)] == 0)
        {
            hash[(int)*(s + slide_right)] = 1;
            slide_right++;
        }
        else
        {
            hash[(int)*(s + slide_left)] = 0;
            slide_left++;
        }

        max = (slide_right - slide_left) > max ? (slide_right - slide_left) : max;
    }
    
    return max;
}



int main()
{
    char* test = "aab";

    int res;
    res =  lengthOfLongestSubstring(test);
    printf("%d\n", res);
    return 0;

}


