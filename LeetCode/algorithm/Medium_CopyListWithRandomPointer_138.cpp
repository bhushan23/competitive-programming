/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void Print(RandomListNode *head) {
        RandomListNode *it = head;
        while (!it) {
            cout << it->label << " ";
            it = it->next;
        }
        cout << endl;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *nHead = new RandomListNode(-1);
        RandomListNode *it = head;
        RandomListNode *cur, *nCur, *curNext, *nCurNext, *next;

        if (!head)
            return NULL;

        // Copy the list
        while (it != NULL) {
            RandomListNode *nTmp = new RandomListNode(it->label);
            nTmp->next = it->next;
            next = it->next;
            it->next = nTmp;
            it = next;
        }

        Print(head);
        // Copy Random Pointers
        it = head;
        while (it != NULL) {
            it->next->random = (it->random ? it->random->next : NULL);
            it = it->next->next;
        }

        // Separate alternate nodes
        nHead->next = head->next;
        it = head;
        while (it != NULL) {
            cur = it;
            nCur = it->next;
            curNext = nCur->next;
            nCurNext = NULL;
            if (curNext)
                nCurNext = curNext->next;
            cur->next = curNext;
            nCur->next = nCurNext;
            it = curNext;
        }

        it = nHead;
        nHead = nHead->next;
        delete it;
        return nHead;
    }
};
