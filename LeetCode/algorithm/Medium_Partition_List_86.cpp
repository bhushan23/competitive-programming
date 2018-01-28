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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lT, *gT, *it, *next, *nHead, *gHead;
        nHead = lT = new ListNode(-1);
        gT = gHead = new ListNode(-1);
        it = head;
        while (it != NULL) {
            next = it->next;
            if (it->val < x) {
                lT->next = it;
                lT = lT->next;
            } else {
                gT->next = it;
                gT = gT->next;
            }
            it = next;
        }
        gT->next = NULL;
        lT->next = gHead->next;
        it = nHead;
        nHead = nHead->next;
        delete it;
        delete gHead;
        return nHead;
    }
};
