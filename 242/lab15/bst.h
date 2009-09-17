#ifndef BST_H_
#define BST_H_

typedef struct bstnode *bst;

extern bst bst_new();
extern bst bst_insert(bst b,char *s);
extern int bst_search(bst b,char *s);
extern void bst_inorder(bst b,void f(char *s));
extern void bst_preorder(bst b,void f(char *s));
extern bst bst_remove(bst b,char *s);
extern bst bst_delete(bst);

#endif
