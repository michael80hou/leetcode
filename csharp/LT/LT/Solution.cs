using System;
using System.Collections.Generic;

namespace LT
{
    public class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> record = new Dictionary<int, int>();

            int[] res = new int[2];

            for (int i = 0; i < nums.Length; i++)
            {
                int curValue = nums[i];
                if (record.ContainsKey(curValue))
                {
                    continue;
                }
                else
                {
                    record[curValue] = i;

                    int t = target - curValue;
                    if (record.ContainsKey(t))
                    {
                        res[0] = i;
                        res[1] = record[t];
                        return res;
                    }
                }
            }

            return res;

        }
    }
}
