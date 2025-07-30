// 滑动窗口法
/*
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int minFlips(string s) {
        int len = //s.length();
        int ans = INT_MAX;
        int cnt = 0;
        for(int i = 0; i < 2 * len - 1; i++) {
            if(s[i % len] % 2 != i % 2) cnt++;
            int left = i - len + 1;
            if(left < 0) continue;
            ans = min({ans, cnt, len - cnt});
            if(s[left] % 2 != left % 2) cnt--;
        }
        return ans;
    }
};

// 位运算改进
class Solution {
public:
    int minFlips(string s) {
        int len = s.length();
        int ans = INT_MAX;
        int cnt = 0;
        for(int i = 0; i < 2 * len - 1; i++) {
            cnt += (s[i % len] ^ i % 2) & 1;
            int left = i - len + 1;
            if(left < 0) continue;
            ans = min({ans, cnt, len - cnt});
            cnt -= (s[left] ^ left % 2) & 1;
        }
        return ans;
    }
};