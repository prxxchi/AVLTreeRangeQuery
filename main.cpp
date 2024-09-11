#include <iostream>
#include "AVLTree.h"

int main() {
    AVLTree<int> tree;

    // Insert elements
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    // Perform range query
    std::cout << "Nodes in range [15, 45]: ";
    tree.rangeQuery(15, 45);

    return 0;
}
