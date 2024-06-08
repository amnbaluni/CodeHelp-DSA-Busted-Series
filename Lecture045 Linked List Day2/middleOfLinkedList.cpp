https://www.naukri.com/code360/problems/middle-of-linked-list_973250

Approach 1
int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    int len = getLength(head);
    int ans = (len/2);
    Node* temp = head;
    int cnt = 0;
    while(cnt<ans){
        temp = temp->next;
        cnt++;
        
    }
    return temp;
}

Approach 2 - slow&fast
ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }  
