class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {


        if(head==NULL || head->next==NULL){
            return head;
        }

        int count = 1;

        ListNode *temp = head;
        ListNode *prev = NULL;

        while(count<=k && temp){
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
            count++;
        }

        if(count<=k){
            
            temp=prev;
            prev=NULL;

            while(temp){
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
            
             }

             

        }

        else{

        ListNode *oldHead = head;
        head->next=temp;
        head=prev;

        oldHead->next = reverseKGroup(temp,k);

        }

        return head;

    }
};