#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "jrb.h"
#include "jval.h"
 #include "jrb.c"
 #include "jval.c"

typedef JRB Graph;

Graph createGraph();
void addEdge(Graph graph, int v1, int v2);
int adjacent(Graph graph, int v1, int v2);
int getAdjacentVertices(Graph graph, int v, int* output);
void dropGraph(Graph graph) ;

/* createGraph */
Graph createGraph(){
    return make_jrb();
}

int adjacent(Graph graph, int v1, int v2){
  JRB node, tree;
  node = jrb_find_int(graph, v1);
  if(node == NULL) return 0;
  tree = (JRB)jval_v(node->val);
  if(jrb_find_int(tree,v2) == NULL) return 0;
  else return 1;
}

void addEdge(Graph graph, int v1, int v2){
  JRB node, tree;
  if(adjacent(graph,v1,v2)==0){
    node = jrb_find_int(graph,v1);
    if(node == NULL){
      tree = make_jrb();
      jrb_insert_int(graph,v1, new_jval_v(tree));
    }else{
    tree = (JRB)jval_v(node -> val);
    }
    jrb_insert_int(tree, v2,new_jval_i(1));
  }

  if(adjacent(graph,v2,v1)==0){
    node = jrb_find_int(graph,v2);
    if(node == NULL){
      tree = make_jrb();
      jrb_insert_int(graph,v2, new_jval_v(tree));
    }else{
      tree = (JRB)jval_v(node ->val);
    }
    jrb_insert_int(tree,v1,new_jval_i(1));
  }
}

/* getAdjacentVertices */
int getAdjacentVertices(Graph g, int v, int* output){
    int total;
    Graph node,tree;
    node = jrb_find_int(g, v);
    tree = (JRB) jval_v(node->val);
    total = 0;
    jrb_traverse(node, tree) output[total++] = jval_i(node->key);
    return total;
}


/* dropGraph */
void dropGraph(Graph graph){
    Graph node;
    jrb_traverse(node, graph)
    jrb_free_tree( jval_v(node->val) );
}

/* main */
int main(){
    int size=5,n,i;
    int output[50];


    Graph g=createGraph();

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
    dropGraph(g);   
}
