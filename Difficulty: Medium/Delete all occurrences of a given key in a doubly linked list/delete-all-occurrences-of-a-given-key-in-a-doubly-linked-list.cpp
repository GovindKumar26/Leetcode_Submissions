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
        // Write your code here
         Node* prev1 = NULL;
        Node* curr = *head_ref;
        Node* forward;

        while(curr) {
            prev1 = curr->prev;
            forward = curr->next;

            if(curr->data==x) {
              if(prev1)  prev1->next = forward;
              else *head_ref = forward;
               if(forward) forward->prev = prev1;
                Node* toDelete = curr;
                 curr=curr->next;
                delete toDelete;
            } 
            else {
                 curr=curr->next;
            }
           
        }

       
    }
};