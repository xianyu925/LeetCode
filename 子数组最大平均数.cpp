class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double avg = 0;
        for(int i = 0; i < nums.size(); i++) {
            avg += (double)nums[i] / k;
            if(i < k - 1) continue;
            ans = max(avg, ans);
            avg -= (double)nums[i - k + 1] / k;
        }
        return ans;
    }
};