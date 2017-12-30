#include <iostream>
#include <stack>
#include <cstddef>
#include <memory>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 

    ~TreeNode() {
        delete left;
        delete right;
    }

    void add(int x) {
        if (x <= this->val) {
            if (left == nullptr) {
                left = new TreeNode(x);
            }
            else {
                this->left->add(x);
            }
        }
        else {
            if (right == nullptr) {
                right = new TreeNode(x);
            }
            else {
                this->right->add(x);
            }
        }
    }

    void print() {
        if (this == nullptr) {
            return;
        }
        if (left != nullptr) {
            left->print();
        }
        std::cout << val << " ";
        if (right != nullptr) {
            right->print();
        }
    }
};

class BSTIterator {
    private:
        std::stack<TreeNode*> treeNodeStack;

        void pushLeftNodes2Stack(TreeNode* node) {
            while (node != nullptr) {
                treeNodeStack.push(node);
                node = node->left;
            }
        }

    public:
        BSTIterator(TreeNode *root) {
            pushLeftNodes2Stack(root);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !treeNodeStack.empty();
        }

        /** @return the next smallest number */
        int next() {
            if (hasNext()) {
                TreeNode* next = treeNodeStack.top();
                treeNodeStack.pop();
                pushLeftNodes2Stack(next->right);
                return next->val;
            }
        }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    std::unique_ptr<TreeNode> t{new TreeNode{4}};
    t->add(2);
    t->add(3);
    t->add(7);
    t->add(9);
    t->add(5);
    t->add(11);
    t->print();
    BSTIterator bstIt = BSTIterator(t.get());
    std::cout << std::endl;
    while (bstIt.hasNext()) {
        std::cout << bstIt.next() << " ";
    }
    std::cout << std::endl;
    return 0;
}

