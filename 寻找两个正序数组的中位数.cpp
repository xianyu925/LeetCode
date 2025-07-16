// 方法一
/*
时间复杂度：O(m+n)
空间复杂度：O(m+n)
使用merge算法将两个数组合并，之后求中位数
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> help;
        int count1 = 0, count2 = 0;
        while(count1 < nums1.size() && count2 < nums2.size())
            help.push_back(nums1[count1] < nums2[count2] ? nums1[count1++] : nums2[count2++]);
        while(count1 < nums1.size()) help.push_back(nums1[count1++]);
        while(count2 < nums2.size()) help.push_back(nums2[count2++]);
        int size = help.size();
        if(size % 2) return help[size / 2];
        else return (double)(help[size / 2 - 1] + help[size / 2]) / 2;
    }
};

// 方法二：二分查找
/*
时间复杂度：O(log(m + n))
空间复杂度：O(1)
主要思路：
要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
这样 pivot 本身最大也只能是第 k-1 小的元素
如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
*/
class Solution {
public:
    int findKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int offset1 = 0, offset2 = 0;
        int m = nums1.size(), n = nums2.size();
        while(1) {
            if(offset1 == m) return nums2[k + offset2 - 1];
            if(offset2 == n) return nums1[k + offset1 - 1];
            if(k == 1) return min(nums1[offset1], nums2[offset2]);
            int newoffset1 = min(offset1 + k / 2 - 1, m - 1);
            int newoffset2 = min(offset2 + k / 2 - 1, n - 1);
            if(nums1[newoffset1] < nums2[newoffset2]) {
                k -= newoffset1 - offset1 + 1;
                offset1 = newoffset1 + 1;
            } else {
                k -= newoffset2 - offset2 + 1;
                offset2 = newoffset2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int k = size / 2 + 1;
        if(size % 2) return (double)findKthElement(nums1, nums2, k);
        else return (findKthElement(nums1, nums2, k) + findKthElement(nums1, nums2, k - 1)) / 2.0;
    }
};

// 方法三：划分
/*
时间复杂度：O(log(min(m,n)))
空间复杂度：O(1)
主要思路：
将两个数组划分成两部分，左边部分和右边部分，合并两个左边部分和右边部分，使得左边部分的最大值小于等于右边部分的最小值。
即：
对数组A进行二分查找，找到使得A[i - 1] <= B[j]且B[j - 1] <= A[i]的最大i，其中j = (m + n + 1) / 2 - i;
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums1, nums2);
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int median1 = 0; median2 = 0;

        while(left <= right) {
            i = (right - left) / 2 + right;
            j = (n - m + 1) / 2 + m - i;
            
            int num_i = (i == m ? INT_MAX : nums1[i]);
            int num_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int num_j = (j == n ? INT_MAX : nums2[j]);
            int num_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);

            if(num_im1 <= num_j) {
                median1 = max(num_im1, num_jm1);
                median2 = min(num_i, num_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }

        return ((m + n) % 2) ? median1 : (median1 + median2) / 2.0;
    }
};