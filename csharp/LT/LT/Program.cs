using System;

namespace LT
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] intput = new int[3] { 3, 2, 4 };
            int target = 6;

            Solution s = new Solution();

            var res = s.TwoSum(intput, target);
            Console.WriteLine("{0}, {1}", res[0], res[1]);
        }
    }
}
