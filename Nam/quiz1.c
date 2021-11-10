#include<stdio.h>
#include<stdlib.h>
struct G{
    int *matrix;
    int sizemax;
};
typedef struct G Graph;

Graph createGraph(int sizemax);
void addEdge(Graph *graph, int v1, int v2);
int adjacent(Graph graph, int v1, int v2);
int getAdjacentVertices(Graph graph, int vertex, int* output); 
//return the number of adjacent vertices.
void dropGraph(Graph *graph);

Graph createGraph(int sizemax){
    Graph G;
    G.sizemax=sizemax;
    G.matrix=(int*)malloc((sizemax*sizemax)*sizeof(int));
    int i;
    for(i=0;i<sizemax*sizemax;i++){
        G.matrix[i]=0;
    }
    return G;
}

void addEdge(Graph *graph, int v1, int v2){
    int n=graph->sizemax;
    graph->matrix[v1*n+v2]=1;
    graph->matrix[v2*n+v1]=1;
}

int adjacent(Graph graph,int v1, int v2){
    int n=graph.sizemax;
    if(graph.matrix[v1*n+v2]==1)
    if(graph.matrix[v2*n+v1]==1)
    return 1;
    return 0;
}

int getAdjacentVertices(Graph graph, int vertex, int* output){
    int n=graph.sizemax;
    int m=0;
    int check=0;
    if(graph.matrix[vertex]!=1) return 0;
    for(int i=0;i<n*n;i++){
        if(adjacent(graph,vertex,i)==1){
        output[m]=i;
        m++;
        check=1;
        }
    }
    if(check==0) return 0;
    else return 1;
}

void dropGraph(Graph *graph){
    free(graph->matrix);
    graph->sizemax=0;
}

void printGraph(Graph graph){
    int n=graph.sizemax;
    for(int i=0;i<n*n;i++){
        if(i%n==0) printf("\n");
        printf("%-5d",graph.matrix[i]);
    }
    printf("\n");
}

int main(){
    int i, n, output[100];
    Graph g = createGraph(10);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    printGraph(g);
    n = getAdjacentVertices (g, 1, output);
    if (n==0) printf("No adjacent vertices of node 1\n");
    else {   printf("Adjacent vertices of node 1:");
    for (i=0; i<n; i++) printf("%-5d", output[i]);}
    dropGraph(&g);
    return 0;
}