// 定长滑动窗口
/*
主要转换：
将原题求会议时间平移后得到的最大空余时间
转换为求相邻k+1个空闲时间的最大值
*/
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int ans = 0;
        int freeTime = 0;
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(), 0);
        for(int i = 0; i < startTime.size(); i++) {
            freeTime += startTime[i] - endTime[i];
            if(i < k) continue;
            ans = max(ans, freeTime);
            freeTime -= startTime[i - k] - endTime[i - k];
        }
        return ans;
    }
};