/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef ListNode* lPtr;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        lPtr slow, fast;
        slow = fast = head;
        while (slow != NULL && fast != NULL) {
            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
            else
                fast = NULL;
            if (slow == fast)
                break;
        }

        if (slow == NULL || fast == NULL)
            return NULL;
        slow = head;
        while (slow != NULL && fast != NULL && slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
