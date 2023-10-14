//TC: O(N)
//SC: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int cntZ = 0; ///count zero
       int len = nums.size();
       for(int i=0; i<len; i++)
       {
           if(nums[i] == 0)
           {
               cntZ++;
               continue;
           }

           if(nums[i] != 0)
           {
               swap(nums[i-cntZ] , nums[i]);
           }
       }
    }
};
