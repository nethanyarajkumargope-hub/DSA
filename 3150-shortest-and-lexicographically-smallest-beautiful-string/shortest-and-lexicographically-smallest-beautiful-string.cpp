class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int count1=0;
        int low=0;
        int high=0;
        string ans="";
        for(high=0;high<n;high++){
            if(s[high]=='1') count1++;
            while(count1==k){
                string current=s.substr(low,high-low+1);
                if(ans==""||current.length()<ans.length()||current.length()==ans.length() && current < ans){
                    ans=current;
                }
                if(s[low]=='1') count1--;
                low++;
            }
        }
        return ans;

    }
};