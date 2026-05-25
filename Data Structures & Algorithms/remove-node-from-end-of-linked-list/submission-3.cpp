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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);

        ListNode* left=dummy;
        ListNode* right=head;

        while(n--) right=right->next;

        while(right){
            left=left->next;
            right=right->next;
        }

        left->next=left->next->next;
        return dummy->next;
    }
};
//left->next becomes the nth node from end.
/*
left -------- right
        n apart
when right reaches the end
left` will be just BEFORE the node to delete.
dummy -> 1 -> 2 -> 3 -> 4 -> 5
n = 2

Initially:
left = dummy
right = 1
Step 1: Move right n steps
while(n--) right = right->next;

Move 2 times:
right = 3

Now:
left = dummy
right = 3

Distance between them is 2 nodes.
*/
