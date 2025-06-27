#ifndef BST_HPP
#define BST_HPP

#include <vector>

enum class TraversalOrder {
    PreOrder,
    InOrder,
    PostOrder
};

template<typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& value);
};

template<typename T>
class BST {
public:
    BST();
    ~BST();

    void insert(const T& val);
    void remove(const T& val);
    bool search(const T& val) const;

    T getMin() const;
    T getMax() const;
    T getPredecessor(const T& val) const;
    T getSuccessor(const T& val) const;
    int getHeight() const;

    std::vector<T> traverse(TraversalOrder order) const;

private:
    TreeNode<T>* root;

    TreeNode<T>* insertNode(TreeNode<T>* node, const T& val);
    TreeNode<T>* deleteNode(TreeNode<T>* node, const T& val);
    bool searchNode(TreeNode<T>* node, const T& val) const;

    TreeNode<T>* findMinNode(TreeNode<T>* node) const;
    TreeNode<T>* findMaxNode(TreeNode<T>* node) const;
    TreeNode<T>* findPredecessor(TreeNode<T>* node, const T& val) const;
    TreeNode<T>* findSuccessor(TreeNode<T>* node, const T& val) const;
    int getHeight(TreeNode<T>* node) const;

    void traversePreOrder(TreeNode<T>* node, std::vector<T>& result) const;
    void traverseInOrder(TreeNode<T>* node, std::vector<T>& result) const;
    void traversePostOrder(TreeNode<T>* node, std::vector<T>& result) const;

    void destroyTree(TreeNode<T>* node);
};

#include "bst.tpp"

#endif // BST_HPP
