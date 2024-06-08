https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644

/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // don't reverse anything if size<k
    int size=0;
    Node* temp = head;
    while(temp!=NULL) {
        temp = temp->next;
        size++;
    }

    if(size<k) 
    return head;

    // base call
    if(head==NULL) 
    return NULL;

    // step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt=0;

    while( curr!=NULL && cnt<k ) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    } 
    // step2: recursion dekh lega aage ka
    if(next!=NULL)
    head->next = kReverse(next, k);
    // step3: return head of reverse list
    return prev;
}

************************************************************************************************************************************

ListNode* getkthNode(ListNode* temp, int k){
        k = k-1;
        while(temp!=NULL && k!=0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp != NULL){
            ListNode* kthNode = getkthNode(temp, k);
            if(kthNode==NULL){
                if(prevLast!=NULL){
                    prevLast->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp==head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
