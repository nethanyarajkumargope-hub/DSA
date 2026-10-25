class Solution {
public:
int getMaxRearrangement(int num) {
    string s = to_string(num);
    sort(s.rbegin(), s.rend());
    return stoi(s);
}

long long maximizeSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<pair<int, int>> gains(n);
    long long totalSum = 0;
    
    for (int i = 0; i < n; i++) {
        int maxVal = getMaxRearrangement(nums[i]);
        int gain = maxVal - nums[i];
        gains[i] = {gain, nums[i]};
        totalSum += nums[i];
    }
    
    sort(gains.rbegin(), gains.rend());
    
    for (int i = 0; i < min(k, n); i++) {
        if (gains[i].first > 0) {
            totalSum += gains[i].first;
        } else {
            break; 
        }
    }
    
    return totalSum;
}

};