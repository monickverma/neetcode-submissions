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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return; 

        ListNode* header = head;

        while (header && header->next) {
            ListNode* curr = header;

            while (curr->next && curr->next->next) {
                curr = curr->next;
            }

            ListNode* last = curr->next; 
            if (!last) break; 

            curr->next = nullptr;       
            last->next = header->next;  
            header->next = last;        

            header = last->next;
        }
    }
};