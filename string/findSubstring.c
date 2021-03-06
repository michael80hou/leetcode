#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


#if 0
#define HASH_BIT_START 0
#define ARRAY_INIT_SIZE 8

struct hash_item_s{
	char *s;
	int ref;
	int count;
	int tag;
	struct hash_item_s *next;
};

struct hash_ctrl_s{
	struct hash_item_s **items;
	int tag;
	int key_mask;
	int byte_len;
	int size;
};

#define ASSERT(_val) do{if (!(_val)) exit(-1);}while(0)

static int leet_roundup(int value)
{
	int bit_len = 0;
	int temp;

	temp = value;
	while (temp != 0){
		temp >>= 1;
		bit_len++;
	}

	if ((1 << bit_len) == value){
		bit_len--;
	}
	return bit_len;
}


static struct hash_ctrl_s *leet_hash_init(int count, int byte_len)
{
	struct hash_ctrl_s *hash;
	int bit_len;

	hash = malloc(sizeof(struct hash_ctrl_s));
	ASSERT(hash);

	bit_len = leet_roundup(count << 1);
	hash->size = 1 << bit_len;
	hash->key_mask = (1 << bit_len) - 1;
	hash->byte_len = byte_len;
	hash->tag = 0;
	hash->items = malloc(sizeof(long) * hash->size);
	ASSERT(hash->items);
	memset(hash->items, 0, sizeof(long) * hash->size);

	return hash;
}

static int leet_hash_key(struct hash_ctrl_s *hash, char *s)
{
	int key = 1;
	int value = 0;
	int i, j;

	for (i = 0; i < hash->byte_len - 3; i += 4){
		value = s[i];
		value = (value << 4) | s[i + 1];
		value = (value << 4) | s[i + 2];
		value = (value << 4) | s[i + 3];
		key *= value;
	}

	for (j = i; j < hash->byte_len; j++){
		key *= s[j];
	}

	value = key;
	key = value & 0xff;
	key += (value >> 8) & 0xff;
	key += (value >> 16) & 0xff;
	key += (value >> 24) & 0xff;

	return key & hash->key_mask;
}

static void leet_hash_add(struct hash_ctrl_s *hash, char *s)
{
	int key;
	struct hash_item_s *item, **room;

	key = leet_hash_key(hash, s);
	item = hash->items[key];
	room = &hash->items[key];
	while (item){
		if (strcmp(item->s, s) == 0){
			break;
		}
		room = &item->next;
		item = item->next;
	}

	if (!item){
		item = malloc(sizeof(struct hash_item_s));
		ASSERT(item);
		item->s = s;
		item->tag = 0;
		item->count = 1;
		item->ref = 1;
		item->next = NULL;
		*room = item;
	}else{
		item->count++;
		item->ref++;
	}
}

static bool leet_find_substring_in_hash(struct hash_ctrl_s *hash, 
	char *s)
{
	int key;
	struct hash_item_s *item;

	key = leet_hash_key(hash, s);
	item = hash->items[key];

	while (item){
		if (!strncmp(s, item->s, hash->byte_len)){
			if (item->tag == hash->tag){
				if (item->ref != 0){
					item->ref--;
					return true;
				}
			}else{
				item->tag = hash->tag;
				item->ref = item->count;
				item->ref--;
				return true;
			}
		}
		item = item->next;
	}

	return false;
}

static bool leet_hash_find(struct hash_ctrl_s *hash, char *s, int count)
{
	int i;
	bool rt = true;;
	
	for (i = 0; i < count; i++){
		if (!leet_find_substring_in_hash(hash, s)){
			rt = false;
			break;
		}
		s += hash->byte_len;
	}

	hash->tag++;
	return rt;
}

static void leet_add_array(int **array, int val, int index)
{
	static int array_len = 0;

	if (index == 0){
		array_len = 0;
	}

	if (index == array_len){
		array_len += ARRAY_INIT_SIZE;
		*array = realloc(*array, array_len);
	}

	(*array)[index++] = val;
}

int *findSubstring(char* s, char** words, int wordsSize, 
	int* returnSize)
{
	struct hash_ctrl_s *hash;
	int i;
	int len, slen, byte_len;
	int *rt_array = NULL;
	int rt_size = 0;

	if (s == NULL || wordsSize == 0){
		return NULL;
	}

	byte_len = strlen(words[0]);
	hash = leet_hash_init(wordsSize, byte_len);
	ASSERT(hash);

	for (i = 0; i < wordsSize; i++){
		leet_hash_add(hash, words[i]);
	}

	len = byte_len * wordsSize;
	slen = strlen(s);
	for (i = 0; slen >= len; i++, slen--){
		if (leet_hash_find(hash, s + i, wordsSize)){
			leet_add_array(&rt_array, i, rt_size);
			rt_size++;
		}
	}

	*returnSize = rt_size;
	return rt_array;
}

#else

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
#endif

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


