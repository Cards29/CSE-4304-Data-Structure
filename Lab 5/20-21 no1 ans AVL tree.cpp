#include <iostream>
#include <algorithm>

struct AVLNode {
    int timeslot;
    int height;
    AVLNode* left;
    AVLNode* right;
    
    AVLNode(int val) : timeslot(val), height(1), left(nullptr), right(nullptr) {}
};

// Utility function to get the height of the tree
int height(AVLNode* node) {
    return node ? node->height : 0;
}

// Utility function to get balance factor of a node
int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotate
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert a timeslot in AVL tree
AVLNode* insert(AVLNode* node, int timeslot) {
    if (!node) return new AVLNode(timeslot);

    if (timeslot < node->timeslot)
        node->left = insert(node->left, timeslot);
    else if (timeslot > node->timeslot)
        node->right = insert(node->right, timeslot);
    else
        return node; // No duplicates allowed

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && timeslot < node->left->timeslot)
        return rightRotate(node);

    if (balance < -1 && timeslot > node->right->timeslot)
        return leftRotate(node);

    if (balance > 1 && timeslot > node->left->timeslot) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && timeslot < node->right->timeslot) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find nearest reservations before and after a given timeslot
void findBeforeAfter(AVLNode* node, int timeslot, int& before, int& after) {
    if (!node) return;

    if (node->timeslot < timeslot) {
        before = node->timeslot;
        findBeforeAfter(node->right, timeslot, before, after);
    } else if (node->timeslot > timeslot) {
        after = node->timeslot;
        findBeforeAfter(node->left, timeslot, before, after);
    }
}

// Count reservations before a given timeslot
int countBefore(AVLNode* node, int timeslot) {
    if (!node) return 0;
    if (node->timeslot < timeslot)
        return 1 + countBefore(node->left, timeslot) + countBefore(node->right, timeslot);
    return countBefore(node->left, timeslot);
}

// Check if there is a reservation within 3 minutes of a timeslot
bool isFreeWithinRange(AVLNode* node, int timeslot) {
    int before = -1, after = -1;
    findBeforeAfter(node, timeslot, before, after);
    return (before == -1 || timeslot - before > 3) && (after == -1 || after - timeslot > 3);
}

int main() {
    AVLNode* root = nullptr;

    // Sample reservations
    root = insert(root, 25);
    root = insert(root, 29);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 75);

    // Make a reservation at 45 if possible
    int timeslot = 45;
    if (isFreeWithinRange(root, timeslot)) {
        root = insert(root, timeslot);
        std::cout << "Reservation at " << timeslot << " added.\n";
    } else {
        std::cout << "Cannot add reservation at " << timeslot << ".\n";
    }

    // Find nearest reservations before and after a given timeslot
    int before = -1, after = -1;
    findBeforeAfter(root, timeslot, before, after);
    std::cout << "Before: " << before << ", After: " << after << "\n";

    // Count reservations before a given timeslot
    int count = countBefore(root, timeslot);
    std::cout << "Count before " << timeslot << ": " << count << "\n";

    return 0;
}
