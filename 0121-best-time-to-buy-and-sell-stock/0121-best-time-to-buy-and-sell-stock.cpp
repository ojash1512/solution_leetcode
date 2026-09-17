class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int max1 = 0;
        for(int i = 0;i<prices.size();i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            else{
                max1 = max(max1, prices[i] - minPrice);
            }
        }
        return max1;
    }
};