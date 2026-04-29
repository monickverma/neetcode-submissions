class MyCircularQueue {
    struct Node{
        int val;
        Node* next;

        Node(int v):val(v),next(nullptr){}
    };

    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity=k;
        size=0;
        front=nullptr;
        rear=nullptr;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        Node* node=new Node(value);
        if(size==0){
            front=node;
            rear=node;
        }
        else{
            rear->next=node;
            node->next=front;
            rear=node;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        if(size==1){
            front = nullptr;
            rear = nullptr;
        }
        else{
            front=front->next;
            rear->next=front;
            
        }
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:front->val;
    }
    
    int Rear() {
        return isEmpty()? -1:rear->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */