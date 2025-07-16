// 方法一
/*
时间复杂度：O(n)
空间复杂度：O(1)
思路：三种情况：全奇、全偶、奇偶相间。分别求出其长度，取最大值。
*/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans;

        int length1 = nums.size();
        for(auto n : nums)
            if(n & 1) length1--;
        int length2 = nums.size() - length1;

        ans = max(length1, length2);

        bool nextOdd;
        int length3 = nums.size();
        if(nums[0] & 1) nextOdd = false;
        else nextOdd = true;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] & 1 && nextOdd == true) nextOdd = false;
            else if(!(nums[i] & 1) && nextOdd == false) nextOdd = true;
            else length3--;

        ans = max(ans, length3);
        return ans;
    }
};

/*
优化
在计算奇偶相间的情况时，可将一组奇数（偶数）视为一个奇数（偶数），只计算数组中奇偶反转的次数
*/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddCount = 0;
        int reverseCount = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & 1) oddCount++;
            if(i > 0 && (nums[i] & 1 ^ nums[i - 1] & 1)) reverseCount++;
        }
        
        return max(max(oddCount, (int)nums.size() - oddCount), reverseCount);
    }
};

/*
另一种思路：
使用二维数组记录全奇、全偶、奇偶相间的情况
速度较慢，但比较优雅
*/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> patterns = {{0, 0}, {1, 1}, {1, 0}, {0, 1}};

        for(auto& pattern : patterns) {
            int cnt = 0;
            for(int n : nums) {
                if(n % 2 == pattern[cnt % 2]) cnt++;
                ans = max(ans, cnt);
            }
        }
        
        return ans;

    }
};