//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
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

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        Node*oddHead=nullptr;
        Node*evenHead=nullptr;
        Node*oddTail=nullptr;
        Node*evenTail=nullptr;
        
        
        if(head==nullptr || head->next==nullptr){
            return { nullptr, nullptr }; // Return two null pointers for empty input
        }
        
        
        Node*temp=head;
        int count=1;
        
        while(temp!=nullptr){
            if(count%2!=0 && temp!=nullptr){ //odd element
                if(oddHead==nullptr && oddTail==nullptr){
                    oddHead=oddTail=temp;
                }
                else{
                    oddTail->next=temp;
                    oddTail=oddTail->next;
                }
            }
            else{   //even element
                if(evenHead==nullptr && evenTail==nullptr){
                    evenHead=evenTail=temp;
                }
                else{
                    evenTail->next=temp;
                    evenTail=evenTail->next;
                }
            }
            temp=temp->next;
            count++;
        }
        
        // Terminate the odd and even lists
        if (oddTail != nullptr) oddTail->next = nullptr;
        if (evenTail != nullptr) evenTail->next = nullptr;
        
        // Return the heads of both odd and even lists
        return { oddHead, evenHead };
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends