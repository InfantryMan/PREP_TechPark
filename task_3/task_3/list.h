#ifndef _LIST_H_
#define _LIST_H_
 
  #include <stdlib.h>
  #include <ctype.h>
  #include <stdbool.h>
  #include <errno.h>
  #include <stdio.h>
  
  typedef struct Node {
    int val;
    char stock;
    struct Node *next;
  } Node;

  char first_sign(FILE *fp);
  Node *node_search(Node *head, int val);
  Node *get_list_tail(Node *head);
  void node_insert(Node *head, Node *node);
  void node_delete(Node **head, Node *node); 
  void node_print(Node *head);
  Node *node_create(int data);
  void free_list(Node *head);

#endif
 
