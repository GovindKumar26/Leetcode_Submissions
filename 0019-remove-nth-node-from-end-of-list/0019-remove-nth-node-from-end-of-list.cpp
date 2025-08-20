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

void deleteAtPos(ListNode*& head, int pos) {
    ListNode *prev = NULL, *curr = head;
    if (pos == 1) {
        head = head->next;
        return;
    }

    ListNode* temp = head;
    while ((pos - 1)) {
        prev = curr;
        curr = curr->next;
        pos--;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //brute
        // ListNode* temp = head;
        // int len = 1;

        // while (temp->next) {
        //     len++;
        //     temp = temp->next;
        // }

        // int pos = len - n + 1;

        // deleteAtPos(head, pos);
        // return head;

        //optimized

         ListNode* slow = head, *fast = head;

        for(int i=0 ; i<n ; i++) {
            fast = fast->next;
        }

         // If fastp becomes NULL,
    // the Nth node from the end is the head
       if (fast == NULL)
        return head->next;

        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;

    }
};