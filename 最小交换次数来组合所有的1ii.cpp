// 定长滑动窗口法
/*
时间复杂度：O(n)
空间复杂度：O(1)
窗口大小为1的个数
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), k = 0;
        int ans = n;
        int cnt = 0;
        for(int i = 0; i < n; i++) 
            if(nums[i]) k++;
        if(!k) return 0;
        for(int i = n - k; i < n * 2 - 1; i++) {
            if(!nums[i % n]) cnt++;
            if(i < n - 1) continue;
            ans = min(ans, cnt);
            if(!nums[(i - k + 1) % n]) cnt--;
        }
        return ans;
    }
};