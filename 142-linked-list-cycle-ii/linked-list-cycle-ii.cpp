/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return NULL;
        // Node* slow = head;
        // Node* fast = head;

        // while(fast != NULL && fast->next != NULL){
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        ListNode* temp = head;
        map<ListNode* , int> mp;
        while(temp != NULL){
            if(mp.find(temp)!= mp.end()){
                return temp;
            }
            mp[temp] = 1;
            temp = temp->next;

        }
        return NULL;

    }
};