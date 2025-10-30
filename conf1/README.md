# BST demo — `conf1/saman.cpp`

This repository contains a small C++ Binary Search Tree (BST) example in `conf1/saman.cpp`.

## What this program does

- Implements a simple BST with:
  - insert
  - search
  - inorder traversal (prints keys in sorted order)
  - delete (handles leaf, single-child, and two-children cases)
- `main()` inserts a small set of sample values, demonstrates searching, and deletes a few nodes while printing the tree (inorder) after each change.

## Files

- `conf1/saman.cpp` — BST implementation and demo program

## Build and run (Windows PowerShell)

Open PowerShell and run:

```powershell
# Compile (requires g++ in PATH)
g++ -std=c++17 "d:/coding/conf1/saman.cpp" -o "d:/coding/conf1/saman.exe"

# Run the compiled executable
& "d:/coding/conf1/saman.exe"
```

If compilation succeeds, the program prints the initial inorder traversal, search results, and the inorder traversal after each deletion.

## Captured program output

This README documents the actual output captured when the program was compiled and run during development:

```
BST inorder traversal (should be sorted): 20 30 40 50 60 70 80 
Searching for 40: found
Searching for 90: not found

Deleting 20 (leaf) and printing inorder: 
30 40 50 60 70 80 

Deleting 30 (node with one child) and printing inorder: 
40 50 60 70 80

Deleting 50 (node with two children, root) and printing inorder:
40 60 70 80
```

(Whitespace/newlines above reflect the program's output.)

## Notes & next steps

- The program currently uses a fixed sample array in `main()`. You can extend it to read commands (insert/search/delete) from stdin or from command-line arguments for interactive use.
- For larger projects, consider splitting into `bst.h`/`bst.cpp` and adding unit tests.
- The program does not rebalance the tree; for balanced behavior consider using AVL or Red-Black Tree implementations.

If you want, I can:
- Make the program interactive (accept commands at runtime).
- Split the implementation into header/source files and add a small test harness.
- Add detailed function-level comments.
