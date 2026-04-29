class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
    int maxFreq = 0;

    for (char task : tasks) {
        freq[task]++;
        maxFreq = max(maxFreq, freq[task]);
    }

    int maxFreqCount = 0;
    for (auto& [task, count] : freq) {
        if (count == maxFreq) {
            maxFreqCount++;
        }
    }

    int partCount = maxFreq - 1;
    int partLength = n - (maxFreqCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = tasks.size() - (maxFreq * maxFreqCount);
    int idleSlots = max(0, emptySlots - availableTasks);

    return tasks.size() + idleSlots;
    }
};
