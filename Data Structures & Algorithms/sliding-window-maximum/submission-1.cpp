class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        
        int n = nums.size();
        vector<int> output(n-k+1); // the size is so because first window starts from 0 and ends at k, 2nd window starts at 1 and ends at k-1, contionuing at last starts at n-k and ends at n-1 so the total number is n-k since shifting by 1 once creates new window.
        deque<int> q; // MAINTAINS INDEXES 

        while (r < n)
        {

            while (!q.empty() && nums[q.back()] < nums[r])
                q.pop_back(); // this loop checks if there is element smaller than pervious elements and eliminates it, since smaller elements NEED NOT BE CHECKED FOR ANY REASON

            q.push_back(r);
            if (l>q.front()) // basically window shifting, since the outbounds isn't required
                q.pop_front();
            if ((r + 1) >= k)
            {
                output[l] = nums[q.front()]; // deque of the left most since it is the maximum
                l++;
            }
            r++;
        }
        return output;
    }
};
