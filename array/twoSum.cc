#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::pair;

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
