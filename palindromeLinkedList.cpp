class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* head2 = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow ->next;
            fast = fast->next->next;
        }
        
        ListNode* prev= nullptr;
        while(slow != nullptr){
            ListNode* curr = slow->next;
            slow->next = prev;
            prev = slow;
            slow = curr;      
        }
        
        while(head2 != nullptr && prev != nullptr){
            if(head2->val != prev->val){
                return false;
            }
            
            head2 = head2->next;
            prev = prev->next;
        }
        
        return true;
        
    }
};