class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        long mini = nums[0];
        vector<int> pre(n, -1), suff(n, -1);
        for(int i = 1 ; i < n - 1; i++){
            pre[i] = mini;
            mini = min(mini, (long)nums[i]);
        }
        mini = nums.back();
        for(int i = n - 2 ; i > 0 ; i--){
            suff[i] = mini;
            mini = min(mini, (long)nums[i]);
        }
        mini = INT_MAX;
        for(int i = 1 ; i < n - 1 ; i++){
            if(nums[i] > pre[i] && nums[i] > suff[i]){
                mini = min(mini, (long)nums[i] + pre[i] + suff[i]);
            }
        }
        return mini != INT_MAX ? mini : -1;
    }
};