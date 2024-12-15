void inorderRecursive(struct TreeNode* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);  // Visit left subtree
    printf("%d ", root->data);  // Visit root
    inorderRecursive(root->right);  // Visit right subtree
}

/* In Inorder traversal, the left subtree is visited first, then the root node, followed by the right subtree. In a binary search tree (BST), this traversal visits the nodes in ascending order.

Inorder Traversal Algorithm:

Traverse the left subtree.
Visit the root node.
Traverse the right subtree. */
