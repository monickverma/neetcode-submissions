class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size()>1){
            vector<ListNode*> mergedLists;
            for(int i=0;i<lists.size();i+=2){
                ListNode* l1=lists[i];
                ListNode* l2=(i+1)<lists.size()? lists[i+1]:nullptr;
                mergedLists.push_back(mergeLists(l1,l2));
            }
             lists=mergedLists;
        }
        return lists[0];
    }

private:
    ListNode* mergeLists(ListNode* list1,ListNode* list2){

        ListNode* dummy=new ListNode(0);
        ListNode* node=dummy;

        while(list1&& list2){
        if(list1->val<list2->val){
            node->next=list1;
            list1=list1->next;
        }
        else{
            node->next=list2;
            list2=list2->next;
        }
        node=node->next;
        }
        if(list1) node->next=list1;
        else if(list2)node->next=list2;
        return dummy->next;

    }
};

