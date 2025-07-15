/*
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        bool isVowelExist = false;
        bool isConsonantExist = false;
        for(int i = 0; i < word.length(); i++) {
            if(word[i] == '@' || word[i] == '#' || word[i] == '$') return false;
            for(int j = 0; j < 10; j++) {
                if(word[i] == "aeiouAEIOU"[j]) isVowelExist = true;
            }
            for(int j = 0; j < 42; j++) {
                if(word[i] == "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"[j]) isConsonantExist = true;
            }
        }
        if(isVowelExist && isConsonantExist) return true;
        else return false;
    }
};

// 使用cstdlib中的函数，使可读性更强
class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        bool isVowelExist = false;
        bool isConsonantExist = false;
        for(auto c : word) {
            if(isalpha(c)) {
                c = tolower(c);
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') isVowelExist = true;
                else isConsonantExist = true;
            } else if(!isdigit(c)) return false;
        }
        if(isVowelExist && isConsonantExist) return true;
        return false;
    }
};