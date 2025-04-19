/*
The major steps of the algorithm are as follows:
Start off with all nodes being white. Initialize an empty stack.
Mark the source s as grey and enstack it
While the stack is not empty:
    Destack a node u
    For each white node v adjacent to u:
        Mark v as grey
        Enstack v
    Mark u as black
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// stack

int timer = 0;

typedef struct linked_list_node
{
    int data;
    struct linked_list_node *next;
} ll_node;

typedef struct stack
{
    ll_node* top;
} stack;

stack *get_stack()
{
    stack *Q = (stack *)malloc(sizeof(stack));
    Q->top = NULL;
    return Q;
}

void push(stack *Q, int data)
{
    ll_node *temp = (ll_node *)malloc(sizeof(ll_node));
    temp->data = data;
    temp->next = NULL;
    
    temp->next = Q->top;
    Q->top = temp;
}

int is_empty(stack *Q)
{
    return Q->top == NULL;
}

int pop(stack *Q)
{
    if (is_empty(Q))
    {
        printf("stack is empty\n");
        return -1;
    }
    ll_node *temp = Q->top;
    int data = temp->data;
    Q->top = Q->top->next;
    free(temp);
    return data;
}

typedef enum color
{
    WHITE,
    GREY,
    BLACK
} color;

// Graph Node
typedef struct graph_node
{
    int data;
    color c;
    int predecessor;
    int discovery_time;
    int finsh_time;

} graph_node;

// Graph
typedef struct Graph
{
    int V;
    int E;
    int **adjacency_matrix;
    graph_node *vertices;
} Graph;

// Modify the get_graph function from Task 1 to now only use the adjacency matrix and not the adjacency list
// Allocate memory for the vertices array (Array of |V| graph_nodes)
// Initialize all the vertices to WHITE
// Initialize data to the index of the vertex

Graph *get_graph(int V, int E)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->V = V;
    G->E = E;
    // Allocate memory for the adjacency matrix (V x V int array)
    G->adjacency_matrix = (int**)malloc(sizeof(int*)*V);
    // Allocate memory for each row of the adjacency matrix
    for(int i = 0 ; i < V ; i++){
        G->adjacency_matrix[i] = (int*)malloc(sizeof(int)*V);
        memset(G->adjacency_matrix[i],0,V);
    }
    // Allocate memory for the vertices array (Array of |V| graph_nodes)
    G->vertices = (graph_node*)malloc(sizeof(graph_node)*V);
    // Initialize all the vertices to WHITE
    for(int i = 0 ; i < V ; i++){
        G->vertices[i].c = WHITE;
        G->vertices[i].data = i;
        G->vertices[i].predecessor = -1;
        G->vertices[i].discovery_time = 0;
        G->vertices[i].finsh_time = 0;
    }

    return G;
}

// BFS
void dfs(Graph *G, int s)
{
    // Initialize the stack
    stack* Q = get_stack();
    // Mark the source s as grey and enstack it
    G->vertices[s].c = GREY;
    push(Q,s);
    // While the stack is not empty:
    while (!is_empty(Q))
    {
        // Destack a node u
        int u = pop(Q);
        // Print the data of the destackd node that would now be explored
        printf("%d ",u);
        // For each white node v adjacent to u:
        for (int v = 0; v < G->V; v++)
        {
            if (G->adjacency_matrix[u][v] == 1 && G->vertices[v].c == WHITE)
            {
                // Mark v as grey
                G->vertices[v].c = GREY;
                G->vertices[v].predecessor = u;
                // Enstack v
                push(Q,v);

            }
        }
        // Mark u as black
        G->vertices[u].c = BLACK;

    }
}

void recDFSVisit(Graph* G, int u){
    printf("%d ",u);
    G->vertices[u].discovery_time = timer;
    timer++;

    for(int i = 0 ; i < G->V ; i++){
        if(G->adjacency_matrix[u][i] == 1 && G->vertices[i].c == WHITE){
            G->vertices[i].predecessor = u;
            G->vertices[i].c = GREY;
            recDFSVisit(G,i);
        }
    }
    G->vertices[u].c = BLACK;
    G->vertices[u].finsh_time = timer;
}

void recDFS(Graph *G){
    for(int i = 0 ; i < G->V ; i++){
        if(G->vertices[i].c == WHITE){
            G->vertices[i].c = GREY;
            recDFSVisit(G,i);
        }
    }
}

void add_edge_adj_matrix(Graph *G, int u, int v)
{
    G->adjacency_matrix[u][v] = 1;
}

void find_target(Graph* G, int s, int t){
    dfs(G,s);
    int node = t;
    while(node != -1){
        printf("%d <-", node);
        node = G->vertices[node].predecessor;
    }
}

int main()
{
    // You can change the file name to input1.txt or input2.txt to test your code for different graphs
    FILE *fp = fopen("input3.txt", "r");
    int V, E;
    fscanf(fp, "%d", &V);
    fscanf(fp, "%d", &E);
    struct Graph *G = get_graph(V, E);
    for (int i = 0; i < E; i++) 
    {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);
        add_edge_adj_matrix(G, u, v);
    }
    fclose(fp);
    //dfs(G, 0);
    //find_target(G,0,6);
    printf("\n");
    recDFS(G);
    return 0;
}