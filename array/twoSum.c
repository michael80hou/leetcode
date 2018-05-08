#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct hash_node
{
  int key;
  int index;
}hash_node;

typedef struct hash_map
{
  hash_node** hash_table;
  int size;
}hash_map;

hash_map* create_hash(int size)
{
    hash_map* hash_map_ptr = malloc(sizeof(hash_map));  
    assert(hash_map_ptr);
    
    hash_node** hash_table_ptr = calloc(size, sizeof(hash_node*));
    assert(hash_table_ptr);
    
    hash_map_ptr->size = size;
    hash_map_ptr->hash_table = hash_table_ptr;    
    return hash_map_ptr;
}

inline int hash(int key, int size)
{
    return (abs(key) % size);
}

void add_hash(hash_map* hash_map_ptr, int key, int index)
{
    assert(hash_map_ptr);
    assert(index >= 0);
    int hash_index = hash(key, hash_map_ptr->size);
    hash_node* node_ptr = NULL;

    while(hash_map_ptr->hash_table[hash_index])
    {
        if(hash_index < hash_map_ptr->size - 1)
        {
            hash_index++;
        }
        else
        {
            hash_index = 0;
        }
    }

    node_ptr = malloc(sizeof(hash_node));
    assert(node_ptr);
    node_ptr->index = index;
    node_ptr->key = key;  
    hash_map_ptr->hash_table[hash_index] = node_ptr;
}

hash_node* search_hash(hash_map *hash_map_ptr, int key, int exclude_index)
{
    assert(hash_map_ptr);
    assert(exclude_index >= 0);

    //t search_count = 1;
    int match = 0;
    int hash_index = hash(key, hash_map_ptr->size);
    hash_node* hash_node_ptr = hash_map_ptr->hash_table[hash_index];

    while(hash_node_ptr)
    {
        if(hash_node_ptr->key == key && hash_node_ptr->index != exclude_index)
        {
            match = 1;
            break;
        }
        else
        {
            hash_index++;
            hash_index = (hash_index == hash_map_ptr->size ? 0 : hash_index); 
            hash_node_ptr = hash_map_ptr->hash_table[hash_index];
        }   
    }

    if(match == 0)
    {
        hash_node_ptr = NULL;
    }
    return hash_node_ptr;
}

void destroy_hash(hash_map* hash_map)
{
    assert(hash_map);
    int i = 0;

    if(hash_map->hash_table != NULL)
    {
        for(i = 0; i < hash_map->size; i++)
        {
            if(hash_map->hash_table[i])
            {
                free(hash_map->hash_table[i]);
                hash_map->hash_table[i] = NULL;
            }
        }
        free(hash_map->hash_table);
        hash_map->hash_table = NULL;
    }

    free(hash_map);
    hash_map = NULL;
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

    struct hash_map* hash_map_ptr = NULL;
    struct hash_node* node_ptr = NULL;
    hash_map_ptr = create_hash(numsSize);

    int i = 0;
    int key = 0;
    for(i = numsSize - 1; i >= 0; i--)
    {
        key = target - nums[i];
        node_ptr = search_hash(hash_map_ptr, key ,i);
        if(node_ptr)
        {
            result[0] = i;
            result[1] = node_ptr->index;
            break;
        }
        else
        {
            add_hash(hash_map_ptr, nums[i], i);
        }
    }
    
    destroy_hash(hash_map_ptr);
    return result;
}



int main()
{
    int test[] = {-1, -2, -3, -4, -5};
    int size = sizeof(test)/sizeof(int);
    int *res = NULL;

    res =  twoSum(test, size, -8);    
    printf("%d %d\n", res[0], res[1]);
    return 0;
    
}
