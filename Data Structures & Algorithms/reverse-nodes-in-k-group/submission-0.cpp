

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;  // If there's no list or k is 1, no reversal is needed
        
        // Create a dummy node to simplify the edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        
        ListNode* current = head;
        
        // Step 1: Calculate the length of the list
        int len = 0;
        while (current) {
            len++;
            current = current->next;
        }

        current = head;

        // Step 2: Reverse in groups of k
        while (len >= k) {
            ListNode* groupStart = current;
            ListNode* prev = nullptr;

            // Reverse k nodes
            for (int i = 0; i < k; ++i) {
                ListNode* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            // Connect the reversed part back into the list
            prevGroupEnd->next = prev;
            groupStart->next = current;
            
            // Move prevGroupEnd to the end of the reversed group
            prevGroupEnd = groupStart;

            len -= k;  // Reduce the length by k after processing the group
        }
        
        return dummy->next;
    }
};

