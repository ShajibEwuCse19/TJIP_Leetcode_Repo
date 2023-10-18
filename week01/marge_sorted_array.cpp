//TC: O(N + M)
//SC: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int L1 = m-1, L2 = n-1; //L1 for nums1 pointer, L2 for nums2 pointer
        int idx = n+m-1; // end pointer of nums1

        while(idx >= 0)
        {
            if(L1 >= 0 and L2 >= 0)
            {
                if(nums1[L1] >= nums2[L2])
                {
                    nums1[idx] = nums1[L1];
                    L1--;
                }
                else  if(nums1[L1] <= nums2[L2])
                {
                    nums1[idx] = nums2[L2];
                    L2--;
                }
            }
            else if(L1 >= 0)
            {
               nums1[idx] = nums1[L1];
                L1--;
            }
            else if(L2 >= 0)
            {
                nums1[idx] = nums2[L2];
                L2--;
            }
            idx--;
        }
    }
};
