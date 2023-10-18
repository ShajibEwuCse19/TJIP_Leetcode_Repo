//TC: O(N)
//SC: O(1)
mt19937 rng(0); ///for better shuffle 
class Solution {

private:

    int createPartition(vector<int>&nums, int L, int R)
    {
        ///we will take all smaller elements than pvt to the left
        int pvt = nums[R]; ///current pvt
        int i = L - 1; ///start of i
        for(int j = L; j < R; j++) ///j start from L(i+1)
        {
            if(nums[j] <= pvt) swap(nums[++i], nums[j]); ///swap with nums[i+1] if we get any smaller element.
        }


        swap(nums[i+1], nums[R]); ///swap pvt with i+1 index. (Now, all greater elements will go to the right side)

        return i+1; ///return pvt index
    }

    void partial_sort(vector<int>&nums, int k)
    {
        //Using shuffle for avoid TLE for some sorted array
        //random_shuffle(nums.begin(), nums.end()); ///We can use this for shuffle
        shuffle(nums.begin(), nums.end(), rng); ///better shuffle

        int L = 0, R = nums.size() - 1; ///Left and Right pointer
        int MaxIteration = 2*log2(nums.size()); ///Threshold (for divide and conq. method, it'll devide the array max log2 times)
        while(L < R and MaxIteration--)
        {
            int pvtIdx = createPartition(nums, L, R); ///finding the pivot index

            if(pvtIdx < k) L = pvtIdx + 1; ///Pvt in the Right side
            else if(pvtIdx > k) R = pvtIdx - 1; ///Pvt in the Left side
            else break; ///got the Pvt index
        }
    }
    int findKthSmallest(vector<int>&nums, int k)
    {
        partial_sort(nums, k); ///sorting the array untill getting the result (Now, nums[k] in the right position)
        return nums[k];
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans = findKthSmallest(nums, nums.size() - k); ///similar but opposite of kth Largest
        return ans;
    }
};
