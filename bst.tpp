#ifndef BST_TPP
#define BST_TPP

#include <stdexcept>
#include <bst.hpp>


template <typename T>
TreeNode<T>::TreeNode(const T& value) : val(value), left(nullptr), right(nullptr){}

template <typename T>
BST<T>::BST() : root(nullptr){}

template <typename T>
BST<T>::~BST(){destroyTree(root);}

template <typename T>
void BST<T>::destroyTree(TreeNode<T>* node){
    if(!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

template <typename T>
void BST<T>::insert(const T& val){
    root = insertNode(root,val);
}

template <typename T>
TreeNode<T>* BST<T>::insertNode(TreeNode<T>* node, const T& val){
    if(!node){
        return new TreeNode<T>(val);
    };
    if(node->val > val){
        node->left = insert(node->left,val);
    }
    else if(node->val < val){
        node->right = insert(node->right,val)
    }
    return node;
}

template <typename T>
void BST<T>::remove(const T& val){
    root = deleteNode(root,val);
}

template <typename T>
TreeNode<T>* BST<T>::deleteNode(TreeNode<T>* node,const T& val){
    if(!node) return nullptr;

    if(node->val > val){
        node->left = deleteNode(node->left,val);
    }
    else if(node->val < val){
        node->right = deleteNode(node->right,val);
    }
    else{

        if(!node->left){
            TreeNode<T>* temp = node->right;
            delete node;
            return temp;
        }
        else if(!node->right){
            TreeNode<T>* temp = node->left;
            delete node;
            return temp;
        }
        else{
            TreeNode<T>* successor = findMinNode(node->right);
            node->val = successor->val;
            node->right = deleteNode(node->right,successor->val);
        }

    }
    return node;
}

template <typename T>
bool BST<T>::search(const T& val) const{
    root = searchNode(root, val);
}

template <typename T>
bool BST<T>::searchNode(TreeNode<T>* node, const T& val) const{
    if(!node) return false;
    if(val == node->val) return true;

    if(node->val > val){
        return searchNode(node->left,val);
    }
    else if(node->val < val){
        return searchNode(node->right,val);
    }

    return false;
}

template <typename T>
T BST<T>::getMin() const{
    TreeNode<T>* minNode = findMinNode(root);
    if(!minNode) {
        throw std::runtime_error("Tree empty");
    }
    return minNode->val;
}

template <typename T>
T BST<T>::getMax() const{
    TreeNode<T>* maxNode = findMaxNode(root);
    if(!minNode) {
        throw std::runtime_error("Tree empty");
    }
    return maxNode->val;
}

template <typename T>
TreeNode<T>* BST<T>::findMinNode(TreeNode<T>* node) const{
    if(!node) return nullptr;
    while(node->left){
        node = node->left;
    }
    return node;
}

template <typename T>
TreeNode<T>* BST<T>::findMaxNode(TreeNode<T>* node) const{
    if(!node) return nullptr;
    while(node->right){
        node = node->right;
    }
    return node;
}

template <typename T>
T BST<T>::getPredecessor(const T& val) const{
    TreeNode<T>* pred= findPredecessor(root val);
    if(!pred) throw std::runtime_error("pred not found");
    return pred->val;
}
    
template <typename T> 
T BST<T>::getSuccessor(const T& val) const{
    TreeNode<T>* pred= findSuccessor(root val);
    if(!pred) throw std::runtime_error("pred not found");
    return pred->val;
}

template<typename T>
TreeNode<T>* BST<T>::findPredecessor(TreeNode<T>* node, const T& val) const {
    TreeNode<T>* curr = root;
    TreeNode<T>* pred = nullptr;
    while (curr) {
        if (val > curr->val) {
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return pred;
}

template<typename T>
TreeNode<T>* BST<T>::findSuccessor(TreeNode<T>* node, const T& val) const {
    TreeNode<T>* curr = root;
    TreeNode<T>* succ = nullptr;
    while (curr) {
        if (val < curr->val) {
            succ = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return succ;
}

template <typename T>
int BST<T>::getHeight() const{
    return getHeight(root);
}

template <typename T>
int BST<T>::getHeight(TreeNode<T>* node) const{
    if(!node) return -1;
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return 1 + std::max(left,right);
}

template <typename T>
std::vector<T> BST<T>::traverse(TraversalOrder order) const {
    std::vector<int> res;
    if (order == TraversalOrder::PreOrder){
        traversePreOrder(root,res);
    }
    else if(order == TraversalOrder::InOrder){
        traverseInOrder(root,res);
    }
    else{
        traversePostOrder(root,res);
    }

    return res;
}

template<typename T>
void BST<T>::traversePreOrder(TreeNode<T>* node, std::vector<T>& result) const {
    if (!node) return;
    result.push_back(node->val);
    traversePreOrder(node->left, result);
    traversePreOrder(node->right, result);
}

template<typename T>
void BST<T>::traverseInOrder(TreeNode<T>* node, std::vector<T>& result) const {
    if (!node) return;
    traverseInOrder(node->left, result);
    result.push_back(node->val);
    traverseInOrder(node->right, result);
}

template<typename T>
void BST<T>::traversePostOrder(TreeNode<T>* node, std::vector<T>& result) const {
    if (!node) return;
    traversePostOrder(node->left, result);
    traversePostOrder(node->right, result);
    result.push_back(node->val);
}



#endif