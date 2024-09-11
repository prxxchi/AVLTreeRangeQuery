#include "AVLTree.h"

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
void AVLTree<T>::insert(T key) {
    root = insert(root, key);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::insert(Node* node, T key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    return balance(node);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::balance(Node* node) {
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && node->left != nullptr && node->key > node->left->key) {
        return rotateRight(node);
    }

    if (balanceFactor < -1 && node->right != nullptr && node->key < node->right->key) {
        return rotateLeft(node);
    }

    if (balanceFactor > 1 && node->left != nullptr && node->key < node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balanceFactor < -1 && node->right != nullptr && node->key > node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

template <typename T>
int AVLTree<T>::getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

template <typename T>
int AVLTree<T>::getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

template <typename T>
void AVLTree<T>::rangeQuery(T low, T high) {
    rangeQuery(root, low, high);
    std::cout << std::endl;
}

template <typename T>
void AVLTree<T>::rangeQuery(Node* node, T low, T high) {
    if (node == nullptr) return;

    if (node->key > low) {
        rangeQuery(node->left, low, high);
    }

    if (node->key >= low && node->key <= high) {
        std::cout << node->key << " ";
    }

    if (node->key < high) {
        rangeQuery(node->right, low, high);
    }
}
