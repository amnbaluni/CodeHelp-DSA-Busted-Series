Approach 1 - iterative method
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if (head == NULL || head->next == NULL) {
            return head;
        }

        LinkedListNode<int> *prev = NULL;
        LinkedListNode<int> *curr = head;
        LinkedListNode<int> *forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
}

Approach 2 - Recursive method
 void reverse(ListNode* &head,ListNode* &prev){
        if(head==NULL ) return ;
        ListNode* curr =head;
        ListNode* forward;
  
        if(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
        reverse(forward,prev);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev =NULL;
        reverse(head,prev);
        return prev;
    }
};
