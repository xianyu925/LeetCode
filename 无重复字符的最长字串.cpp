//方法一：暴力法
/*
时间复杂度：O(n^2)
空间复杂度：O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        for(int i = 0; i < s.length(); i++) {
            for(int j = i + 1; ; j++) {
                string temp(s, i, j - i);
                if(j == s.length() || temp.find(s[j]) != string::npos) {
                    max = max > j - i ? max : j - i;
                    break;
                }
            }
        }

        return max;
    }
};

//方法二：滑动窗口法
/*
时间复杂度：O(n)
空间复杂度：O(m) m为字符串中所含字符种类的数量
滑动窗口法及逐渐移动左窗口（或右窗口）
再根据题目具体要求来调节右窗口（或左窗口）
这里：
第一层循环用于逐渐移动左窗口
第二层循环用于调节右窗口
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> lookup;
        int maxStr = 0;
        for(int right = 0, left = 0; left < s.length(); left++) {
            while(right < s.length() && lookup.find(s[right]) == lookup.end())
                lookup.insert(s[right++]);
            maxStr = max(maxStr, right - left);
            lookup.erase(s[left]);
        }
        return maxStr;
    }
};
