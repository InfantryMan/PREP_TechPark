#include "list.h"

Node *node_search(Node *head, int val) {
  Node *cur_node = head;
  while (cur_node->val != val){
    if (cur_node->next == NULL)
      return NULL;
    cur_node = cur_node->next;
  } 
  return cur_node;
}

Node *get_list_tail(Node *head) {
  Node *cur_node = head;
  while (cur_node->next) 
    cur_node = cur_node->next;
  return cur_node;
}

void node_insert(Node *head, Node *node) {
  Node *tail = get_list_tail(head);
  tail->next = node;
}

char node_delete(Node **head, Node *node) { 
  if (*head == node && (*head)->next == NULL) {
   // printf("Memory freed in node_delete in head for %d\n", node->val);
    free(*head);
    *head = NULL;
    return 0;
  }
  if (*head == node) {
    Node* new_head = *head;
    *head = (*head)->next;
    //printf("Memory freed in node_delete in head for %d\n", node->val);
    free(new_head);
    return 1;
  }
  if (node->next == NULL) {
    Node *cur_node = *head;
    while (cur_node->next->next != NULL)
      cur_node = cur_node->next;
    cur_node->next = NULL;
   // printf("Memory freed in node_delete in tail for %d\n", node->val);
    free(node);
    return 0;
  }
  //printf("Memory freed in node_delete inside for %d\n", node->val);
  Node *node_next = node->next;
  node->val = node_next->val;
  node->stock = node_next->stock;
  node->next = node_next->next;
  free(node_next);
  return 1;
}

void node_print(Node *head) {
  Node *cur_node = head;
  while (cur_node != NULL) {
    printf("%d ", cur_node->val);
    if (cur_node->stock == 1)
      printf("Yes");
    else if (cur_node->stock == 0)
      printf("No");
    printf("\n");
    cur_node = cur_node->next;
  }
}

char first_sign(FILE *fp) {
  int c;
  do {
    c = fgetc(fp);
    //while (c != '+' && c != '-' && c != '?' && c != EOF);
    if (ferror(fp))
      return 1;
  } while (isspace(c));
  return c;
}

Node *node_create(int data) {
  Node *r = malloc(sizeof(*r)); 
  //printf ("Memory allocated for %d\n", data);
  if (r == NULL) 
    return NULL;
  r->val = data;
  r->next = NULL;
  r->stock = -1;
  return r;
}

void free_list(Node *head) {
  Node *cur_node = head;
  while (cur_node != NULL) {
    cur_node = cur_node->next;
    //printf("Memory freed in free_list for %d\n", head->val);
    free(head);
    head = cur_node;
  }
}

