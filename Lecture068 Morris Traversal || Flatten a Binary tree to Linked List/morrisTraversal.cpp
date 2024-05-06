1. Initialize current as root 
2. While current is not NULL
   If current hs a left child
      ifa) Make current as right child of the rightmost 
         node in current's left subtree
      ifb) Go to this left child, i.e., current = current->left
   Else
      ea) Print current’s data
      eb) Go to the right, i.e., current = current->right


Code
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curNode = root;
        vector<int> nodes;
        
        while (curNode != NULL) 
        {
            if (curNode -> left) 
            {
						   //Find the inorder predecessor of current
               //ifa) Make current as right child of the rightmost node in current's left subtree
                TreeNode* predecessor = curNode -> left;
                while (predecessor -> right && predecessor -> right != curNode) //second condition used when reverting
                    predecessor = predecessor -> right;
                
                if ((predecessor -> right)==NULL) 
                {
                    predecessor -> right = curNode;
                    curNode = curNode -> left; //ifb) Go to this left child
                }
                else 
                {
                    //Revert back the changes
                    predecessor -> right = NULL;
                    nodes.push_back(curNode -> val);
                    curNode = curNode -> right;
                }
            }
            else 
            {
                nodes.push_back(curNode -> val);  //ea)
                curNode = curNode -> right;  //eb)
            }
        }
        
        return nodes;
    }
};
