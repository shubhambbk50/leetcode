class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>v;
        int maxi=*max_element(candies.begin(),candies.begin()+candies.size());
        for(auto i:candies){
            v.push_back(i+extraCandies >= maxi);
        }
        return v;
    }
};