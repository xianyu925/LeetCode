// 超时做法
/*
时间复杂度：O(n^2 * logn)
空间复杂度：O(n)
*/
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        vector<int> subArray;
        for(int i = 0; i < nums.size(); i++) {
            subArray.push_back(nums[i]);
            if(i < k - 1) continue;
            int beautyNum = findXthSmallNum(subArray, x);
            if(beautyNum < 0) ans.push_back(beautyNum);
            else ans.push_back(0);
            subArray.erase(subArray.begin());
        }
        return ans;
    }

    int findXthSmallNum(vector<int> array, int x) {
        sort(array.begin(), array.end());
        return array[x - 1];
    }
};

// 建立数组模拟滑动窗口 利用桶排序找到第x个最小的数
/*
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        const int BIAS = 50;
        int n = nums.size();
        vector<int> ans(n - k + 1, 0);
        int cnt[2 * BIAS + 1] = {0}; // 统计每个数的出现次数
        for(int i = 0; i < n; i++) {
            cnt[nums[i] + BIAS]++;
            if(i < k - 1) continue;
            int beautyNum;
            int left = x;
            for(int j = 0; j < BIAS; j++) {
                left -= cnt[j];
                if(left < 1) {
                    ans[i - k + 1] = j - BIAS;
                    break;
                }
            }
            cnt[nums[i - k + 1] + BIAS]--;
        }
        return ans;
    }
};