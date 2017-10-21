#include <stdlib.h>
#include <iostream>
#include <vector>
#include <forward_list>
#include <queue>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
        cout << val << " ";
        if (right != nullptr) {
            right->print();
        }
    }

    int kthSmallest(int k) {
        static vector<int> bst2Array;
        if (left != nullptr) {
            left->kthSmallest(k);
        }
        bst2Array.push_back(val);
        if (right != nullptr) {
            right->kthSmallest(k);
        }
        return bst2Array.size() < k ? -1 : bst2Array[k-1];
    }

    int maxDepth() {
        if (this == nullptr) {
            return 0;
        }
        return 1 + max(left->maxDepth(), right->maxDepth());
    }
};

class Solution {
public:

    void preorderTraversalRec(TreeNode* node, vector<int>& preorderArray) {
        if (node == nullptr) return;
        preorderArray.push_back(node->val);
        preorderTraversalRec(node->left, preorderArray);
        preorderTraversalRec(node->right, preorderArray);
    }

    // 144. Binary Tree Preorder Traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderArray;
        preorderTraversalRec(root, preorderArray);
        return preorderArray;
    }

    void inorderTraversalRec(TreeNode* node, vector<int>& inorderArray) {
        if (node == nullptr) return;
        inorderTraversalRec(node->left, inorderArray);
        inorderArray.push_back(node->val);
        inorderTraversalRec(node->right, inorderArray);
    }

    // 94. Binary Tree Inorder Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderArray;
        inorderTraversalRec(root, inorderArray);
        return inorderArray;
    }

    void postorderTraversalRec(TreeNode* node, vector<int>& postorderArray) {
        if (node == nullptr) return;
        postorderTraversalRec(node->left, postorderArray);
        postorderTraversalRec(node->right, postorderArray);
        postorderArray.push_back(node->val);
    }

    // 145. Binary Tree Postorder Traversal
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderArray;
        postorderTraversalRec(root, postorderArray);
        return postorderArray;
    }

    void kthSmallestWithSortingHelper(TreeNode* root, vector<int>& bst2Array) {
        if (root->left != nullptr) {
            kthSmallestWithSortingHelper(root->left, bst2Array);
        }
        bst2Array.push_back(root->val);
        if (root->right != nullptr) {
            kthSmallestWithSortingHelper(root->right, bst2Array);
        }
    }

    // 230. Kth Smallest Element in a BST
    int kthSmallestWithSorting(TreeNode* root, int k) {
        vector<int> bst2Array;
        kthSmallestWithSortingHelper(root, bst2Array);
        return bst2Array.size() < k ? -1 : bst2Array[k-1];
    }

    int kthSmallestRecursive(TreeNode* root, int k, unsigned& counter) {
        if (root == nullptr) return -1;
        int smallest = kthSmallestRecursive(root->left, k, counter);
        if (smallest != -1)  return smallest;
        ++counter;
        if (counter == k) {
            return root->val;
        }
        smallest = kthSmallestRecursive(root->right, k, counter);
        if (smallest != -1)  return smallest;
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        unsigned counter = 0;
        return kthSmallestRecursive(root, k, counter);
    }

    // 104. Maximum Depth of Binary Tree
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // 111. Minimum Depth of Binary Tree
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr) return 1 + minDepth(root->right);
        if (root->right == nullptr) return 1 + minDepth(root->left);
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }

    // 226. Invert Binary Tree
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* auxNode = root->left;
        root->left = root->right;
        root->right = auxNode;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // 100. Same Tree
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // 617. Merge Two Binary Trees
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        return (left->val == right->val && 
                isSymmetric(left->left, right->right) && 
                isSymmetric(left->right, right->left));
    }

    // 101. Symmetric Tree
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }

    void sumOfLeftLeavesRec(TreeNode* node, int& sum, bool isLeft) {
        if (node == nullptr) return;
        if (isLeft && node->left == nullptr && node->right == nullptr) sum += node->val;
        sumOfLeftLeavesRec(node->left, sum, true);
        sumOfLeftLeavesRec(node->right, sum, false);
    }

    // 404. Sum of Left Leaves
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        sumOfLeftLeavesRec(root->left, sum, true);
        sumOfLeftLeavesRec(root->right, sum, false);
        return sum;
    }

    // 105. Construct Binary Tree from Preorder and Inorder Traversal
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto posRootInorder = find(inorder.begin(), inorder.end(), preorder[0]);
        preorder.erase(preorder.begin());
        std::vector<int> inorderLeft(inorder.begin(), posRootInorder);
        std::vector<int> inorderRight(posRootInorder+1, inorder.end());
        root->left = buildTree(preorder, inorderLeft);
        root->right = buildTree(preorder, inorderRight);
        return root;
    }

    TreeNode* buildTree(forward_list<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(*preorder.begin());
        auto posRootInorder = find(inorder.begin(), inorder.end(), *preorder.begin());
        preorder.pop_front();
        std::vector<int> inorderLeft(inorder.begin(), posRootInorder);
        std::vector<int> inorderRight(posRootInorder+1, inorder.end());
        root->left = buildTree(preorder, inorderLeft);
        root->right = buildTree(preorder, inorderRight);
        return root;
    }

    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
        std::forward_list<int> preorderList(preorder.begin(), preorder.end());
        return buildTree(preorderList, inorder);
    }

    bool isValidBST(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr) return true;
        if (!isValidBST(node->left, prev)) return false;
        if (prev != nullptr && node->val <= prev->val) return false;
        prev = node;
        if (!isValidBST(node->right, prev)) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValidBST(root, prev);
    } 

    int sumNumbersRec(TreeNode* node, std::string rootToLeafStr) {
        if (node == nullptr) {
            return 0;
        }
        rootToLeafStr += '0' + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return std::stoi(rootToLeafStr);
        }
        return sumNumbersRec(node->left, rootToLeafStr) +
            sumNumbersRec(node->right, rootToLeafStr);
    }

    // 129. Sum Root to Leaf Numbers
    int sumNumbers(TreeNode* root) {
        return sumNumbersRec(root, "");
    }

	// 102. Binary Tree Level Order Traversal
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        std::vector<std::vector<int>> levelOrderTraversals{};
        std::queue<std::pair<TreeNode*, int>> nodeQ;
        int currLvl = 0;
        nodeQ.emplace(root, currLvl);
        levelOrderTraversals.emplace_back();

        while (!nodeQ.empty()) {
            auto qElem = nodeQ.front();
            nodeQ.pop();
            TreeNode* node = qElem.first;
            if (qElem.second != currLvl) {
                levelOrderTraversals.emplace_back();
                currLvl = qElem.second;
            }
            levelOrderTraversals.back().push_back(node->val);
            if (node->left) {
                nodeQ.emplace(node->left, currLvl+1);
            }
            if (node->right) {
                nodeQ.emplace(node->right, currLvl+1);
            }
        }

        return levelOrderTraversals;
    }
};

