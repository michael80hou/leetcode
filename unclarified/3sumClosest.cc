#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::vector;
using std::unordered_multimap;
using std::unordered_map;

using std::pair;

class Solution {
public: 
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        vector<int>::size_type i = 0;

        for(i = 0; i < nums.size(); i++) {
            int rear = nums.size() - 1;
            int front = i + 1;

            while(front < rear) {
                int sum = nums[i] + nums[front] + nums[rear];
                if(abs(sum - target) < abs(res - target)) {
                    res = sum;
                }

                if(sum > target) {
                    rear--;
                } else if(sum < target){
                    front++;
                } else {
                    return target;
                }  
            }
        }

        return res;
    }
    
};

int main()
{
    vector<int> test = {-1, 2, 1, -4};
    int res;
    class Solution* ptr = new Solution();
    res =  ptr->threeSumClosest(test, 1);
    std::cout << res << std::endl;

    return 0;

}




