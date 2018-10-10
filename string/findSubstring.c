#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int len_s = strlen(s);
    int wordsLen = strlen(words[0]);
    if(0 == len_s || 0 == wordsSize || len_s < wordsLen * wordsSize) {
        *returnSize = 0;
        return NULL;
    }

    int *flags = calloc(sizeof(int), wordsSize);
    if(NULL == flags) {
        return NULL;
    }

    int *res = calloc(sizeof(int), len_s);
    if(NULL == res) {
        return NULL;
    } 
    int res_index = 0;

    int (*table)[len_s] = calloc(len_s * sizeof(int), wordsSize);
    if(NULL == table) {
        return NULL;
    }
    
    int left = 0, right = wordsLen * wordsSize;    
    for(; right <= len_s; left++, right++) {
        memset(flags, 0, sizeof(int) * wordsSize);
        int valid = 1;
        for(int i = left; i < right; i += wordsLen) {
            int hit = 0;
            for(int j = 0; j < wordsSize; j++) {
                if(0 == flags[j]) {
                        if(0 == table[j][i]){
                            if(0 == strncmp(s + i, words[j], wordsLen)) {
                                flags[j] = 1;
                                table[j][i] = 1;
                                hit = 1;
                                break;  
                            } else {
                                table[j][i] = -1; 
                            }
                            
                        } else if(1 == table[j][i]) {
                                flags[j] = 1;
                                hit = 1;
                                break;                             
                        }

                } else {
                    continue;
                }
          
            }

            if(0 == hit) {
                valid = 0;
                break;
            }
                
        }


        if(1 == valid) {
            res[res_index++] = left;
        }
        
    }

    *returnSize = res_index;

    if(flags) {
        free(flags);
        flags = NULL;        
    }

    if(table) {
        free(table);
        table = NULL;        
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


