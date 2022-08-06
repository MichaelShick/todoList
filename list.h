#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//max task size
#define task_len 128
//max status size;
#define status_len 64
typedef struct node
{
    char task_t[task_len];
    char status[status_len];
    struct node *next_t;
} list_s, *listPtr_s;
// call malloc and return the pointer. in case of memory allocation failure return NULL;
int list_size = 0;
listPtr_s init_list();

// all the add functions return 1 on success, 0 on failure;
// add a node to the beginning of the list
int add(listPtr_s* list_s, char msg_t[task_len], char status[status_len]);
// add a node to the end of the list
int append(listPtr_s* list_s, char msg_t[task_len], char status[status_len]);
// add a node to the specified index
int add_at(listPtr_s* list_s, char msg_t[task_len], char status[status_len], int i);

// remove a node from the beginning of the list
void remove_first(listPtr_s* list_s);
// remove a node from the end of the list
void remove_last(listPtr_s* list_s);
// remove a node from the specified index
int remove_at(listPtr_s* list_s, int i);

// check if the list contains the given node.
//  return the node position in the list or -1 if it isn't present;
int has_node(listPtr_s list, listPtr_s t);
// print at most N nodes from the list
void print_list(listPtr_s t,int n);

//get a specified node by index 
list_s get_node(listPtr_s *list,int i);

//replace parts of a specified task


// free all the nodes in the list
void free_list(listPtr_s t);
