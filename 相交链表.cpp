/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法一
/*
时间复杂度：O(m+n)
空间复杂度：O(1)
主要思路：
两链表均遍历到尾节点后检查是否相等
若相等，则长链表先遍历两链表长度的差值，之后两链表同时遍历至相等
即相交节点
缺点：
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0, cntB = 0;
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1->next) {
            cntA++;
            cur1 = cur1->next;
        }
        while(cur2->next) {
            cntB++;
            cur2 = cur2->next;
        }
        if(cur1 != cur2) return NULL;

        cur1 = cntA > cntB ? headA : headB;
        cur2 = cur1 == headA ? headB : headA;
        for(int i = 0; i < abs(cntA - cntB); i++) cur1 = cur1->next;
        while(cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }             
};

// 无环情况下的特殊做法
/*
时间与空间复杂度同上
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, q = headB;
        while(p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};

// 哈希集合
/*
时间复杂度：O(m+n)
空间复杂度：O(m)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        ListNode *p = headA;
            set.insert(p);
            p = p->next;
        }
        p = headB;
        while(p) {
            if(set.count(p)) return p;
            p = p->next;
        }
        return NULL;
    }
};