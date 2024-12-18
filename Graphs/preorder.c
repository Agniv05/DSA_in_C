#include <stack>
// root  ---> left   ---->  right
void preorderNonRecursive(struct TreeNode* root) {
    if (root == NULL) return;
    std::stack<struct TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        struct TreeNode* current = stack.top();
        stack.pop();
        printf("%d ", current->data);
        
        // Push right and left children to stack (right first)
        if (current->right != NULL) stack.push(current->right);
        if (current->left != NULL) stack.push(current->left);
    }
}
