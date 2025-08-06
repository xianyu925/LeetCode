// 不定长滑动窗口
/*
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int zero_cnt = 0;
        for(int l = 0, r = 0; r < n; ++r) {
            zero_cnt += 1 - nums[r];
            while(zero_cnt > 1) zero_cnt -= 1 - nums[l++];
            ans = max(ans, r - l);
        }
        return ans;
    }
};