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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* curr = head;
        if(!curr || !curr->next) return head;
        ListNode* secondNode = curr->next;

        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }

        curr = head;

        while (curr->next && curr->next->next) {
            ListNode* x = curr->next;
            curr->next = curr->next->next;
            curr = x;
        }

        if (len % 2 == 0) {
            curr->next = secondNode;
        } else {
            ListNode* temp = curr->next;
            curr->next = NULL;
            temp->next = secondNode;
        }
        return head;
    }
};