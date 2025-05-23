#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
    int height;
} Node;

typedef struct bst {
    Node *root;
} BST;

BST *new_bst() 
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}
void traverse_bfs(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    Node *queue[100];
    int front = 0;
    int back = 0;
    queue[back++] = node;
    while (front != back)
    {
        Node *current = queue[front++];
        printf("%d ", current->value);
        if (current->left != NULL)
        {
            queue[back++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[back++] = current->right;
        }
    }
}
/*
    We saw the traverse_bfs() function in Task 1. This function is called breadth-first because it prints all the nodes of each level before proceeding to the next. An another way of traversing the tree is called depth-first traversal. In this, one path upto the leafis completely traversed before you proceed along another path. All the walks we saw last week - in-order, pre-order and post-order, are versions of DFS. 

    You had implemented these walks last week. Now write a program that constructs a binary tree given the in-order and post-order traversals.

    Assume you are given three lines of input. 
    The first line contains the total number of nodes
    The second line contains the in-order walk
    The third line contains the post-order walk

*/

Node* Helper(int *inorder, int* post_order, int n, int i, int c, int d){
    if(c>d) return NULL;
    if(c==d) return new_node(inorder[c]);

    int parent = post_order[i];
    int j = 0;
    for(; j < d; j++){
        if(parent == inorder[j]) break;
    }

    Node* pnode = new_node(parent);
    pnode->right = Helper(inorder,post_order, n, i-1, j+1,d);
    pnode->left = Helper(inorder,post_order,n,i-(d-j)-1,c,j-1);
    return pnode;

}

Node *build_tree(int *in_order, int *post_order, int n) 
{
    return Helper(in_order, post_order, n, n-1, 0, n-1);
}

int main() 
{
    int n;
    scanf("%d", &n);
    int in_order[n];
    int post_order[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &in_order[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &post_order[i]);
    }
    BST *bst = new_bst();
    bst->root = build_tree(in_order, post_order, n);
    traverse_bfs(bst->root);
    printf("\n");
    return 0;
}