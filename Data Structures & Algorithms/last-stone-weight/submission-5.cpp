class Solution {
public:
/*


[2,3,6,2,4]
heap=[4,3,2,2]

6-4=2

3,2,2,2

3-2=1

2,2,1

2-2=0

1

*/
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int s:stones) heap.push(s);

        while(heap.size()>1){
           int first=heap.top();
           heap.pop();
           int second=heap.top();
           heap.pop();
          heap.push(first-second);
        }

        if(heap.size()==0) heap.push(0);
        
        return heap.top();
        
    }
};
