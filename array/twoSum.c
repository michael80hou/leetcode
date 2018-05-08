#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define HASH_CONSANT (0xffff)

struct hash_element
{
  unsigned int key;
  int index;
  struct hash_element* next;
};

struct hash_head
{
  struct hash_element* next;
};

struct hash_head* create_hash()
{
    struct hash_head* direct_map_hash = NULL;
    unsigned int hash_count = HASH_CONSANT + 1;
    unsigned int hash_size = sizeof(struct hash_head) * hash_count;    
    direct_map_hash = malloc(hash_size);
    assert(direct_map_hash);
    memset(direct_map_hash, 0, hash_size); 
    return direct_map_hash;
}

unsigned int hash(unsigned int key)
{
    unsigned int index = key & HASH_CONSANT;
    return index;
}

void add_hash(struct hash_head *hash_table, unsigned int key, unsigned int index)
{
    assert(hash_table);
    unsigned int hash_index = hash(key);
    struct hash_head* head = hash_table + hash_index;
    struct hash_element* element = NULL;    
    
    struct hash_element* add_ptr =  malloc(sizeof(struct hash_element)); 
    assert(add_ptr);
    add_ptr->key = key;
    add_ptr->index = index;
    add_ptr->next = NULL; 

    if(head->next)
    {
        element = head->next;
        while(element->next)
        {
            element = element->next;
        }
        element->next = add_ptr;
    }
    else
    {
        head->next = add_ptr;
    }
}

struct hash_element* search_hash(struct hash_head *hash_table, unsigned int key, unsigned int exclude_index)
{
    assert(hash_table);
    unsigned int hash_index = hash(key);
    struct hash_head* head = hash_table + hash_index;
    struct hash_element* element = NULL;
    int match = 0;

    if(head->next)
    {
        for(element = head->next; element; element = element->next)
        {
            if(element->key == key && element->index != exclude_index)
            {
                match = 1;
                break;
            }
        }
    }

    if(match == 0)
    {
        element = NULL;
    }
    
    return element;
}

void destroy_hash(struct hash_head *hash_table)
{
    assert(hash_table);
    int i = 0;
    struct hash_head* head = NULL;
    struct hash_element* element = NULL;
    struct hash_element* next = NULL;

    for(i = 0; i < HASH_CONSANT + 1; i++)
    {

        head = hash_table + i;
        if(head->next == NULL)
        {
            continue;
        }
        else
        {
            element = head->next;
            while(element->next)
            {
                next = element->next;
                free(element);
                element = next;
            }
            free(element);
        }
    }

    free(hash_table);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    assert(nums);
    assert(numsSize > 0);

    int* result = NULL;
    result = malloc(sizeof(int) * 2);
    assert(result);
    result[0] = -1;
    result[1] = -1;

    struct hash_head* hash_table = NULL;
    struct hash_element* element = NULL;
    hash_table = create_hash();

    int i = 0;
    unsigned int key = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        key = nums[i];
        add_hash(hash_table, key, i);
    }

    for(i = 0; i < numsSize; i++)
    {
        key = (unsigned int) (target - nums[i]);
        element = search_hash(hash_table, key ,i);
        if(element)
        {
            result[0] = i;
            result[1] = element->index;
            break;
        }
    }
    
    destroy_hash(hash_table);
    return result;
}


int main()
{
    int test[] = {-1, -2, -3, -4, -5};
    int size = sizeof(test)/sizeof(int);
    int *res = NULL;

    res =  twoSum(test, size, -8);
    
    //struct sub_max_res result;

    //sub_max(test, 0, size - 1, &result );

    //printf("max_sum = %d , left index %d, right index %d\n", result.max_sum, result.index_l, result.index_r);
    printf("%d %d\n", res[0], res[1]);
    return 0;
    
}
