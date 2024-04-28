//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        int count=0;
        Node*temp=head;
        
        while(temp->next!=nullptr){
            temp=temp->next;
            count++;
        }
        count++;
        
        if(count==1){   //only 1 element in linked list
            return nullptr;
        }
        else if(count==2){  //only 2 elements in linked list
            head->next=nullptr;
            return head;
        }
        else{   //nore than 2 elements in linked list
        
           int mid=0;
            if(count%2==0){ //count is even
                mid=(count/2)+1;
            }
            else{   //count is odd
                mid=(count/2)+1;
            }
            temp=head;
            while(mid>2){   //reach to an element before the middle index
                temp=temp->next;
                mid--;
            }
            
           //deleting the value at specified index and referencing the next value
            temp->next=temp->next->next;
        }
        return head;
    }
};

//{ Driver Code Starts.



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends