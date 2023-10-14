//TC: 0(N)
//SC: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int sum) {
        
        unordered_map<int,int>freq;

        for(int i=0; i<nums.size(); i++)
        {
            int find = sum - nums[i];

            if(freq.count(find))
            {
                return {i, freq[find]};
            }
            freq[nums[i]] = i;
        }

        return {};
    }
};
