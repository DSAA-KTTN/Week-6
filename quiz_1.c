#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


typedef struct {
    int * matrix;
    int sizemax;
} Graph;

Graph createGraph(int sizemax);
void addEdge(Graph graph, int v1, int v2);
int adjacent(Graph graph, int v1, int v2);
int getAdjacentVertices(Graph graph, int vertex, int* output); 
//return the number of adjacent vertices.
void dropGraph(Graph graph);

/* createGraph */
Graph createGraph(int sizemax){
    Graph a;
    int size=sizemax*sizemax;
    a.sizemax=sizemax;
    a.matrix=(int*)calloc(size,sizeof(int));
    return a;
}

/* addEdge */
void addEdge(Graph graph, int v1, int v2){

    graph.matrix[v1*graph.sizemax+v2]=1;
    graph.matrix[v2*graph.sizemax+v1]=1;
}

/* adjacent */
int adjacent(Graph graph, int v1, int v2){
    if(graph.matrix[v1*graph.sizemax+v2]==1)return 1;
    else return 0;
}

/* getAdjacentVertices */
int getAdjacentVertices(Graph graph, int vertex, int* output){
        int i,j,count=0;
        for(i=0;i<graph.sizemax;i++)
        if(graph.matrix[vertex*graph.sizemax+i]==1){
            output[count]=i;
            count++;
        }
    return count;

}

/* print */
void print(Graph graph){
    int i,j;
    int n=sqrt(graph.sizemax);
    for(i=0;i<graph.sizemax;i++){
        for(j=0;j<graph.sizemax;j++) printf("%d ",graph.matrix[i*graph.sizemax+j]);
        printf("\n");
    }
}

/* dropGraph */
void dropGraph(Graph graph){
    free(graph.matrix);
    graph.sizemax=0;
}

/* main */
int main(){
    int size=5,n,i;
    int output[50];
    Graph g=createGraph(size);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
     n = getAdjacentVertices (g, 1, output);
      if (n==0) printf("No adjacent vertices of node 1\n");
      else {
          printf("%d\n",n);
      printf("Adjacent vertices of node 1:");
      for (i=0; i<n; i++) printf("%d ", *(output+i));
      printf("\n");
     }
    print(g);
    dropGraph(g);
}