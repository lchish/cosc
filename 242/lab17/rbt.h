#ifndef RBT_H_
#define RBT_H_

typedef struct rbtnode *rbt;

typedef enum colour_e {RED,BLACK} colour_t;

extern rbt rbt_new();
extern rbt rbt_insert(rbt b,char *s);
extern int rbt_search(rbt b,char *s);
extern void rbt_inorder(rbt b,void f(char *s,colour_t c));
extern void rbt_preorder(rbt b,void f(char *s,colour_t c));
extern rbt rbt_remove(rbt b,char *s);
extern rbt rbt_delete(rbt);

#endif
