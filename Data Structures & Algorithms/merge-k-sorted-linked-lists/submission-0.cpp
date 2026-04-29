class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while (!lists.empty()) {
            int smallest = 10001; 
            int index = -1;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && lists[i]->val < smallest) {
                    smallest = lists[i]->val;
                    index = i;
                }
            }

            if (index == -1) break;

            node->next = lists[index];
            node = node->next;

            lists[index] = lists[index]->next;

            if (!lists[index]) {
                lists[index] = lists.back();  
                lists.pop_back();  
            }
        }

        return dummy.next;
    }
};