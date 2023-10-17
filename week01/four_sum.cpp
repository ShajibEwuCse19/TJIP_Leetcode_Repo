//TC: O(N^3)
//SC: O(N)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); /// sort for apply two sum
        vector<vector<int>>result; 
        int len = nums.size();

        for(int i = 0; i < len - 3; i++)
        {
            int a = nums[i]; ///a

            for(int j = i+1; j < len - 2; j++)
            {
                int b = nums[j];///b

                int L = j + 1, R = len - 1; /// left and right pointer
                ///applying two sum method
                while(L < R)
                {
                    int c = nums[L]; ///c
                    int d = nums[R];///d
                    long long sum = (long long)a + (long long)b + (long long)c + (long long)d;

                    ///searching a + b + c + d = target
                    if(sum < (long long)target)L++;
                    else if(sum > (long long)target)R--;
                    else
                    {
                        while(L + 1 < R and nums[L + 1] == c)L++;///avoid duplicate
                        while(R - 1 > L and nums[R - 1] == d)R--;///avoid duplicate

                        result.push_back({a, b, c, d});
                        L++;
                        R--;
                    }
                }

                while(j + 1 < len and nums[j] == nums[j+1]) j++;///avoid duplicate
            }
            while(i + 1 < len and nums[i] == nums[i+1]) i++;///avoid duplicate
        }

        return result;
    }
};
