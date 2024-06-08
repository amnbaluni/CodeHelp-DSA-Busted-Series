https://www.naukri.com/code360/problems/circularly-linked_1070232

bool isCircular(Node *head) {
  if (head == NULL)
    return true; // empty linked list
  if (head->next == NULL)
    return false;
  Node *slow = head;
  Node *fast = head;
  while (slow != NULL && fast != NULL) {
    slow = slow->next;
    fast = fast->next;
    if (fast != NULL)
      fast = fast->next;
    if (slow == fast) {
      if (slow == head) {
        return true;
      } else {
        return false;
      }
    }
  }
  return false;
}
