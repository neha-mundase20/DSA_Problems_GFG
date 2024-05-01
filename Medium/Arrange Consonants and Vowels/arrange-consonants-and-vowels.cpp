//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    
    bool isVowel(char data){
        if(data=='a' || data=='e' || data=='i' || data=='o' || data=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    struct Node* arrangeCV(Node* head) {
        /*vector<char>c;
        
        Node*temp=head;
        while(temp!=nullptr){   //storing all elements of linked list in vector
            c.push_back(temp->data);
            temp=temp->next;
        }
        
        multiset<char>st1,st2;   //as multisets store multiple elements in sorted format
        
        for(int i=0;i<c.size();i++){    //storing vowels in set st1
            if(c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u'){
                st1.insert(c[i]);
            }
        }
        
        for(int i=0;i<c.size();i++){    //storing consonants in set st2
            if(c[i]!='a' && c[i]!='e' && c[i]!='i' && c[i]!='o' && c[i]!='u'){
                st2.insert(c[i]);
            }
        }
        
        Node*head1=nullptr; //creating a new linked list combining multisets s1 & s2
        Node*tail1=nullptr;
        
        for(auto it:st1){
            Node*temp1=new Node(it);
            if(head1==nullptr){
                head1=temp1;
                tail1=head1;
            }
            else{
                tail1->next=temp1;
                tail1=temp1;
            }
        }
        
        for(auto it:st2){
            Node*temp1=new Node(it);
            tail1->next=temp1;
            tail1=temp1;
        }
        
        return head1;*/
        
        //Creating two linked lists, one for vowel and second for consonants
        Node*temp=head,*head1=nullptr,*tail1=nullptr,*head2=nullptr,*tail2=nullptr;
        bool flag;
        
        while(temp!=nullptr){
            flag=isVowel(temp->data);
            Node*temp1=new Node(temp->data);
            
            if(flag==true){ //character is a vowel
                if(head1==nullptr){
                    head1=temp1;
                    tail1=temp1;
                }
                else{
                    tail1->next=temp1;
                    tail1=temp1;
                }
            }
            else{   //character is a consonant
                if(head2==nullptr){
                    head2=temp1;
                    tail2=temp1;
                }
                else{
                    tail2->next=temp1;
                    tail2=temp1;
                }
            }
            temp=temp->next;
        }
        Node*val=nullptr;
        
        if(head1==nullptr){
            val=head2;
        }
        else if(head2==nullptr){
            val=head1;
        }
        else{
            tail1->next=head2;
            val=head1;
        }
        return val;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends