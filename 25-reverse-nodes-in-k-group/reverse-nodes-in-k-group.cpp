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
    // ListNode* reverseLL(ListNode* head){
    //     if(head==nullptr || head->next==nullptr)return head;
    //     ListNode* newHead = reverseLL(head->next);
    //     ListNode* front = head->next;
    //     front->next = head;
    //     head = nullptr;
    //     return newHead;
    // }
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* findKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp && k>0){
            k--;
            temp= temp->next;
        }
        return temp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp= head, *nextNode, *prevNode = nullptr,*kthNode;
        ListNode* newHead = nullptr;

        while(temp!= nullptr)
        {
            kthNode = findKthNode(temp,k);
            if(kthNode==NULL)
            {
                if(prevNode) prevNode->next = temp;
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = nullptr;
            ListNode* reverseHead = reverseLL(temp);
            if(newHead==nullptr)
            {
               newHead = reverseHead;
            }
            else
            {
                if(prevNode)prevNode->next = reverseHead;
            }
            prevNode = temp;
            temp = nextNode;
        }
       return newHead? newHead:head;
    }
};