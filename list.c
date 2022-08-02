#include "list.h";
int main()
{
    return 1;
}
// add a node to beginning of the list
int add(char* t)
{
    
}
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

//check if the list is empty
int is_empty(listPtr_s t);
//check if the list contains the given node.
// return the node position in the list or -1 if it isn't present;
int has_node(listPtr_s t, char* n);

