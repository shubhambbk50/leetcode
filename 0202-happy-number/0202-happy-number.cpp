class Solution {
public:
    bool isHappy(int n) {
        map<int,int>mp;
        while(n!=1){
            if(n==1) return 1;
            if(mp.find(n) != mp.end()){
                return false;
            }
            mp[n]++;
            int temp = n;
            int num = 0;
            while(temp > 0){
                int temp2 = (temp%10) * (temp%10);
                num += temp2;
                temp = temp/10;
            }
            n = num;
        }
        return true;
    }
};