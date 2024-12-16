

# AVL Tree Range Query Project

This project implements an **AVL Tree** in C++ to perform range queries efficiently. The AVL tree is a self-balancing binary search tree (BST), where the difference between heights of left and right subtrees cannot be more than one for all nodes. The tree supports insertion, deletion, and querying of elements within a given range.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Insert**: Adds an element to the AVL tree, ensuring the tree remains balanced.
- **Delete**: Removes an element from the tree and rebalances it.
- **Range Query**: Retrieves all elements between a specified range.
- **Self-Balancing**: Ensures `O(log n)` time complexity for insertion, deletion, and querying.

## Prerequisites

To run this project, you need:

- A C++ compiler (e.g., GCC, Clang)
- Basic knowledge of the command line
-  An IDE such as Visual Studio Code, CLion, or any other C++ development environment

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/prxxchi/AVLTreeRangeQuery.git
   ```

2. Navigate to the project directory:
   ```bash
   cd avl-tree-range-query
   ```

3. Compile the code:
   ```bash
   g++ -o avl_tree main.cpp avl_tree.cpp
   ```

4. Run the executable:
   ```bash
   ./avl_tree
   ```

## Usage

The project demonstrates basic operations of the AVL Tree. After compiling and running, you will be prompted to insert, delete, or perform range queries. 

### Example Operations:
- **Insert Element**: Adds a new node to the AVL tree.
- **Delete Element**: Removes a node from the tree while keeping it balanced.
- **Range Query**: Returns all elements between two values (inclusive).

## Code Structure

- `avl_tree.h`: Header file containing the definition of the AVL Tree class.
- `avl_tree.cpp`: Implements the AVL Tree operations like insertion, deletion, and balancing.
- `main.cpp`: The main file to run and test the AVL Tree with example inputs.
  
The key class and functions are:

- `Node`: Represents a node in the AVL tree.
- `insert()`: Inserts a node and rebalances the tree.
- `deleteNode()`: Deletes a node and ensures balance.
- `rangeQuery()`: Returns all values between a given range.

## Example

Here’s an example of how the project works:

```cpp
int main() {
    AVLTree tree;
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    
    tree.deleteNode(20);
    
    std::vector<int> result = tree.rangeQuery(5, 25);
    
    for (int val : result) {
        std::cout << val << " ";
    }
    
    return 0;
}
```

**Expected Output**:
```
10 30
```

## Contributing

Contributions are welcome! If you’d like to improve this project, feel free to fork the repository and submit a pull request.

1. Fork the project.
2. Create your feature branch:
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. Commit your changes:
   ```bash
   git commit -m 'Add AmazingFeature'
   ```
4. Push to the branch:
   ```bash
   git push origin feature/AmazingFeature
   ```
5. Open a pull request.


---
