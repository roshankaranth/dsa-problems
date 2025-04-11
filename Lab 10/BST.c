#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int height;
    struct node *left;
    struct node *right;
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
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void insert(BST *bst, int value)
{
    Node *node = new_node(value);
    if (bst->root == NULL) 
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (value < current->value) 
        {
            if (current->left == NULL) 
            {
                current->left = node;
                return;
            }
            current = current->left;
        } 
        else 
        {
            if (current->right == NULL) 
            {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value) 
        {
            return 1;
        } 
        else if (key < current->value) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return 0;
}

int find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    Node *current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(BST *bst, Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        // Node is a leaf
        Node* current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    
    if (node->left == NULL)
    {
        // Node only has right child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if (node->right == NULL)
    {
        // Node only has left child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    // Node has both children
    Node *temp = successor(node);
    node->value = temp->value;
    delete(bst, temp);
    return;
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int calculate_height(Node* node){
    int lheight = (node->left != NULL) ? node->left->height: 0;
    int rheight = (node->right != NULL) ? node->right->height:0;
    
    return 1 + max(lheight,rheight);
}

Node* rotate_left(Node* node){
    Node* x = node->right;
    node->right = x->left;
    x->left = node;

    node->height = calculate_height(node);
    x->height = calculate_height(x);

    return x;
}

Node* rotate_right(Node* node){
    Node* x = node->left;
    node->left = x->right;
    x->right = node;

    node->height = calculate_height(node);
    x->height = calculate_height(x);

    return x;
}

int is_height_balanced(Node* node){
    if(node == NULL) return 0;

    int lheight = is_height_balanced(node->left);
    int rheight = is_height_balanced(node->right);

    if(lheight == -1 || rheight == -1) return -1;
    else if(lheight - rheight > 1 || rheight - lheight > 1) return -1;
    else return 1 + max(lheight,rheight);
}

int is_avl(BST* bst){
    return is_height_balanced(bst->root);
}

int balance_factor(Node* node){
    int lheight = (node->left != NULL) ? node->left->height: 0;
    int rheight = (node->right != NULL) ? node->right->height:0;
    
    return lheight - rheight;
}

Node* insertAVL(Node* node, int val){
    if(node == NULL) node = new_node(val);
    else if(node->value > val){
        node->left = insertAVL(node->left, val);
        node->left->height = calculate_height(node->left);
        
    }else{
        node->right = insertAVL(node->right, val);
        node->right->height = calculate_height(node->right);
    }

    int balance = balance_factor(node);
    balance = (balance>1 || balance <-1) ? -1 : 0;

    if(balance == -1){
        if(node->value > val){
            if(node->left->value > val){
                node = rotate_right(node);
            }else{
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            }
        }else{
            if(node->right->value < val){
                node = rotate_left(node);
            }else{
                node->right = rotate_right(node->right);
                node = rotate_left(node);
            }  
        }
    }

    return node;
}

void traverse_bfs(Node *node){
    if (node == NULL){
        return;
    }

    Node *queue[100];
    int front = 0;
    int back = 0;
    queue[back++] = node;
    printf("BFS:\n");
    while (front != back){
        int size = back;
        for(int i = front ; i < size; i++){
            Node *current = queue[front++];
            printf("%d ", current->value);
            if (current->left != NULL){
                queue[back++] = current->left;
            }
            if (current->right != NULL){
                queue[back++] = current->right;
            }
        }
        printf("\n");
    }
}

// Driver program to test the above functions (feel free to play around with this)
int main()
{
    BST *bst = new_bst();
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 4);
    insert(bst, 5);
    insert(bst, 6);
    insert(bst, 7);
    insert(bst, 8);
    traverse_in_order(bst->root);
    printf("\n");
    printf("Max = %d\n", find_max(bst));
    printf("Min = %d\n", find_min(bst));
    printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    printf("Successor of root = %d\n", successor(bst->root)->value);
    delete(bst, bst->root->left);
    traverse_in_order(bst->root);
    printf("\n");
    delete(bst, bst->root->right);
    traverse_in_order(bst->root);
    printf("\n");
    delete(bst, bst->root);
    traverse_in_order(bst->root);
    printf("\n");

    //AVL tree
    int arr[] = {1,2,3,4,5,6,7,8,9};
    BST* avl = new_bst();
    for(int i = 0 ; i < sizeof(arr)/sizeof(int) ; i++){
        avl->root = insertAVL(avl->root,arr[i]);
    }

    printf("%d\n", is_avl(avl));
    traverse_bfs(avl->root);
    return 0;
}