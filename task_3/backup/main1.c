#include "list.h"

int main (int argc, char *argv[]) {

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Usage: %s can't open file\n", argv[1]);
    return EXIT_FAILURE;
  }
  
  int sign;
  Node *head = NULL;

  sign = first_sign(fp);
  if (sign == 1) {
    fprintf(stderr, "Error in fgetc\n");
    fclose(fp);
    return EXIT_FAILURE;
  }

  while (sign != EOF) {
    int num = -1;
    errno = 0;
    int n = fscanf(fp, "%d", &num);
    if (n != 1 || errno) {
      fprintf(stderr, "Error in fscanf.\n");
      free_list(head);
      fclose(fp);
      return EXIT_FAILURE;
    }
    Node *node, *node_found;
    switch (sign) {
      case '+': 
        if (head != NULL) {
          node = node_create(num);
        }
        else {
          head = node_create(num);
          break;
        }
        if (node == NULL || head == NULL) {
          fprintf(stderr, "No available memory for malloc\n");
          free_list(head);
          fclose(fp);
          return EXIT_FAILURE;
        }   
        node_found = node_search(head, num);
        if (node_found == NULL) 
          node_insert(head, node);
        else {
          free(node);
         // printf("Memory freed for %d\n", num);
        }
        break;
      case '-':
        if (head != NULL) {
          node_found = node_search(head, num);
          if (node_found != NULL)
            node_delete(&head,node_found);
        } 
        break;
      case '?':
        if (head != NULL) {
          node = node_create(num);
        }
        else {
          head = node_create(num);
          head->stock = 0;
          break;
        }
        if (node == NULL || head == NULL) {
          fprintf(stderr, "No available memory for malloc\n");
          free_list(head);
          fclose(fp);
          return EXIT_FAILURE;
        }
        node_found = node_search(head, num);
        if (node_found == NULL)
          node->stock = 0;
        else
          node->stock = 1;
        node_insert(head, node);
    }
    sign = first_sign(fp);
    if (sign == 1) {
      fprintf(stderr, "Error in fgetc\n");
      fclose(fp);
      free_list(head);
      return EXIT_FAILURE;
    }
  }
  if (head != NULL)
    node_print(head);
  free_list(head);
  fclose(fp);
}
