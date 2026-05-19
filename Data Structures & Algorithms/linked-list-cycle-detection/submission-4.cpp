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

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* last=slow->next;
        slow->next=nullptr;

        ListNode* head2=nullptr;

        while(last){
            ListNode* nextNode=last->next;
            last->next=head2;
            head2=last;
            last=nextNode;
        }

        ListNode* first=head;
        last=head2;
       
        while(last){
            ListNode* tmp1=first->next;
            ListNode* tmp2=last->next;

            first->next=last;
            last->next=tmp1;
            first=tmp1;
            last=tmp2;
        }
    }
};
