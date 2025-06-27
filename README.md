# 🧠 Template-Based Binary Search Tree (BST) in C++

This project provides a header-only, template-based implementation of a **Binary Search Tree (BST)** in C++. It supports all essential BST operations and is fully generic for any comparable type (`int`, `std::string`, etc.).

---

## 📦 Features

- `insert()` – insert a value into the tree
- `remove()` – delete a value from the tree
- `search()` – check if a value exists
- `getMin()` / `getMax()` – find minimum or maximum value
- `getPredecessor()` / `getSuccessor()` – find in-order predecessor or successor
- `getHeight()` – get tree height
- `traverse()` – return elements in Pre-order, In-order, or Post-order

---

## 🗂️ Files

- `bst.hpp` – main header file with declarations
- `bst.tpp` – implementation of all template methods

---

## ✅ Example Usage

```cpp
#include "bst.hpp"
#include <iostream>

int main() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    if (tree.search(10)) {
        std::cout << "Found 10\n";
    }

    std::cout << "Min: " << tree.getMin() << "\n";
    std::cout << "Max: " << tree.getMax() << "\n";
    std::cout << "Height: " << tree.getHeight() << "\n";

    auto inorder = tree.traverse(TraversalOrder::InOrder);
    std::cout << "In-order: ";
    for (int val : inorder)
        std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
