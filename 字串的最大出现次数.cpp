// 贪心+滑动窗口（大小为minSize）
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        int ans = 0;
        bool isValid = true;
        unordered_map<string, int> hashMap;
        for(int i = 0; i < n - minSize + 1; i++) {
            unordered_set<char> exist;
            string cur;
            for(int j = i; j < i + minSize; j++) {
                isValid = true;
                exist.insert(s[j]);
                if(exist.size() > maxLetters) {
                    isValid = false;
                    break;
                }
                cur += s[j];
            }
            if(isValid) { 
                hashMap[cur]++;
                ans = max(ans, hashMap[cur]);
            }
        }
        return ans;
    }
};