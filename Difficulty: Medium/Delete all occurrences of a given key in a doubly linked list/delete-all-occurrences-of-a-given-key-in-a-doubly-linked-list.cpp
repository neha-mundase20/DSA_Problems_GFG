//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* current = *head_ref;

        while (current != nullptr) {
            if (current->data == x) {
                // Node to be deleted
                Node* nodeToDelete = current;

                // Update head if the node to be deleted is the head
                if (current == *head_ref) {
                    *head_ref = current->next; // Move head
                    if (*head_ref != nullptr) {
                        (*head_ref)->prev = nullptr; // Update new head's prev
                    }
                } else {
                    // Not head, update previous node's next
                    if (current->prev != nullptr) {
                        current->prev->next = current->next;
                    }
                }

                // Update next node's prev if not deleting the last node
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }

                // Move to the next node
                current = current->next;

                // Delete the node
                delete nodeToDelete; 
            } else {
                // Move to the next node only if current is not deleted
                current = current->next;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        Node* head = new Node();
        head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            // push(&head,val);
            inp[i] = val;
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }
        int key;
        cin >> key;
        // printList(head);
        // cout << endl;

        Solution obj;

        obj.deleteAllOccurOfX(&head, key);
        printList(head);
        cout << endl;

        // cout << "\n~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends