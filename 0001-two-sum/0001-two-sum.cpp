class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res ={};
        int i = 0;
        while(i < nums.size()){
            int j = i+1;
            while(j < nums.size()){
                if((nums[i] + nums[j]) == target){
                    res.push_back(i);
                    res.push_back(j);
                }
                j++;
            }
            i++;
        }
        return res;
    }
};