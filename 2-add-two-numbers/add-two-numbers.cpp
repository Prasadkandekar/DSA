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
class Solution {
public:
//Navie solution : using two stacks will work 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp= dummyHead;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        while(t1 || t2){
            int sum = carry;
            if(t1) sum +=t1->val;
            if(t2) sum += t2->val;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            temp->next = newNode;
            temp = temp->next;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return dummyHead->next;
    }
};