struct node *deleteNode(struct node *root, int value){
   struct node* iPre;
   if (root == NULL){//if root doesnt exist
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){//if root is the only node
        free(root);
    }

    //searching for the node to be deleted
    if (value < root->data){
        deleteNode(root->left,value);
    }
    else if (value > root->data){
        deleteNode(root->right,value);
    }
    //Deletion stategy
    else{
        iPre = inOrderPredecessor(root); //inorder predecessor
        root->data = iPre->data;  //stroes data of node to be deleted in Ipre
        deleteNode(root->left, iPre->data); //recursively calls function until root==node to be deleted
    }
}
