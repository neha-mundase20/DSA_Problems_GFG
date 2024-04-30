/* Add two numbers represented by linked lists
Medium Accuracy: 34.52% Submissions: 245K+ Points: 4

Given two decimal numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Example 1:

Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
Output: 
3->9->0->null  
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Example 2:

Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)
Output: 
7->0->null
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(max(n,m)) for the resultant list.

Constraints:
1 <= n, m <= 104 */

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    struct Node* Reverse(struct Node*head){
        Node*prev=nullptr;
        Node*current=head;
        Node*next=nullptr;
        
        while(current!=nullptr){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        num1=Reverse(num1); //reversing linked lists to start adding from LSB
        num2=Reverse(num2);
        
        Node*result=nullptr;
        Node*temp=nullptr;
        int carry=0;
        
        while(num1!=nullptr || num2!=nullptr || carry){
            int sum=carry;  //previous carry should also be assigned to sum
            
            if(num1!=nullptr){
                sum=sum+(num1->data);
                num1=num1->next;
            }
            if(num2!=nullptr){
                sum=sum+(num2->data);
                num2=num2->next;
            }
            
            carry=sum/10;   //calculate the carry
            Node* node=new Node(sum % 10);  //calculate the bit to be added in the list when
                                            //carry is passed on to next digit

            if (result==nullptr) {
                result=node;
            }
            else {
                temp->next=node;
            }
            temp=node;
        }
        result=Reverse(result);
        // Remove leading zeros from the result list
        Node* current = result;
        while (current!=nullptr && current->data==0) {
            Node* next=current->next;
            delete current;  // free the current node
            current=next;
        }
        
         if (current==nullptr){  // Check if all nodes were zero and list is empty
        result=new Node(0);  // Add a single zero node
        }
        else{
        result=current;
        }


        return result;
        
        
        
        
        /*The integer 5 is just the number 5.
            The character '5' is represented by the number 57 in ASCII.
            To convert the integer 5 to the character '5', 
            you need to add the ASCII value of '0' to your integer:
            char c = 5 + '0';  // 5 + 48 = 53 in ASCII, which corresponds to the character '5'

            When you write 5 + '0', the compiler interprets '0' as its ASCII value, which is 48.
            Adding 5 to 48 results in 53, which is the ASCII value for the character '5'*/
        
        /* // Convert linked lists to strings by converting node data to character
        string s1, s2;
        Node* temp = num1;
        while (temp != nullptr) {
            s1.push_back(temp->data + '0');  // convert integer to character
            temp = temp->next;
        }
        
        temp = num2;
        while (temp != nullptr) {
            s2.push_back(temp->data + '0');  // convert integer to character
            temp = temp->next;
        }
        
        // Convert strings to integers
        long long n1 = stoll(s1);
        long long n2 = stoll(s2);
        long long n3 = n1 + n2;  // perform addition
        
        // Convert the sum back to a string
        string s3 = to_string(n3);
        
        // Create the resulting linked list from the sum string
        Node* head = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < s3.length(); ++i) {
            Node* newNode = new Node(s3[i] - '0');  // Convert character back to integer
            if (head == nullptr) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
        }
        return head;*/
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends