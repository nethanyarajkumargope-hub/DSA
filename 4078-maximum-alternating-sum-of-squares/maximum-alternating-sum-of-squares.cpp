class Solution {
public:
    long long maxAlternatingSum(vector<int>& arr) {
        // negative numbers is also possible
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<0) arr[i]=-arr[i];
        }
        long long a=0;
        long long b=0;
        sort(arr.begin(),arr.end());
        for(int i =0;i<n;i++){
            if(i<n/2){
                a+=arr[i]*arr[i];
            }else{
                b+=arr[i]*arr[i];
            }
        }
        return abs(a-b);
    }
    };