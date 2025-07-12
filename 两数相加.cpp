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

 // my solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* answer = new ListNode;
        ListNode* current = answer;
        current->next = answer;

        while(l1 && l2) {
            int sum = l1->val + l2->val;
            current->val = (sum + carry) % 10;
            carry = (sum + carry) / 10;
            if(!(l1->next && l2->next)) break;
            ListNode* nextOne = new ListNode;
            current->next = nextOne;
            current = nextOne;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1->next) {
            l1 = l1->next;
            while(l1) {
                int sum = (l1->val + carry) % 10;
                ListNode* nextOne = new ListNode(sum);
                carry = (l1->val + carry) / 10;
                current->next = nextOne;
                current = nextOne;
                l1 = l1->next;
            }
        } else if(l2->next) {
            l2 = l2->next;
            while(l2) {
                int sum = (l2->val + carry) % 10;
                ListNode* nextOne = new ListNode(sum);
                carry = (l2->val + carry) / 10;
                current->next = nextOne;
                current = nextOne;
                l2 = l2->next;
            }
        }

        if(carry) {
            ListNode* nextOne = new ListNode(carry);
            current->next = nextOne;
            current = nextOne;
        }

        current->next = nullptr;

        return answer;
    }
};

// leetcode solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode;
        ListNode* current = answer;
        int carry = 0;

        while(l1 || l2 || carry) {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;
            sum = val1 + val2 + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        return answer->next;
    }
};
