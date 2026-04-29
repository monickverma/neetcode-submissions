/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Node{
public:
Node* next;
int data;

Node(int val): data(val), next(nullptr) {}

};

Node* deepCopy(Node* head){
    if(!head) return nullptr;
    Node* copy = new Node(head->data);
    Node* curr= head->next;
    Node* currcopy=copy;

    while(curr){
        currcopy->next=New Node(curr->data);
        curr=curr->next;
        currcopy=currcopy->next;
    }
    return copy;
}
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

unordered_map<Node*, Node*> nodemap;

Node* curr= head;
while (curr)
{
   nodemap[curr]=new Node(curr->val);
   curr=curr->next;
}

curr=head;
while (curr)
{
    nodemap[curr]->next=nodemap[curr->next];
    nodemap[curr]->random=nodemap[curr->random];
    curr=curr->next;
}
return nodemap[head];
    }
};
