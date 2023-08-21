#include <bits/stdc++.h> 
#include<queue>
/**********************************************************************

Following is the Binary Tree node structure already written:

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

**********************************************************************/

int sumAtKthLevel(BinaryTreeNode<int>* root, int k)
{
	 // If the current node is NULL
    if (root == nullptr)
        return 0;
 
    // Create Queue
    queue<BinaryTreeNode<int>*> que;
 
    // Enqueue the root node
    que.push(root);
 
    // Level is used to track
    // the current level
    int level = 0;
 
    // To store the sum of nodes
    // at the Kth level
    int sum = 0;
 
    // flag is used to break out of
    // the loop after the sum of all
    // the nodes at Nth level is found
    int flag = 0;
 
    // Iterate the queue till its not empty
    while (!que.empty()) {
 
        // Calculate the number of nodes
        // in the current level
        int size = que.size();
 
        // Process each node of the current
        // level and enqueue their left
        // and right child to the queue
        while (size--) {
            BinaryTreeNode<int>* ptr = que.front();
            que.pop();
 
            // If the current level matches the
            // required level then calculate the
            // sum of all the nodes at that level
            if (level == k) {
 
                // Flag initialized to 1
                // indicates that sum of the
                // required level is calculated
                flag = 1;
 
                // Calculating the sum of the nodes
                sum += ptr->data;
            }
            else {
 
                // Traverse to the left child
                if (ptr->left)
                    que.push(ptr->left);
 
                // Traverse to the right child
                if (ptr->right)
                    que.push(ptr->right);
            }
        }
 
        // Increment the variable level
        // by 1 for each level
        level++;
 
        // Break out from the loop after the sum
        // of nodes at K level is found
        if (flag == 1)
            break;
    }
    return sum;
}
