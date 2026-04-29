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

        long long number1 = 0, number2 = 0, decimal = 1;
        ListNode* curr = l1;

        while (curr) {
            number1 += (curr->val) * decimal;
            decimal *= 10;
            curr = curr->next;
        }

        decimal = 1;
        curr = l2;
        while (curr) {
            number2 += (curr->val) * decimal;
            decimal *= 10;
            curr = curr->next;
        }

        long long sum = number1 + number2;

        if (sum == 0) return new ListNode(0);

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (sum) {
            int digit = sum % 10;
            ListNode* newNode = new ListNode(digit);

            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            sum /= 10;
        }

        return head;
    }
};
