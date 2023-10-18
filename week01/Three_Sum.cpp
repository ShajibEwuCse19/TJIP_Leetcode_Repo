//TC: O(N^2)
//SC: O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;

        for(int i=0; i<nums.size(); i++)
        {
            int a = nums[i]; //find b+c where b+c will be equal to -a. then a + (-a) = 0

            //usign two pointer method to find two sum
            int Left = i+1, Right = nums.size()-1;
            int find = -a;
            while(Left < Right)
            {
                int b = nums[Left];
                int c = nums[Right];
                int sum = b + c;

                if(sum < find)Left++;
                else if(sum > find)Right--;
                else 
                {
                    while(Left + 1 < Right and nums[Left + 1] == b)Left++; ///remove duplicate
                    while(Right - 1 > Left and nums[Right - 1] == c)Right--;///remove duplicate

                    result.push_back({a, b, c});
                    Right--;
                    Left++;
                }
            }

          while(i + 1 < nums.size() and nums[i] == nums[i+1])i++;///remove duplicate

        }

        return result;
    }
};
