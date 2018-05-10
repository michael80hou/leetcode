#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;
typedef std::unordered_multimap<int, std::pair<int, int>>::iterator hash_iterator;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result(2, -1);
        vector<int>::size_type i = 0;

        std::unordered_multimap<int, std::pair<int, int>> hash;
        vector<int>::size_type numsSize = nums.size();
        
    	for(i = 0; i < numsSize; i++)
    	{
    		int key = target - nums[i];
    		if(hash.count(key) == 0)
    		{
    		    hash.insert(std::make_pair(nums[i], std::make_pair(i, nums[i])));
    		}
    		else
    		{
    		    std::pair<hash_iterator, hash_iterator> candidate = hash.equal_range(key);
    		    while(candidate.first != candidate.second)
    		    {
    		        if(candidate.first->second.first != (int)i && candidate.first->second.second == key)
    		        {
    		            result[0] = candidate.first->second.first;
    		            result[1] = i;
    		        }

    		        candidate.first++;
    		    }
    		}
    	}

        return result;        
        
    }
};

#if 0
typedef std::unordered_multimap<int, std::pair<int, int>>::iterator hash_iterator;
int* twoSum(int* nums, int numsSize, int target) {
    assert(nums);
    assert(numsSize > 0);

    int* result = NULL;
	result = new int[2];
	assert(result);
	result[0] = -1;
	result[1] = -1;

	std::unordered_multimap<int, std::pair<int, int>> hash;
	for(int i = 0; i < numsSize; i++)
	{
		int key = target - nums[i];
		if(hash.count(key) == 0)
		{
		    hash.insert(std::make_pair(nums[i], std::make_pair(i, nums[i])));
		}
		else
		{
		    std::pair<hash_iterator, hash_iterator> candidate = hash.equal_range(key);
		    while(candidate.first != candidate.second)
		    {
		        if(candidate.first->second.first != i && candidate.first->second.second == key)
		        {
		            result[0] = candidate.first->second.first;
		            result[1] = i;
		        }

		        candidate.first++;
		    }
		}
	}

    return result;
}
#endif
int main()
{

    //int test[] = {-1, -2, -3, -4, -5};
    //int size = sizeof(test)/sizeof(int);
    //int *res = NULL;
    std::vector<int> test(5, 0);
    test[0] = -1;
    test[1] = -2;
    test[2] = -3;
    test[3] = -4;
    test[4] = -5;

    std::vector<int> res;

    class Solution* ptr = new Solution();
    

    res =  ptr->twoSum(test,-8); 
    std::cout<<res[0]<<" "<<res[1]<<std::endl;
    //printf("%d %d\n", res[0], res[1]);
    return 0;
    
}
