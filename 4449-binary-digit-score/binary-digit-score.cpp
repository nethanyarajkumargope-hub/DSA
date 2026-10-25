class Solution {
public:
    int calculateScore(int a, int b) {
       int s=0;
       int q = 0;
        while(a!=0){
           a = a & (a - 1);
            s+=1;
        }
        while(b!=0){
             b = b & (b - 1);
            q+=1;
        }
        if(s>=q) return s*q;
        else return q/s;
    }
};