class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        unordered_set<int> present(nums.begin(), nums.end());
        vector<int> ans;

        for (int x = mn + 1; x < mx; x++) {
            if (!present.count(x)) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};