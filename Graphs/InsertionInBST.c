void insert(struct node *root, int key){
  struct node* new = createNode(key);
  struct node* prev=NULL;
  while (root!=NULL){//Traverses node to find if already present
    prev=root;//sets prev pointer to new root everytime
    if (root->data==key){
      printf("Already in BST");
    }
    else if (root->data<key){
      root=root->right;
    }
    else{
      root=root->left;
    }
  }//prev now points to the last root after which key is to be present
  if (key<prev->data){
    prev->left=new;
  }
  else{
    prev->right=new;
  }
}
