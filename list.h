#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// max task size
#define STR_LEN 128


// the linked list struct, containing two string fields
typedef struct node
{
    char task_t[STR_LEN];
    char status[STR_LEN];
    struct node *next_t;
} list_s, *listPtr_s;
// call malloc and return the pointer. in case of memory allocation failure return NULL;
listPtr_s init_list();

// for all the add functions:
    // listPtr_s* list_s    - a pointer to the list to add the node to
    // char msg_t[]         - plain text message to put in the list
    // char status[]        - plain text message to put in the list
    // return 1 on success, 0 on failure;

// add a node to the beginning of the list
int add(listPtr_s *list_s, char msg_t[STR_LEN], char status[STR_LEN]);

// add a node to the end of the list
int append(listPtr_s *list_s, char msg_t[STR_LEN], char status[STR_LEN]);
// add a node to the specified index
// int i    - the index of where to add the node at
int add_at(listPtr_s *list_s, char msg_t[STR_LEN], char status[STR_LEN], int i);

// for all the remove functions:
    // listPtr_s* list_s - a pointer to the list to remove the node from
    // return nothing except for remove at - return 1 on success, 0 on failure

// remove a node from the beginning of the list
void remove_first(listPtr_s *list_s);
// remove a node from the end of the list
void remove_last(listPtr_s *list_s);
// remove a node from the specified index
// int i    - the index of where to add the node at
int remove_at(listPtr_s *list_s, int i);

// check if the list contains the node t.
// listPtr_s list   - the list to look in
// listptr_s t      - the node to look for
//  return the node position in the list or -1 if it isn't present;
int has_node(listPtr_s list, listPtr_s t);

// print at most N nodes from the list
// return nothing
void print_list(listPtr_s t, int n);

// get a specified node located at index i
// listptr_s list   - the list to look in
// int i            - index of the node
// returns the node located at index i
list_s get_node(listPtr_s list, int i);

// get the list node count
// listptr_s list   - the list to look in
// returnus the amount of nodes in the list
int get_list_size(listPtr_s list);

// free all the nodes in the list t
// listptr_s t  - the list to free
// returns nothing
void free_list(listPtr_s t);
