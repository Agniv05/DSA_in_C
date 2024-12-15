#include <stack>

void postorderNonRecursive(struct TreeNode* root) {
    if (root == NULL) return;
    
    std::stack<struct TreeNode*> stack1, stack2;
    stack1.push(root);
    
    while (!stack1.empty()) {
        struct TreeNode* current = stack1.top();
        stack1.pop();
        stack2.push(current);
        
        // Push left and right children to stack1
        if (current->left != NULL) stack1.push(current->left);
        if (current->right != NULL) stack1.push(current->right);
    }
    
    // Print nodes in reverse order of stack2 (Postorder)
    while (!stack2.empty()) {
        struct TreeNode* node = stack2.top();
        stack2.pop();
        printf("%d ", node->data);
    }
}
