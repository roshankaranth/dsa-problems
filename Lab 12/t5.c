#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
    int d;
    int f;
} graph_node;

// Graph
typedef struct Graph
{
    int V;
    int E;
    int **adjacency_matrix;
    graph_node *vertices;
} Graph;

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
        G->vertices[i].d= 0;
        G->vertices[i].f = 0;
    }

    return G;
}

void add_edge_adj_matrix(Graph *G, int u, int v)
{
    // As in previous tasks
    G->adjacency_matrix[u][v] = 1;
}

/* 
    Recursive DFS with time stamps as given in CLRS
*/
int time = 0;

void recDFSVisit(Graph *G, int u)
{
    printf("%d ",u);
    G->vertices[u].c = GREY;
    G->vertices[u].d = time;
    time++;

    for(int i = 0 ; i < G->V ; i++){
        if(G->adjacency_matrix[u][i] == 1 && G->vertices[i].c == WHITE){
            G->vertices[i].c = GREY;
            recDFSVisit(G,i);
        }
    }
    G->vertices[u].c = BLACK;
    G->vertices[u].f = time;
}

void recDFS(Graph *G)
{
    // As in task 4
    for(int i = 0 ; i < G->V ; i++){
        if(G->vertices[i].c == WHITE){
            recDFSVisit(G,i);
        }
    }
}

Graph *get_transpose(Graph *G)
{
    // The transpose of a graph is a graph with the same vertices but with the direction of all edges reversed
    Graph *Gt = (Graph *)malloc(sizeof(Graph));
    Gt->V = G->V;
    Gt->E = G->E;
    // Allocate memory for the adjacency matrix (V x V int array)
    Gt->adjacency_matrix = (int**)malloc(sizeof(int*)*G->V);
    // Allocate memory for each row of the adjacency matrix
    for(int i = 0 ; i < G->V ; i++){
        Gt->adjacency_matrix[i] = (int*)malloc(sizeof(int)*G->V);
        memset(Gt->adjacency_matrix[i],0,G->V);
    }
    // Allocate memory for the vertices array (Array of |V| graph_nodes)
    Gt->vertices = (graph_node*)malloc(sizeof(graph_node)*G->V);
    // Initialize all the vertices to WHITE
    for(int i = 0 ; i < G->V ; i++){
        Gt->vertices[i].c = WHITE;
        Gt->vertices[i].data = i;
        Gt->vertices[i].d= 0;
        Gt->vertices[i].f = 0;
    }

    for(int u = 0 ; u < G->V ; u++){
        for(int v = 0 ; v < G->V ; v++){
            if(G->adjacency_matrix[u][v] == 1){
                Gt->adjacency_matrix[v][u] = 1;
            }
        }
    }

    return Gt;
}   

int strongly_connected_components(Graph *G)
{
    time = 0;
    printf("Computing strongly connected components\n");
    printf("Running DFS on the original graph\n");
    recDFS(G);
    printf("\n");
    graph_node descending_f_indices[G->V];
    for (int i = 0; i < G->V; i++)
    {
        descending_f_indices[i].data = i;
        descending_f_indices[i].f = G->vertices[i].f;
    }
    // Sort the vertices in descending order of f
    for (int i = 0; i < G->V; i++)
    {
        for (int j = i + 1; j < G->V; j++)
        {
            if (descending_f_indices[i].f < descending_f_indices[j].f)
            {
                graph_node temp = descending_f_indices[i];
                descending_f_indices[i] = descending_f_indices[j];
                descending_f_indices[j] = temp;
            }
        }
    }

    // Print descending_f_indices
    printf("Descending f indices: ");
    for (int i = 0; i < G->V; i++)
    {
        printf("%d ", descending_f_indices[i].data);
    }
    
    Graph *Gt = get_transpose(G);
    for (int i = 0; i < G->V; i++)
    {
        Gt->vertices[i].c = WHITE;
    }

    int num_scc = 0;
    time = 0;
    printf("\n");
    for (int i = 0; i < G->V; i++)
    {
        if (Gt->vertices[descending_f_indices[i].data].c == WHITE)
        {
            num_scc++;
            printf("SCC %d: ", num_scc);
            recDFSVisit(Gt, descending_f_indices[i].data);
            printf("\n");
        }
    }
    return num_scc;
}

Graph* undirected_graph(Graph* G){
    Graph *Gu = (Graph *)malloc(sizeof(Graph));
    Gu->V = G->V;
    Gu->E = G->E;
    // Allocate memory for the adjacency matrix (V x V int array)
    Gu->adjacency_matrix = (int**)malloc(sizeof(int*)*G->V);
    // Allocate memory for each row of the adjacency matrix
    for(int i = 0 ; i < G->V ; i++){
        Gu->adjacency_matrix[i] = (int*)malloc(sizeof(int)*G->V);
        memset(Gu->adjacency_matrix[i],0,G->V);
    }
    // Allocate memory for the vertices array (Array of |V| graph_nodes)
    Gu->vertices = (graph_node*)malloc(sizeof(graph_node)*G->V);
    // Initialize all the vertices to WHITE
    for(int i = 0 ; i < G->V ; i++){
        Gu->vertices[i].c = WHITE;
        Gu->vertices[i].data = i;
        Gu->vertices[i].d= 0;
        Gu->vertices[i].f = 0;
    }

    for(int u = 0 ; u < G->V ; u++){
        for(int v = 0 ; v < G->V ; v++){
            if(G->adjacency_matrix[u][v] == 1){
                Gu->adjacency_matrix[v][u] = 1;
                Gu->adjacency_matrix[u][v] = 1;
            }
        }
    }

    return Gu;
}

int weakly_connected_components(Graph *G) // Implement after testing strongly_connected_components
{
    // TODO: Implement this function
    Graph* Gu = undirected_graph(G);

    int num_wcc = 0;
    time = 0;
    printf("\n");
    for (int i = 0; i < G->V; i++)
    {
        if (Gu->vertices[i].c == WHITE)
        {
            num_wcc++;
            printf("SCC %d: ", num_wcc);
            recDFSVisit(Gu, i);
            printf("\n");
        }
    }
    return num_wcc;
}

int main()
{
    // You can change the file name to input1.txt or input2.txt to test your code for different graphs
    FILE *fp = fopen("input4.txt", "r");
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
    // Number of strongly connected components
    printf("Number of strongly connected components: %d\n", strongly_connected_components(G));

    //Number of weakly connected components.
    printf("Number of weakly connected components: %d\n", weakly_connected_components(G));
    return 0;
}