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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count = 0;
        ListNode *tmp = root;
        while (tmp != NULL) {
            count++;
            tmp = tmp->next;
        }


        vector<ListNode*> out;

        ListNode *head = new ListNode(-1);
        tmp = head;
        ListNode *it = root;
        int s;
        bool first = true;
        int l = k;
        for (int i = 0; i < l; ++i) {
            head = new ListNode(-1);
            tmp = head;
            s = ceil((float) count / (float)k);
            while(s > 0 && it) {
                ListNode *nNode = new ListNode(it->val);
                tmp->next = nNode;
                tmp = tmp->next;
                it = it->next;
                count--;
                s--;
            }
            k--;
            out.push_back(head->next);
        }
        return out;
    }
};
