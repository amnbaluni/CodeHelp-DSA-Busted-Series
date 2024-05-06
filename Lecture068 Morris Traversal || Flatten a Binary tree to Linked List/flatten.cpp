void flatten(Node *root)
    {
        Node* currNode = root;
        while(currNode != NULL){
            if(currNode->left){
                Node* pred = currNode->left;   /finding predecessor
                while(pred->right){
                    pred = pred->right;   //last rightmost node tak jao
                }
                pred->right = currNode->right;  //us node ke right ko currNode ke right se link krdo
                currNode -> right = currNode->left;   //currNode ke right ko left se link krdo
                //currNode ke left ko null krdo
                currNode->left = NULL;
            }
            currNode = currNode->right;
        }
    }
