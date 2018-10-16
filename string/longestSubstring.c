#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int characterReplacement(char* s, int k) {
    assert(s);
    assert(k>=0);

    int letter_map[26] = {0};
    int len = strlen(s);
    if(len == 0) {
        return 0;
    }

    if(k >= len) {
        return len;
    }

    int l = 0, r = k;
    int max = 0;
    int res = 0;

    for(int l = 0; l < len - k; l++) {
        for(int i = l; i < len; i++) {
            int index = s[i] - 'A';
            letter_map[index]++;
            max = max > letter_map[index] ? max : letter_map[index]; 

            int num = i - l + 1;
            if(num - max > k) {
                res = res > num -1 ? res : num - 1;
                break;
            }
        }
    }

    return res;
    
}


int main()
{
    int* res = NULL;
    char* s = "barfoothefoobarman";
    char* words[2] = {"foo","bar"};

    int size = 0;
    res =  findSubstring(s, (char**)&words, 2, &size);

    printf("%d \n", size);
    for(int i = 0; i < size; i++) {
        printf("%d ", res[i]);
    }

    printf("\n");
    
    return 0;

}


