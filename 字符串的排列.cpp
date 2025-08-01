// 定长滑动窗口
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26, 0);
        size_t k = s1.size();
        size_t n = s2.size();
        int diff = 0;

        for(char c : s1)
            if(cnt[c - 'a']++ == 0) ++diff;

        for(size_t i = 0; i < n; ++i) {
            if(cnt[s2[i] - 'a']-- == 0) ++diff;
            else if(cnt[s2[i] - 'a'] == 0) --diff;
            int left = i - k + 1;
            if(left < 0) continue;
            if(diff == 0) return true;
            if(cnt[s2[left] - 'a']++ == 0) ++diff;
            if(cnt[s2[left] - 'a'] == 0) --diff;
        }
        return false;
    }
};