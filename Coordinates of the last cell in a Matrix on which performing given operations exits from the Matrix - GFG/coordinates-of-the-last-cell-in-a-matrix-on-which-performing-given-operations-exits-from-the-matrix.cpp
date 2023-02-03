//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){

        int i=0,j=0;

        char d='r';

        while(i<matrix.size() && j<matrix[i].size()){

            if(matrix[i][j]==0){

                if(d=='r'){

                    if(j+1==matrix[i].size())

                     return {i,j};

                    else

                     j++;

                }

                else if(d=='d'){

                    if(i+1==matrix.size())

                     return {i,j};

                    else

                     i++;

                }

                else if(d=='l'){

                    if(j-1<0)

                     return {i,j};

                    else

                     j--;

                }

                else{

                    if(i-1<0)

                     return {i,j};

                    else

                     i--;

                }

                

            }

            else{

                if(d=='r'){

                    d='d';

                    matrix[i][j]=0;

                }

                else if(d=='d'){

                    d='l';

                    matrix[i][j]=0;

                }

                else if(d=='l'){

                    d='u';

                    matrix[i][j]=0;

                }

                else{

                    d='r';

                    matrix[i][j]=0;

                }

            }

        }

        

    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends