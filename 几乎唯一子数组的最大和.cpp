class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        if(m > k) return 0;

        long long ans = 0, sum = 0;
        unordered_map<int, int> diffNums;
 
        for(int i = 0; i < nums.size(); i++) {
            diffNums[nums[i]]++;
            sum += nums[i];
            if(i < k - 1) continue;
            if(diffNums.size() > m - 1) ans = max(ans, sum);
            if(--diffNums[nums[i - k + 1]] == 0) diffNums.erase(nums[i - k + 1]);
            sum -= nums[i - k + 1];
        } 

        return ans;
    }
};