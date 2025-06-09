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
        int cnt = 0 ;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)return NULL;

        int len = lengthOfLL(head);
        int k = len/2;
        ListNode* temp = head;
        while(--k){
            temp = temp->next;
        }        

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
    }
};