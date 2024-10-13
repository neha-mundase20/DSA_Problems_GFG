//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        /*int m=mat.size(),n=mat[0].size();
        Node*head=nullptr;
        Node*rowHead=nullptr;
        Node*current=nullptr;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(head==nullptr){
                    head=new Node(mat[i][j]);
                    head->down=new Node(mat[i+1][j]);
                    head->right=new Node(mat[i][j+1]);
                    current=head->right;
                    rowHead=head;
                }
                else if(i<m-1 && j<n-1){
                    current->right=new Node(mat[i][j+1]);
                    current->down=new Node(mat[i+1][j]);
                    current=current->right;
                }
                else if(j==n-1 && i<m-1){
                    current->right=nullptr;
                    current->down=new Node(mat[i+1][j]);
                    current=rowHead->down;
                    rowHead=rowHead->down;
                }
                else if(i==m-1 && j<n-1){
                    current->right=new Node(mat[i][j+1]);
                    current->down=nullptr;
                    current=current->right;
                }
                else if(i==m-1 && j==n-1){
                    current->right=nullptr;
                    current->down=nullptr;
                }
            }
        }
        return head;*/
        
        int m=mat.size(),n=mat[0].size();
        vector<vector<Node*>>result(m,vector<Node*>(n,nullptr));
        Node*head=nullptr;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                Node*temp=new Node(mat[i][j]);
                result[i][j]=temp;
                
                if(i==0 && j==0){
                    head=temp;
                }
                
                if(j>0){    //Link the right pointer
                    result[i][j-1]->right=temp;
                }
                
                if(i>0){    //Link the down pointer
                    result[i-1][j]->down=temp;
                }
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends