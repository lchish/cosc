/**
 * @file tree.c
 * @author Leslie Chisholm
 * @date September 2009
 * 
 * This file implements a binary search tree ADT using either
 * a red-black tree or binary search tree
 */

#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "mylib.h"

#define IS_BLACK(x) ((NULL == (x) || BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x) && RED == (x)->colour))

/**
 *Global variable defining the type of tree to use.
 */
static tree_t tree_type;
/**
 * Struct hold the trees key,left and right subtree and colour(
 * which is only used for RBTs).
 */
struct treenode
{
  char *key;
  colour_t colour;
  tree left;
  tree right;
};

/**
 * Creates a new tree and sets what type of tree we are going to use.
 * @param tree_typ type of tree to create either RBT or BST.
 * @return new search tree.
 */
tree tree_new(tree_t tree_typ)
{
  tree_type = tree_typ;
  return NULL;
}
/**
 * Used by red black trees to rotate the tree to the right.
 * @param t tree to rotate.
 * @return rotated tree.
 */
static tree right_rotate(tree t)
{
  tree tmp = t;
  t = t->left;
  tmp->left = t->right;
  t->right = tmp;
  return t;
}
/**
 * Used by red black trees to rotate the tree to the left.
 * @param t tree to rotate.
 * @return rotated tree.
 */
static tree left_rotate(tree t)
{
  tree tmp = t;
  t = t->right;
  tmp->right = t->left;
  t->left = tmp;
  return t;
}

/**
 * Balances red black trees.
 * @param t tree to balance.
 * @return balanced tree.
 */
static tree tree_fix(tree t)
{
  if(IS_RED(t->left) && IS_RED(t->left->left)){
    if(IS_RED(t->right)){
      /*colour root red and children a,b black*/
      t->colour = RED;
      t->left->colour = BLACK;
      t->right->colour = BLACK;
    }else if(IS_BLACK(t->right)){
      /*right rotate root , colour new root (a) black,
       * and new child(old root) red*/
      t = right_rotate(t);
      t->colour = BLACK;
      t->right->colour = RED;/*old root*/
    }
  }else if(IS_RED(t->left) && IS_RED(t->left->right)){
    if(IS_RED(t->right)){
      /*colour root red and children a,b black*/
      t->colour = RED;
      t->left->colour = BLACK;
      t->right->colour = BLACK;
    }
    else if(IS_BLACK(t->right)){
      /* Left rotate left child (a), right rotate root (r),
       * colour new root (d) black and new child (R) red */
      t->left = left_rotate(t->left);
      t = right_rotate(t);
      t->colour = BLACK;
      t->right->colour = RED;/* old root */
    }
  }else if(IS_RED(t->right) && IS_RED(t->right->left)){
    if(IS_RED(t->left)){
      /* Colour root (R) red and children (a,b) black*/
      t->colour = RED;
      t->left->colour = BLACK;
      t->right->colour = BLACK;
    }else if(IS_BLACK(t->left)){
      /* Right rotate right child(b),left rotate root(r),
       * colour new root (e) black and new child (r) red */
      t->right = right_rotate(t->right);
      t = left_rotate(t);
      t->colour = BLACK;
      t->left->colour = RED;/* old root */
    }
  }else if(IS_RED(t->right) && IS_RED(t->right->right)){
    if(IS_RED(t->left)){
      /* Colour root (R) red and children (A,B) black */
      t->colour = RED;
      t->left->colour = BLACK;
      t->right->colour = BLACK;
    }
    else if(IS_BLACK(t->left)){
      /* Left rotate root R, colour new root b black and new child R red */
      t = left_rotate(t);
      t->colour = BLACK;
      t->left->colour = RED;/*old root*/
    }
  }
  return t;
}

/**
 * Searches the tree for a specific key.
 * @param t tree to search.
 * @param s key to search for.
 * @return 1 if found otherwise 0.
 */
int tree_search(tree t, char *s)
{
  if(t == NULL){
    return 0;/*not found*/
  }else if(strcmp(t->key,s) == 0){
    return 1;/*found*/
  }else if(strcmp(t->key,s) > 0){/* t->key > s */
    return tree_search(t->left,s);
  }else{/* t->key < s*/
    return tree_search(t->right,s);
  }
}

/**
 * Inserts a new key into the tree.
 * @param t tree to put key into.
 * @param s key to insert.
 * @return tree with key inserted.
 */
tree tree_insert(tree t,char *s)
{
  if(t == NULL){/*empty tree*/
    t = emalloc(sizeof *t);
    t->key = emalloc(strlen(s) * sizeof s[0] + 1);
    t->colour = RED;
    strcpy(t->key,s);
  }else if(strcmp(t->key,s)==0){/*do nothing*/
  }else if(strcmp(t->key,s) < 0){/*s > b-key */
    t->right = tree_insert(t->right,s);
  }
  else if(strcmp(t->key,s) > 0){/*s < b-key*/
    t->left = tree_insert(t->left,s);
  }
  if(tree_type == RBT){
    t = tree_fix(t);
  }
  return t;
}

/**
 * Prints the keys in the tree inorder.
 * @param t tree to print.
 * @param f(char *s) printing function to use.
 */
void tree_inorder(tree t, void f(char *s))
{
  if(t == NULL){
    return;
  }else{
    tree_inorder(t->left,f);
    f(t->key);
    tree_inorder(t->right,f);
  }
}

/**
 * Prints the keys in the tree out preorder.
 * @param t tree to print.
 * @param f(char *s) printing function to use.
 */
void tree_preorder(tree t, void f(char *s))
{
  if(t == NULL){
    return;
  }else{
    f(t->key);
    tree_preorder(t->left,f);
    tree_preorder(t->right,f);
  }
}

/**
 Calculates the greatest depth of the tree.
 @param t tree to find the depth of.
 @return maximum depth of the tree.
 */
int tree_depth(tree t)
{
  if(t->left != NULL && t->right != NULL){
    return tree_depth(t->left) > tree_depth(t->right) 
      ? tree_depth(t->left)+1 : tree_depth(t->right)+1;
   }else if(t->left != NULL){
    return tree_depth(t->left)+1;
  }else if(t->right != NULL){
    return tree_depth(t->right)+1;
  }else{
    return 0;
  }
}

/**
 * Frees all dynamically allocated memory to the tree.
 * @param t tree to delete.
 * @return deleted tree.
 */
tree tree_destroy(tree t)
{
  if(t == NULL){
    return t;/*aka return null*/
  }else{
    tree_destroy(t->left);
    tree_destroy(t->right);
    free(t->key);
    free(t);
    return t;
  }
}

/* provided code */

/**
 * Traverses the tree writing a DOT description about connections, and
 * possibly colours, to the given output stream.
 *
 * @param t the tree to output a DOT description of.
 * @param out the stream to write the DOT output to.
 */
static void tree_output_dot_aux(tree t, FILE *out) {
   if(t->key != NULL) {
      fprintf(out, "\"%s\"[label=\"{<f0>%s|{<f1>|<f2>}}\"color=%s];\n", t->key,
              t->key, (RBT == tree_type && RED == t->colour) ? "red":"black");
   }
   if(t->left != NULL) {
      tree_output_dot_aux(t->left, out);
      fprintf(out, "\"%s\":f1 -> \"%s\":f0;\n", t->key, t->left->key);
   }
   if(t->right != NULL) {
      tree_output_dot_aux(t->right, out);
      fprintf(out, "\"%s\":f2 -> \"%s\":f0;\n", t->key, t->right->key);
   }
}

/**
 * Output a DOT description of this tree to the given output stream.
 * DOT is a plain text graph description language (see www.graphviz.org).
 * You can create a viewable graph with the command
 *
 *    dot -Tsvg < graphfile > graphfile.svg
 *
 * You can also use png, ps, jpg, pdf... instead of svg (because the
 * version of dot on CentOS can't output pdfs we convert it to a fig
 * first).
 *
 * @param t the tree to output the DOT description of.
 * @param out the stream to write the DOT description to.
 */
void tree_output_dot(tree t, FILE *out) {
   fprintf(out, "digraph tree {\nnode [shape = Mrecord, penwidth = 2];\n");
   tree_output_dot_aux(t, out);
   fprintf(out, "}\n");
}
