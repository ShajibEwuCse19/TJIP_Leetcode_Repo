//TC: O(N)
//SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int MinPrice = prices[0];

        for(int i = 1; i < prices.size(); i++)
        {
            profit = max(profit , prices[i] - MinPrice);

            MinPrice = min(MinPrice , prices[i]);
        }

        return profit;
    }
};
