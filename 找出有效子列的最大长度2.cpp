// 暴力枚举
/*
时间复杂度：O(k^2 * n)
空间复杂度：O(1)
缺点：
会超时
*/
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < i + 1; j++) {
                int length = 0;
                int prev = -1;
                for(int n : nums) {
                    n = n % k;
                    if(prev == -1) {
                        if(n == i) {
                            length++;
                            prev = i;
                        } else if(n == j) {
                            length++;
                            prev = j;
                        }
                    } else if(n == i && prev == j) {
                        length++;
                        prev = i;
                    } else if(n == j && prev == i) {
                        length++;
                        prev = j;
                    }
                }
                ans = max(length, ans);
            }
        }
        return ans;
    }
};

// 动态规划(Dynamic Programming)
/*
核心思想：
通过记忆化储存中间结果，避免重复计算。适用于重叠子问题和最优子结构的优化问题。
关键步骤：
1. 状态表示：定义一个数组或表格来储存每个子问题的解
2. 状态转移方程：找到子问题之间的递推关系
3. 初始化：设置初始条件
4. 填表顺序：按照一定的顺序填充表格
5. 返回值：根据题目要求返回最终结果

时间复杂度：O(k^2 + nk)
空间复杂度：O(k^2)
*/
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;
        for(int n : nums) {
            n %= k;
            for(int i = 0; i < k; i++) {
                dp[i][n] = dp[n][i] + 1;
                ans = max(ans, dp[i][n]);
            }
        }
        return ans;
    }
};

// 枚举余数，考察子序列的最后一项
/*
双百做法
时间复杂度：O(k*(k+n))
空间复杂度：O(k)
m : 相邻两项之和模k的结果
f[n] : 以n结尾的子序列的长度
*/
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> f(k);
        for(int m = 0; m < k; m++) {
            f.assign(k, 0);
            for(int n : nums) {
                n %= k;
                f[n] = f[(m - n + k) % k] + 1;
                ans = max(ans, f[n]);
            }
        }
        return ans;
    }
};