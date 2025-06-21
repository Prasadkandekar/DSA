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
        ListNode* temp= headA;
     
        map<ListNode*,int>NodeMap;
        while(temp){
            NodeMap[temp] = 1;
            temp= temp->next;
        }
        temp = headB;
        while(temp){
          
          if(NodeMap.find(temp) != NodeMap.end()){
            return temp;
          }
          temp = temp->next;
        }

        return nullptr;
    }
};