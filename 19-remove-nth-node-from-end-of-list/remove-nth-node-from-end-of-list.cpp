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
    int lengthOfLL(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* deleteHead(ListNode*head){
       ListNode* prev = head;
       head = head->next;
       delete prev;
       return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==NULL || head->next==NULL)return NULL;

        int len = lengthOfLL(head);
        if(len==n){
            return deleteHead(head);
        }
        int k = len-n-1;
        ListNode* temp = head;
        while(k--){
            temp = temp->next;
        }
        ListNode* front = temp->next;
       if(temp->next)temp->next = temp->next->next;
        delete front;
        return head;
    }
};