TC = SC = O(N)

Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
        // starting mein root ka parent to null hoga
        nodeToParent[root] = NULL;
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->data == target){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent){
        map<Node*, bool> visited;
        queue<Node*> q;
        int time = 0;
        q.push(root);
        visited[root] = true;
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i=0; i<size; i++){
                //process neighbouring nodes
                Node* front = q.front();
                q.pop();
                //check for left
                if(front->left && visited[front->left]!=true){
                    q.push(front->left);
                    visited[front->left] = true;
                    flag = 1;
                }
                //check for right
                if(front->right && visited[front->right]!=true){
                    q.push(front->right);
                    visited[front->right] = true;
                    flag = 1;
                }
                //check for parent
                if(nodeToParent[front] && visited[nodeToParent[front]] != true){
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                    flag = 1;
                }
            }
            if(flag) time++;
        }
        return time;
    }
    int minTime(Node* root, int target) 
    {
        //step1 - create Node to parent mapping
        map<Node*, Node*> nodeToParent;
        //step2 - find target node
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        //step3 - burn the tree
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
