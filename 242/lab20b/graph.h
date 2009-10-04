#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct graphrec *graph;
extern graph graph_new(int num_vertices);
extern graph graph_delete(graph g);
extern void graph_add_directed(graph g,int u,int v);
extern void graph_add_undirected(graph g,int u,int v);
extern void graph_dfs(graph g);
extern void graph_bfs(graph g,int source);
extern void graph_print(graph g);

#endif
