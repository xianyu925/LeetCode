/*
定长滑窗套路：
1. 入：下标为i的元素进入窗口。若i<k-1，则重复第一步
2. 更新：更新答案
3. 出：下标为i-k+1的元素离开窗口
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0; 
        double avg = 0;
        for(int i = 0; i < arr.size(); i++) {
            avg += (double)arr[i] / k;
            if(i < k - 1) continue;
            if(avg >= threshold) ans++;
            avg -= (double)arr[i - k + 1] / k;
        }
        return ans;
    }
};