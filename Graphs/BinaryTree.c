/* Binary Tree
A binary tree is a tree data structure where each node has at most two children: a left child and a right child.

Binary Search Tree (BST)
A binary search tree is a binary tree in which for every node:

All the nodes in its left subtree have values less than the node's value.
All the nodes in its right subtree have values greater than the node's value. */

// Insert a new node in the BST
struct TreeNode* insertBST(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else {
        root->right = insertBST(root->right, value);
    }
    return root;
}

/* An AVL tree is a self-balancing binary search tree where the difference between the heights of the left and right subtrees (the balance factor) is at most 1 for all nodes.

Rotation operations (left and right) are performed to maintain balance during insertion and deletion.

Left Rotation: Used when the right subtree is taller.
Right Rotation: Used when the left subtree is taller.
3. Heaps
A heap is a specialized binary tree-based data structure that satisfies the heap property:

Min-Heap: The value of each node is greater than or equal to the value of its parent.
Max-Heap: The value of each node is less than or equal to the value of its parent.
Min-Heap and Max-Heap
In a min-heap, the smallest element is always at the root, and in a max-heap, the largest element is at the root. */

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
