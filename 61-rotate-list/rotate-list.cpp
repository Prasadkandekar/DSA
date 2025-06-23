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
        ListNode* temp= head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head== NULL || head->next==NULL)return head;

        ListNode* temp = head;
        ListNode* prev = temp;
        ListNode* newHead;
        int n = lengthOfLL(head);
        int times = k%n;
        while(times--){
            
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;

            }
            if(prev)prev->next = NULL;
            temp->next = head;

            newHead = temp;
            temp = head;
            head = newHead;
            prev = NULL;

        }
        return head;
    }
};