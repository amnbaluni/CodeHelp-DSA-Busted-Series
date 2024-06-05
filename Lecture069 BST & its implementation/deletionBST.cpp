struct Node {
    int key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//Function to find minimum value in a BST
Node* min_val(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

//Function to find maximum value in a BST
Node* max_val(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

 
/* Given a binary search tree and a key, this function
   deletes the key and returns the new root */
Node* deleteNode(Node* root, int val)
{
    //base case
    if(root == NULL){
        return root;
    }
    if(root->data == val){
        //we will have three cases here
        //CASE 1 - 0 Child -> delete leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //CASE 2 - we have only 1 child
        if(root->left != NULL && root->right == NULL){   //we have only left child
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){   //we have only right child
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //CASE 3 - we have 2 child nodes
        if(root->left != NULL && root->right != NULL){
            int mini_val = min_val(root)->data;
            root->data = mini_val;
            root->right = deleteNode(root->right, mini_val);
            return root;
        }
    }
    else if(root->data > val){
        //left wale part me jao
        root->left = deleteNode(root->data, val);
        return root;
    }
    else(root->data < val){
        //right wale part me jao
        root->right = deleteNode(root->data, val);
        return root;
    }
}
 
