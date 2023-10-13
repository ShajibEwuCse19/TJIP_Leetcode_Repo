//TC:O(N)
//SC:O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(auto i: nums)
        {
            ans = ans^i; ///doing XOR: a^a = 0, a^b^a = b
        }

        return ans;
    }
};