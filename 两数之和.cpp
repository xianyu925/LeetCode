class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++) {
            if(hashmap.find(target - nums[i]) != hashmap.end()) 
                return {hashmap[target - map[i]], i};
            hashmap[nums[i]] = i;
        }
        return {};
    }
};