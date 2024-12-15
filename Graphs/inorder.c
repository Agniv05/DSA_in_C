#include <stack>

void inorderNonRecursive(struct TreeNode* root) {
    std::stack<struct TreeNode*> stack;
    struct TreeNode* current = root;
    
    while (current != NULL || !stack.empty()) {
        while (current != NULL) {
            stack.push(current);
            current = current->left;  // Reach the leftmost node
        }
        
        current = stack.top();
        stack.pop();
        printf("%d ", current->data);  // Visit the node
        current = current->right;  // Visit the right subtree
    }
}
