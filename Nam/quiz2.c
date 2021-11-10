#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"jrb.h"
typedef JRB Graph;
Graph createGraph();
void addEdge(Graph graph, int v1, int v2);
int getAdjacentVertices (Graph graph, int v, int*
output);
void dropGraph(Graph graph);

Graph createGraph(){
    return make_jrb();
}
void addEdge(Graph graph, int v1, int v2){
    JRB node=jrb_find_int(graph,v1);
    JRB node2=jrb_find_int(graph,v2);
    JRB tree;
    if(node==NULL){
        tree = make_jrb();
        jrb_insert_int(graph, v1, new_jval_v(tree));
        jrb_insert_int(tree, v2, new_jval_i(1));
    }else{
        tree = (JRB) jval_v(node->val);
        jrb_insert_int(tree, v2, new_jval_i(1));
    }
    if(node2==NULL){
        tree = make_jrb();
        jrb_insert_int(graph, v2, new_jval_v(tree));
        jrb_insert_int(tree, v1, new_jval_i(1));
    }else{
        tree = (JRB) jval_v(node2->val);
        jrb_insert_int(tree, v1, new_jval_i(1));
    }
}
int getAdjacentVertices (Graph graph, int v, int*
output){
    Graph node, tree;
    node = jrb_find_int(graph, v);
    tree = (JRB) jval_v(node->val);
    int total = 0;
    jrb_traverse(node, tree){
    output[total++] = jval_i(node->key);
    }
    return total;
}
void dropGraph(Graph graph){
    JRB node;
    jrb_traverse(node, graph){
    jrb_free_tree( jval_v(node->val) );
    }
}
int main(){
    int size=5,n,i;
    int output[50];
    int m;
    Graph g=createGraph();
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    m=1;
     n = getAdjacentVertices (g, m, output);
      if (n==0) printf("No adjacent vertices of node 1\n");
      else {
          printf("%d\n",n);
      printf("Adjacent vertices of node %d:",m);
      for (i=0; i<n; i++) printf("%d ", output[i]);
      printf("\n");
     }
    dropGraph(g);   
}