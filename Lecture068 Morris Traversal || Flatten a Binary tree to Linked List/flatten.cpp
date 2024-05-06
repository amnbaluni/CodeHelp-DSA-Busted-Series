void flatten(Node *root)
    {
        Node* currNode = root;
        while(currNode != NULL){
            if(currNode->left){
                Node* pred = currNode->left;
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = currNode->right;
                currNode -> right = currNode->left;
                //currNode ke left ko null krdo
                currNode->left = NULL;
            }
            currNode = currNode->right;
        }
    }
