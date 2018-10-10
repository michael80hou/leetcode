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

#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::pair;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result = {-1, -1};
        vector<int>::size_type i = 0;

        unordered_map<int, int> umap;
    	  for(i = 0; i < nums.size(); i++)
    	  {
    		    int key = target - nums[i];
                auto iter = umap.find(key);
    		    if(iter == umap.end())
    		    {
    		        //umap.insert(std::make_pair(nums[i], i));
                    umap.insert(pair<int, int>{nums[i], i});
    		    }
    		    else
    		    {
    		       result[0] = iter->second;
    		       result[1] = i;
              break;
    		    }
    	   }

        return result;

    }
};

int main()
{
    std::vector<int> test{-1, -2, -3, -4, -5};
    std::vector<int> res{-1, -1};

    class Solution* ptr = new Solution();
    res =  ptr->twoSum(test,-8);
    std::cout<<res[0]<<" "<<res[1]<<std::endl;
    //printf("%d %d\n", res[0], res[1]);
    return 0;

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


