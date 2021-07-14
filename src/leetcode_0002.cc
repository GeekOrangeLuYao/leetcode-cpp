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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* head;
        head = new ListNode(0);
        ListNode* tmp = head;

        int re(0), t;
        while(true) {
            // cout << (l1 -> val) << " " << (l2 -> val) << endl;
            if(l1 == nullptr && l2 == nullptr) break;
            else if(l1 == nullptr) {
                t = (l2 -> val) + re;
                l2 = l2 -> next;
            }
            else if(l2 == nullptr) {
                t = (l1 -> val) + re;
                l1 = l1 -> next;
            }
            else {
                t = (l1 -> val) + (l2 -> val) + re;
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            tmp -> next = new ListNode(((t >= 10) ? t - 10 : t), nullptr);
            re = (t >= 10) ? 1 : 0;
            tmp = tmp -> next;
        }
        // show(head);
        
        if(re) tmp -> next = new ListNode(re);
        return head -> next;
    }
};