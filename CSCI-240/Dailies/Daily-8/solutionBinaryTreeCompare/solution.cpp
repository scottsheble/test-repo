#include <queue>
#include "treenode.h"

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;  
    }
    if (!p || !q) {
        return false;  
    }

    return (p->value == q->value) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

bool isSymmetricTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;  
    }
    if (!p || !q) {
        return false;  
    }

    return (p->value == q->value) &&
           isSymmetricTree(p->left, q->right) &&
           isSymmetricTree(p->right, q->left);
}

bool isOneTreePartOfAnother(TreeNode* p, TreeNode* q) {
    if (!p) {
        return true;  
    }
    if (!q) {
        return false;  
    }

    return isSameTree(p, q) || isOneTreePartOfAnother(p, q->left) || isOneTreePartOfAnother(p, q->right);
}

bool isSameHeap(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;  
    }
    if (!p || !q) {
        return false;  
    }

    bool left_heap_p = (!p->left) || (p->value >= p->left->value && isSameHeap(p->left, nullptr));
    bool right_heap_p = (!p->right) || (p->value >= p->right->value && isSameHeap(p->right, nullptr));

    bool left_heap_q = (!q->left) || (q->value >= q->left->value && isSameHeap(q->left, nullptr));
    bool right_heap_q = (!q->right) || (q->value >= q->right->value && isSameHeap(q->right, nullptr));

    return isSameTree(p, q) && left_heap_p && right_heap_p && left_heap_q && right_heap_q;
}

int getWidth(TreeNode* root, int level, bool left, std::vector<int>& width) {
    if (!root) {
        return 0;
    }

    if (level == 1) {
        width[left ? 0 : 1] = 1;  
        return 1;
    }

    int left_width = getWidth(root->left, level - 1, true, width);
    int right_width = getWidth(root->right, level - 1, false, width);

    return left_width + right_width;
}

int getHeight(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left_height = getHeight(root->left);
    int right_height = getHeight(root->right);

    return std::max(left_height, right_height) + 1;
}

bool ofSameWidth(TreeNode* p, TreeNode* q) {
    int height_p = getHeight(p);
    int height_q = getHeight(q);

    if (height_p != height_q) {
        return false;  
    }

    for (int level = 1; level <= height_p; ++level) {
        std::vector<int> width_p(2, 0);
        std::vector<int> width_q(2, 0);

        getWidth(p, level, true, width_p);
        getWidth(q, level, false, width_q);

        if (width_p != width_q) {
            return false;  
        }
    }

    return true;  
}