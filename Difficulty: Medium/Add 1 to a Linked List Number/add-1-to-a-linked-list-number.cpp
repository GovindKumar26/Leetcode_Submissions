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
    Node* reverseLL(Node*head) {
        if(head==NULL || head->next==NULL) return head;
        
        Node *prev = NULL;
        Node *curr = head;
        Node *forward;
        
        while(curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
           
        }
        
        return prev;
        
    }
    
  public:
    Node* addOne(Node* head) {
        
           Node* revHead = reverseLL(head);

        Node* temp = revHead;
        int carry = 1;  // initialize with 1 because we want to add one

        while (temp) {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;

            // if carry is 0, we can break early
            if (carry == 0) break;

            // if this is the last node and carry exists
            if (temp->next == NULL && carry != 0) {
                temp->next = new Node(carry);
                carry = 0;
                break;
            }

            temp = temp->next;
        }

        return reverseLL(revHead);
        
        
    }
};