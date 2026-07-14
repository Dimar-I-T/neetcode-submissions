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
    ListNode* reverseList(ListNode* head) {
        vector<ListNode*> node;
        ListNode* temp = head;
        while (head != NULL){
            node.push_back(head);
            head = head->next;
        }

        int n = node.size();
        if (n < 2){
            return temp;
        }

        ListNode* headBaru = node[n - 1];
        for (int x = n - 1; x >= 1; x--){
            node[x]->next = node[x - 1];
        }

        node[0]->next = NULL;
        return headBaru;
    }
};