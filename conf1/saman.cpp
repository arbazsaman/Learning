// jamai hamdard
// Binary Search Tree (BST) example
// Provides insert, search, inorder traversal and delete

#include <iostream>
using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
  Node(int k): key(k), left(nullptr), right(nullptr) {}
};

// Insert a key into BST, return new root
Node* insert(Node* root, int key) {
  if (!root) return new Node(key);
  if (key < root->key)
    root->left = insert(root->left, key);
  else if (key > root->key)
    root->right = insert(root->right, key);
  // if key == root->key, do nothing (no duplicates)
  return root;
}

// Search for a key in BST; return pointer or nullptr
Node* search(Node* root, int key) {
  if (!root || root->key == key) return root;
  if (key < root->key) return search(root->left, key);
  return search(root->right, key);
}

// Inorder traversal (sorted order)
void inorder(Node* root) {
  if (!root) return;
  inorder(root->left);
  cout << root->key << " ";
  inorder(root->right);
}

// Find minimum node in a subtree
Node* findMin(Node* root) {
  while (root && root->left) root = root->left;
  return root;
}

// Delete a key from BST, return new root
Node* deleteNode(Node* root, int key) {
  if (!root) return nullptr;
  if (key < root->key) root->left = deleteNode(root->left, key);
  else if (key > root->key) root->right = deleteNode(root->right, key);
  else {
    // node found
    if (!root->left) {
      Node* r = root->right;
      delete root;
      return r;
    } else if (!root->right) {
      Node* l = root->left;
      delete root;
      return l;
    } else {
      // two children: replace with inorder successor
      Node* succ = findMin(root->right);
      root->key = succ->key;
      root->right = deleteNode(root->right, succ->key);
    }
  }
  return root;
}

int main() {
  Node* root = nullptr;
  // sample data
  int vals[] = {50, 30, 20, 40, 70, 60, 80};
  for (int v : vals) root = insert(root, v);

  cout << "BST inorder traversal (should be sorted): ";
  inorder(root);
  cout << "\n";

  int keysToSearch[] = {40, 90};
  for (int k : keysToSearch) {
    cout << "Searching for " << k << ": ";
    Node* found = search(root, k);
    if (found) cout << "found\n";
    else cout << "not found\n";
  }

  cout << "\nDeleting 20 (leaf) and printing inorder: \n";
  root = deleteNode(root, 20);
  inorder(root);
  cout << "\n";

  cout << "\nDeleting 30 (node with one child) and printing inorder: \n";
  root = deleteNode(root, 30);
  inorder(root);
  cout << "\n";

  cout << "\nDeleting 50 (node with two children, root) and printing inorder: \n";
  root = deleteNode(root, 50);
  inorder(root);
  cout << "\n";

  return 0;
}