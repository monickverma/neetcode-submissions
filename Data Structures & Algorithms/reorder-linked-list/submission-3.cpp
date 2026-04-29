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
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        ListNode* end=slow->next;
        slow->next=nullptr;
        ListNode* prev =nullptr;//what
        
        while (end) {
            ListNode* nextNode = end->next;  
            end->next = prev;               
            prev = end;                     
            end = nextNode;                 
        }

        ListNode* first=head;

        end=prev;

        while(end){
            ListNode* tmp1=first->next;
            ListNode* tmp2=end->next;

            first->next=end;
            end->next=tmp1;
            first=tmp1;
            end=tmp2;
        }

        
    }
};