//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if(head==nullptr || head->next==head){
            return head;
        }
        Node* prev=nullptr;
        Node* curr=head;
        Node* next=nullptr;

        // Reverse the circular linked list
        do {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        } while(curr!=head);

        // Re-link the last node to the new head
        head->next=prev;
        head=prev;

        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (head == nullptr) return nullptr;

        Node* curr = head;
        Node* prev = nullptr;

        // If the node to be deleted is the head node
        if (head->data == key) {
            // If there's only one node in the list
            if (head->next == head) {
                delete head;
                return nullptr;
            }
            
            // Find the last node to update its next pointer
            while (curr->next != head) {
                curr = curr->next;
            }
            // Make the last node point to the new head (next of the old head)
            curr->next = head->next;
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        // Traverse the list to find the node to delete
        prev = head;
        curr = head->next;

        while (curr != head) {
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return head;
            }
            prev = curr;
            curr = curr->next;
        }

        return head; // Return the updated head after deletion
    }
};

//{ Driver Code Starts.

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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends