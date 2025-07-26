// 定长滑动窗口
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> element;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            element[nums[i]]++;
            if(i < k - 1) continue;
            if(element.size() == k) ans = max(ans, sum);
            if(--element[nums[i - k + 1]] == 0) element.erase(nums[i - k + 1]);
            sum -= nums[i - k + 1];
        }
        return ans;
    }
};