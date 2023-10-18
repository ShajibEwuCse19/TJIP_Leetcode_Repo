//TC: O(N)
//SC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int NextMaxPrice = 1, MinPrice = 0, len = prices.size();

        while(NextMaxPrice<len)
        {
            if(prices[NextMaxPrice] >= prices[NextMaxPrice-1])
            {
                NextMaxPrice++;
                continue;
            }
            
            profit += max(0 , prices[NextMaxPrice-1] - prices[MinPrice]);

            MinPrice = NextMaxPrice;
            NextMaxPrice++;
        }

        if(NextMaxPrice == len) profit += max(0 , prices[NextMaxPrice-1] - prices[MinPrice]);

        return profit;
    }
};
