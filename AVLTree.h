#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <vector>

template <typename T>
class AVLTree {
public:
    AVLTree();
    void insert(T key);
    void rangeQuery(T low, T high);

private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        int height;
        Node(T key) : key(key), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;
    Node* insert(Node* node, T key);
    Node* balance(Node* node);
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    void rangeQuery(Node* node, T low, T high);
};

#include "AVLTree.cpp"
#endif
