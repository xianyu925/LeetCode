// 定长滑动窗口
/*
时间复杂度：O(n)
空间复杂度：O(1)
本题由于窗口定长可以省略一个变量r，但我没有省略了
哈希集合也可以用s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'来代替，速度更快
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        int cnt = 0;
        for(int l = 0, r = -1; l < s.length() - k + 1; l++) {
            while(r - l < k - 1)
                if(set.count(s[++r])) cnt++;
            ans = max(ans, cnt);
            if(ans == k) return ans;
            if(set.count(s[l])) cnt--;
        }
        return ans;
    }
};