//The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day. Find the maximum profit that you can get.

// Note: A stock can only be sold if it has been bought previously and multiple stocks cannot be held on any given day


class Solution {
    public int maximumProfit(int prices[]) {
        // code here
        if (prices.length == 0) return 0;
        
        int ans = 0;
        int n = prices.length;
        
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                ans += prices[i] - prices[i - 1];
            }
        }
        
        return ans;
    }
}
