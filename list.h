#define msg_len 256
#define status_len 64
typedef struct node{
    char msg_t[msg_len];
    char status[status_len];
    struct node *next_t;
}list_s,*listPtr_s;
//call malloc and return the pointer. in case of memory allocation failure return NULL;
listPtr_s init();

//all the add functions return 1 on success, 0 on failure;
//add a node to the beginning of the list
int add(char* t);
//add a node to the end of the list
int append(listPtr_s t);
//add a node to the specified index
int add_at(int i);

//all the remove functions return the node that was removed, or NULL if it was not found
//remove a node from the end of the list
listPtr_s remove(listPtr_s t);
//remove a node from the beginning of the list
listPtr_s remove_first(listPtr_s t);
//remove a node from the specified index
listPtr_s remove_at(int i);

//replace the specified node with a new node.
// if the replacement target isn't in the list return -1
// otherwise return the node index;
//check if the list is empty
int is_empty(listPtr_s t);
//check if the list contains the given node.
// return the node position in the list or -1 if it isn't present;
int has_node(listPtr_s t, char* n);
//print all the nodes in the list
void print_list(listPtr_s t);


