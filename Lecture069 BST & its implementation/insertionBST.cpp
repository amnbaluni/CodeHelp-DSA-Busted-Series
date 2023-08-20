class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* insertIntoBST(node* root, int d){
 if(root==NULL){
   root = new node(data);
   return root;
  }
  if(d > root->data){
    root->right = insertIntoBST(root->right, d)
      }
 else(d < root->data){
    root->left = insertIntoBST(root->left, d)
      }
   return root;
}

void takeInput(node* &root){
  int data;
  cin>>data;
  while(data!=-1){
    root = insertIntoBST(root, data);
    return root;
  }
}

int main(){
  node* root = NULL;
  cout<<"Enter data to create BST"<<endl;
  takeInput(root);
  return 0;
}

