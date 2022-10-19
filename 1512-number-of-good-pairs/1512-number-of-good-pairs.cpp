class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        unordered_map<int,int>mp;
        for(int i:nums){
            count+=mp[i]++;
        }
        return count;
    }
};