#include <stdlib.h>
#include "graph.h"
#include "mylib.h"
#include "queue.h"

typedef enum state_e {UNVISITED,VISITED_SELF,VISITED_DESCENDANTS} state_t;

struct vertex_array{
   int predecessor;
   int distance;
   state_t state;
   int finish;
};

struct graphrec{
   int size;/*size of the graph*/
   int **edges;/*2 dimensional array storing what vertices are
                * connected to other ones*/
   struct vertex_array *vertices;/*array of information about the vertices*/
 };
static int step;
 graph graph_new(int num_vertices){
    int i;
    graph result = emalloc(sizeof *result);
    result->vertices = emalloc(sizeof result->vertices[0] * num_vertices);
    result->size = num_vertices;
    result->edges = emalloc(sizeof result->edges[0] * num_vertices);
    for(i=0;i<num_vertices;i++){
       result->edges[i] = emalloc(sizeof result->edges[0][0] * num_vertices);
    }
    return result;
 }
 /*connect u to v*/
void graph_add_directed(graph g,int u,int v){
    g->edges[u][v] = 1;
 }
 /*connect u to v and v to u*/
void graph_add_undirected(graph g,int u,int v){
   g->edges[u][v] =1;
   g->edges[v][u] =1;
 
 }
 void graph_print(graph g){
    int i,j;
    printf("adjacency list:\n");
    for(i = 0; i < g->size;i++){
       printf("%d | ",i);
       for(j=0;j<g->size;j++){
          if(g->edges[i][j] == 1){
             printf("%d, ",j);
         }
      }
      printf("\n");
   }
   printf("\nvertex distance pred finish\n");
   for(i=0;i<g->size;i++){
      printf("%d\t%d\t%d\t%d\n",i,g->vertices[i].distance,
             g->vertices[i].predecessor,g->vertices[i].finish);
   }
}
static void visit(graph g,int v){
  int j;
  g->vertices[v].state = VISITED_SELF;
  step++;
  g->vertices[v].distance = step;
  for(j = 0; j < g->size; j++){
    if(g->edges[v][j] == 1 && g->vertices[j].state == UNVISITED){
      g->vertices[j].predecessor = v;
      visit(g,j);
    }
  }
  step++;
  g->vertices[v].state = VISITED_DESCENDANTS;
  g->vertices[v].finish = step;
}

void graph_dfs(graph g){
  int i,j;
  for(i = 0; i < g->size;i++){
      g->vertices[i].state = UNVISITED;
      g->vertices[i].predecessor = -1;
   }
  step =0;
   for(j = 0; j < g->size; j++){
         if(g->vertices[j].state == UNVISITED){
	   visit(g,j);
	 }
   }
}
void graph_bfs(graph g,int source){
   int i,j,u;
   queue q = queue_new(g->size);
   for(i = 0; i < g->size;i++){
      g->vertices[i].state = UNVISITED;
      g->vertices[i].distance = -1;
      g->vertices[i].predecessor = -1;
   }
   g->vertices[source].state = VISITED_SELF;
   g->vertices[source].distance = 0;
   
   queue_add(q,source);
   while(queue_empty(q) == 0){
      u = queue_remove(q);
      for(j = 0; j < g->size; j++){
         if(g->edges[u][j] == 1 && g->vertices[j].state == UNVISITED){
            g->vertices[j].state = VISITED_SELF;
            g->vertices[j].distance = 1 + g->vertices[u].distance;
            g->vertices[j].predecessor = u;
            queue_add(q,j);
         }
         g->vertices[u].state = VISITED_DESCENDANTS;
      }
   }
}

graph graph_delete(graph g){
   int i;
   for(i=0;i<g->size;i++){
      free(g->edges[i]);
   }
   free(g->edges);
   free(g->vertices);
   free(g);
   return g;
}
