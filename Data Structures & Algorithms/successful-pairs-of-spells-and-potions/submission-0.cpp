class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());

        vector<int> result;
        for (int i = 0; i < spells.size(); i++) {
        int l = 0;
        int r = potions.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if ((long long)spells[i] * potions[mid] >= success) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        if ((long long)spells[i] * potions[l] >= success) {
            result.push_back(potions.size() - l);
        }
        else {
            result.push_back(0);
        }
    }

    return result;


    }
};
