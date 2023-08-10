#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
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


Node *removeDuplicates(Node *head)
{
    if (!head || !head->next) {
        return head; // No duplicates in an empty or single-element list
    }

    unordered_set<int> seen_values;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (seen_values.find(current->data) != seen_values.end()) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            seen_values.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
    return head;
}
