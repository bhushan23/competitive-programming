/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmp = head;
        if (!tmp)
            return head;
        ListNode *nextNode = tmp->next;
        while (tmp) {
            while (nextNode && nextNode->val == tmp->val) {
                tmp->next = nextNode->next;
                nextNode = tmp->next;
            }
            tmp = tmp->next;
        }
        return head;
    }
};
