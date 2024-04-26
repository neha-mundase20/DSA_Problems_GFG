//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        char direction ='e';    //Initial direction is to the east as 
                                //you enter the matrix at cell (0,0) in left to right direction
        int i=0,j=0;
        vector<int>leavingPoint;
        
        while(i>=0 && i<n && j>=0 && j<m){
            if(matrix[i][j]==1){
                    
                matrix[i][j]=0;    
                switch(direction){
                    
                    case 'e':
                    direction='s';
                    i++;
                    break;
                        
                    case 'w':
                    direction='n';
                    i--;
                    break;
                        
                    case 'n':
                    direction='e';
                    j++;
                    break;
                        
                    case 's':
                    direction='w';
                    j--;
                    break;
                }
            }
            else{
                //Move in current direction itself
                switch(direction){
                    case 'e':
                    j++;
                    break;
                    
                    case 'w':
                    j--;
                    break;
                    
                    case 'n':
                    i--;
                    break;
                    
                    case 's':
                    i++;
                    break;
                }
            }
        }
        //Out of Range of matrix, so determine last position
        switch(direction){
            case 'e':
            leavingPoint.push_back(i);
            leavingPoint.push_back(j-1);
            break;
            
            case 'w':
            leavingPoint.push_back(i);
            leavingPoint.push_back(j+1);
            break;
            
            case 'n':
            leavingPoint.push_back(i+1);
            leavingPoint.push_back(j);
            break;
            
            case 's':
            leavingPoint.push_back(i-1);
            leavingPoint.push_back(j);
            break;
        }
        return leavingPoint;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends