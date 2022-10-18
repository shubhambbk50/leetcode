class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0; 
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
            //(s)+((s-e)/2);
        if(nums.size()==0){
            return {-1,-1};
        }
        while(s<e){
            if(nums[mid]==target)
                break;
            if(nums[mid]>target)
                e--;
            else
                s++;
            mid=s+(e-s)/2;
        }
        cout<<mid<<" ";
        vector<int>a;int m,n;
        int index1=mid;int index2=mid;
        if(nums[mid]!=target){
            m=-1;n=-1;
            a.push_back(m);
            a.push_back(n);
            return a;
        }
        else{
                   // cout<<index1<<index2;
            
            while(index1>=0 && nums[mid]==nums[index1])
                index1--;
            while(index2<nums.size()&&nums[mid]==nums[index2])
                index2++;

        }
        m=index1+1;n=index2-1;
        a.push_back(m);
        a.push_back(n);
        
        return a;
    
    }
};