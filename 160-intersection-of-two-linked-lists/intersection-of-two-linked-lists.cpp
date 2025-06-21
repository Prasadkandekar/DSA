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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        map<ListNode*,int>NodeMap;
        while(temp1){
            NodeMap[temp1] = 1;
            temp1 = temp1->next;
        }
        while(temp2){
          
          if(NodeMap.find(temp2) != NodeMap.end()){
            return temp2;
          }
          temp2 = temp2->next;
        }

        return nullptr;
    }
};