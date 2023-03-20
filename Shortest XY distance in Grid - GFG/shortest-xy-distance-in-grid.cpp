//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
         queue<pair<int, int>> q;
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(grid[i][j] == 'X')
                    q.push({i, j});
            }
        }
        
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int dis = 0;
        bool flag = 1;
        while(!q.empty() && flag)
        {
            int size = q.size();
            dis++;
            while(size-- && flag)
            {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
               
                for(int i = 0; i < 4; i++)
                {
                    int newx = x + dirs[i];
                    int newy = y + dirs[i + 1];
                    
                    if(newx >= 0 && newy >= 0 && newx < N && newy < M)
                    {
                        if(grid[newx][newy] == 'Y')
                        {
                            flag = 0;
                            break;
                        }
                        
                        else if(grid[newx][newy] == 'O')
                        {
                            q.push({newx, newy});
                            grid[newx][newy] = 'X';
                        }
                        
                    }
                    
                    
                }
            }
            
        }
        return dis;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends