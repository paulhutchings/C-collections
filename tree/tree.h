#ifndef TREE_H
#define TREE_H

typedef struct treenode {
    void* data;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

typedef struct tree {
    TreeNode* root;
    int size;
    int (*isEqual)(void* a, void* b); 
} Tree;

Tree* newTree(void* type);
void insert(Tree* t, void* item);

#endif