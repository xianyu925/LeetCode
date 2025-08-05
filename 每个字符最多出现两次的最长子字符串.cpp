// 不定长滑动窗口
/*
遍历左端点移动右端点
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int cnt[26] = {0};
        for(int l = 0, r = 0; r < s.size(); ++l) {
            while(++cnt[s[r] - 'a'] != 3 && ++r < s.size());
            ans = max(ans, r - l);
            if(r < s.size()) --cnt[s[r] - 'a'];
            --cnt[s[l] - 'a']; 
        }
        return ans;
    }
};