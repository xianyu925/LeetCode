/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
简单题
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head) {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};

//将基础的 *2 +1 运算转换为位运算
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head) {
            ans = ans << 1 | head->val;
            head = head->next;
        }
        return ans;
    }
};

// 方法二：递归
/*
时间复杂度：O(n)
空间复杂度：O(1)
*/
class Solution {
public:
    int getDecimalValue(ListNode* head, int ans = 0) {
        return head ? getDecimalValue(head->next, ans << 1 | head->val) : ans;
    }
};