// 不定长滑动窗口
/*
遍历窗口右端点移动左端点比遍历左端点然后移动右端点简单
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int cost = 0;
        for(int l = 0, r = 0; r < s.size(); ++r) {
            cost += abs(s[r] - t[r]);
            while(cost > maxCost) cost -= abs(s[l] - t[l++]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};