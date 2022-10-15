class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str= s;  // we have done this because we can't declare 
                        // string str[s.size()] 
                        // but we can do so by alloting dynamic memory
                        // in that case we have to use "\0"
        for(int i=0; i<indices.size(); i++){
            str[indices[i]]=s[i];
        }
        return str;
    }
};