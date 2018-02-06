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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int len;
    ListNode *Head;
    Solution(ListNode* head) {
        Head = head;
        while (head != NULL) {
            head = head->next;
            len++;
        }
    }

    /** Returns a random node's value. */
    int getRandom() {
        int num = rand() % len;
        ListNode *temp = Head;
        while (num--) {
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
