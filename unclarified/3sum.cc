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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>::size_type i = 0;
        std::sort(nums.begin(), nums.end());
        
        for(i = 0; i < nums.size(); i++) {

            int target = -nums[i];
            int rear = nums.size() - 1;
            int front = i + 1;

            while(front < rear) {
                int sum = nums[front] + nums[rear];

                if(sum > target) {
                    rear--;
                } else if(sum < target){
                    front++;
                } else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[rear];
                    res.push_back(triplet); 

                    while (front < rear && nums[front] == triplet[1]) front++;
                    while (front < rear && nums[rear] == triplet[2]) rear--;
                }  
            }

            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) { i++; }
         
        }
        return res;       
    }

};

int main()
{
    vector<int> test = {0,0,0,0};
    vector<vector<int>> res;

    vector<vector<int>>::size_type i = 0, j = 0;

    class Solution* ptr = new Solution();
    res =  ptr->threeSum(test);

    for (i = 0; i < res.size(); i++)
    {
        for (j = 0; j < res[i].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    return 0;

}




