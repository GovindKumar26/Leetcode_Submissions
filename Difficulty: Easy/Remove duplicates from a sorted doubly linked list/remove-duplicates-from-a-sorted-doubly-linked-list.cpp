/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        if (head == NULL) return head;
        
        Node* curr = head;
        while (curr != NULL) {
            if (curr->next != NULL && curr->data == curr->next->data) {
                Node* nodeToDelete = curr->next;
                curr->next = curr->next->next;
                
                if (curr->next != NULL) {
                    curr->next->prev = curr;  
                }
                
                delete nodeToDelete;
            } 
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};