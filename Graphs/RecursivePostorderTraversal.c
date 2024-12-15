void postorderRecursive(struct TreeNode* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);  // Visit left subtree
    postorderRecursive(root->right);  // Visit right subtree
    printf("%d ", root->data);  // Visit root
}

/* In Postorder traversal, the left subtree is visited first, then the right subtree, and the root node is visited last.

Postorder Traversal Algorithm:

Traverse the left subtree.
Traverse the right subtree.
Visit the root node. */
