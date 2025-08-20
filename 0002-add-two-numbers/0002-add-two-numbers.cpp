/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  ListNode*reverse(ListNode*head){

//     if(head==NULL || head->next==NULL) return head;

//     ListNode*curr=head;
//     ListNode*prev=NULL;
//     ListNode*forward;

//     while(curr!=NULL){
//         forward  = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     } return prev;
//  }

void insertAtTail(ListNode*& head, ListNode*& tail, int data) {
    ListNode* temp = new ListNode(data);
    if (head == NULL) {
        tail = temp;
        head = tail;
        return;
    }

    tail->next = temp;
    tail = temp;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode*head1 = reverse(l1);
        // ListNode*head2 = reverse(l2);
        // ListNode* curr1 = l1;
        // ListNode* curr2 = l2;
        // ListNode *head = NULL, *tail = NULL;

        // int carry = 0, sum;

        // while (curr1 != NULL || curr2 != NULL || carry != 0) {
        //     int val1 = 0, val2 = 0;

        //     if (curr2 != NULL) {
        //         val2 = curr2->val;
        //     }
        //     if (curr1 != NULL) {
        //         val1 = curr1->val;
        //     }

        //     sum = val1 + val2 + carry;
        //     carry = sum / 10;
        //     sum = sum % 10;

        //     insertAtTail(head, tail, sum);

        //     if (curr1 != NULL)
        //         curr1 = curr1->next;

        //     if (curr2 != NULL)
        //         curr2 = curr2->next;
        // }
        // return head;


        ListNode* dummy = new ListNode(-1);

        ListNode*temp1 = l1, *temp2 = l2;
        ListNode* curr = dummy;
        int carry = 0, sum = 0;
        while(temp1 || temp2 || carry) {
            int val1 = 0, val2 = 0;
            if(temp1){ val1 = temp1->val; temp1=temp1->next;}
            if(temp2){ val2 = temp2->val; temp2=temp2->next;}
            sum = val1 + val2 + carry;
            carry = sum/10;
            sum = sum%10;

            curr->next = new ListNode(sum);
            curr = curr->next;
        }

        return dummy->next;
    }
};