int main(int argc, char** argv) {
    TreeNode* t = new TreeNode(4);
    t->add(2);
    t->add(3);
    t->add(7);
    t->add(9);
    t->add(5);
//    t->add(11);
    t->print();
    Solution sol;
//    cout << "\n" << sol.kthSmallest(t,atoi(argv[1])) << "\n";
    cout << "Max depth = " << sol.maxDepth(t) << endl;
    cout << "Min depth = " << sol.minDepth(t) << endl;
//    TreeNode* n = sol.invertTree(t);
//    cout << endl;
//    n->print();
    vector<int> pre = sol.inorderTraversal(t);
    cout << endl;
    for (auto elem:pre) cout << elem << " ";
    cout << endl;
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->right->right = new TreeNode(3);
    cout << sol.isSymmetric(t1) << endl;
    cout << "Sum of left leaves: " << sol.sumOfLeftLeaves(t) << endl;
    std::vector<int> preorder = {1,2,3,4};
    std::vector<int> inorder = {3,2,4,1};
//    sol.buildTree(preorder, inorder)->print();
    sol.buildTree2(preorder, inorder)->print();
    TreeNode* bst = new TreeNode(1);
    bst->left = new TreeNode(1);
//    bst->left->right = new TreeNode(4);
//    bst->right = new TreeNode(7);
//    bst->right->left = new TreeNode(5);
    cout << endl << sol.isValidBST(bst) << endl;
    cout << endl << sol.sumNumbers(t) << endl;
    cout << endl << "----level order traversal----" << endl;
    for (auto traversal:sol.levelOrder(t)) {
        for (auto level:traversal) {
            cout << level << " ";
        }
        cout << endl;
    }
    cout << endl;
	return 0;
}

