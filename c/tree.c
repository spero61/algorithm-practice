#include <stdio.h>
#include <stdlib.h>

// define a node with two pointers
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

void free_tree(node *root);
void print_tree(node *root);

int main(int argc, char *argv[])
{
    // initialize tree with no nodes
    node *root = NULL;

    // allocate memory for a node n
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    // set a value for node n
    n -> number = 4;
    // set pointers to children nodes to null
    n -> left = NULL;
    n -> right = NULL;
    // set tree to point to this node
    root = n;


    // repeat the process
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 1;
    }
    n -> number = 2;
    n -> left = NULL;
    n -> right = NULL;
    root -> left = n;


    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 1;
    }
    n -> number = 1;
    n -> left = NULL;
    n -> right = NULL;
    root -> left -> left = n;


    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 1;
    }
    n -> number = 3;
    n -> left = NULL;
    n -> right = NULL;
    root -> left -> right = n;


    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 1;
    }
    n -> number = 6;
    n -> left = NULL;
    n -> right = NULL;
    root -> right = n;


    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 1;
    }
    n -> number = 5;
    n -> left = NULL;
    n -> right = NULL;
    root -> right -> left = n;


    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 1;
    }
    n -> number = 7;
    n -> left = NULL;
    n -> right = NULL;
    root -> right -> right = n;


    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 1;
    }
    n -> number = 0;
    n -> left = NULL;
    n -> right = NULL;
    root -> left -> left -> left = n;

    print_tree(root);
    free_tree(root);

    return 0;
}


// recursively free both children(left, right) first
void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root -> left);
    free_tree(root -> right);
    free(root);
}


// print function starts at the root node then recursively print the entire tree
// recursively prints left subtree => root node’s value => right subtree
void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root -> left);
    printf("%i\n", root -> number);
    print_tree(root -> right);
}
