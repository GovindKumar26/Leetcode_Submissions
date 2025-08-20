/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
         Node* zeroD = new Node(0); // dummy node for 0s
        Node* oneD = new Node(0);  // dummy node for 1s
        Node* twoD = new Node(0);  // dummy node for 2s

        Node* zero = zeroD, *one = oneD, *two = twoD;
        Node* curr = head;

        while (curr != NULL) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect 0s → 1s → 2s
        zero->next = (oneD->next) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = NULL;

        Node* newHead = zeroD->next;

        // Free dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return newHead;
        
    }
};