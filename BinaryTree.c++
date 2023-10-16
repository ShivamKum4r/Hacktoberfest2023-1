#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
  Node* root;

  BinaryTree() {
    root = nullptr;
  }

  void insert(int data) {
    Node* newNode = new Node(data);
    insert(root, newNode);
  }

  void insert(Node* node, Node* newNode) {
    if (node == nullptr) {
      root = newNode;
      return;
    }

    if (newNode->data < node->data) {
      insert(node->left, newNode);
    } else {
      insert(node->right, newNode);
    }
  }

  void inorder(Node* node) {
    if (node == nullptr) {
      return;
    }

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }

  void inorder() {
    inorder(root);
  }
};

int main() {
  BinaryTree tree;

  tree.insert(10);
  tree.insert(5);
  tree.insert(15);
  tree.insert(3);
  tree.insert(7);
  tree.insert(17);

  cout << "Inorder traversal: ";
  tree.inorder();

  cout << endl;

  return 0;
}
