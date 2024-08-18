class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
        return head;

        //count number of nodes
        int count=0;
        ListNode *temp=head;
        while(temp){
            count++;
            temp=temp->next;
        };
        k=k%count;
        if(k==0){
            return head;
        }
        count -=k;
        ListNode *curr=head,*prev=NULL;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        ListNode*Tail=curr;
        //sencond list uske last node pe leke jaao
        while(Tail->next!=NULL){
            Tail=Tail->next;
        }
        Tail->next=head;
        head=curr;
        return head;
        
    }
};