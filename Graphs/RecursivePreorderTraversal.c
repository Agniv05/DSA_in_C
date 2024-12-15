void preorderRecursive(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);  // Visit root
    preorderRecursive(root->left);  // Visit left subtree
    preorderRecursive(root->right);  // Visit right subtree
}


/* In Preorder traversal, the root node is visited first, followed by the left subtree and then the right subtree.

Preorder Traversal Algorithm:

Visit the root node.
Traverse the left subtree.
Traverse the right subtree.  */
