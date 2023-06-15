class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        while(cnt <= 10000){
            if(n==1){
                return true;
            }
            int temp = n; int num = 0;
            while(temp>0){
                int temp2 = (temp%10) * (temp%10);
                num += temp2;
                temp = temp/10;
                cnt++;
            }                
            n = num;
        }
        return false;
    }
};