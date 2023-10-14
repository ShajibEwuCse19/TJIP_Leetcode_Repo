//TC: O(N)
//SC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0, major = nums[0];
        for(auto i: nums)
        {
            if(cnt == 0)
            {
                cnt++;
                major = i;
            }
            else if(i == major)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        return major;
    }
};
