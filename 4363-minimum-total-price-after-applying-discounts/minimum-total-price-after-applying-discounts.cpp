class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        priority_queue<int> pq;
        int n = prices.size();
        for(int i=0;i<n;i++) pq.push(prices[i]);
        double sum=0;
        sort(discounts.begin(),discounts.end(),greater<int>());
        int limit = min(discounts.size(), prices.size());
        for(int i=0;i<limit;i++){
            int d = discounts[i];
            int p =pq.top();
            pq.pop();
            sum+=(p* (100.0 - d)) / 100;
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};