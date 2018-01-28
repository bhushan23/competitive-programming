/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef ListNode* lNode;
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oHead = head;
        lNode eHead, oCur, eCur;

        eHead = oCur = eCur = NULL;

        if (!head)
            return head;

        oCur = oHead;
        if (oCur)
            eCur = oCur->next;

        lNode prev = NULL;
        eHead = eCur;
        while (oCur != NULL && eCur != NULL) {
            lNode oNext = eCur->next;
            lNode eNext = NULL;
            if (oNext)
                 eNext = oNext->next;
            oCur->next = oNext;
            eCur->next = eNext;
            prev = oCur;
            oCur = oNext;
            eCur = eNext;
        }
        if (oCur) {
            oCur->next = eHead;
        } else if (prev) {
            prev->next = eHead;
        }

        return head;
    }
};
