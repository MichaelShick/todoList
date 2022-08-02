#include "list.h";
#include <stddef.h>

int main()
{
    listPtr_s list = init_node();
}
// call malloc and return the pointer. in case of memory allocation failure return NULL;
inline static listPtr_s init_node()
{
    return (listPtr_s)malloc(sizeof(list_s));
}
// add a node to the beginning of the list
int add(listPtr_s list, listPtr_s t)
{
    int status = 1;
    if (list == NULL)
    {
        list = t;
    }
    else
    {
        t->next_t = list;
        list = t;
    }
    return status;
}
// add a node to the end of the list
int append(listPtr_s list, listPtr_s t)
{
    int status = 1;
    listPtr_s tmp;
    if (list == NULL)
    {
        list = t;
    }
    else
    {
        tmp = list;
        while (tmp->next_t != NULL)
        {
            tmp = tmp->next_t;
        }
        tmp->next_t = t;
    }
}
// add a node to the specified index.
// in the index is illegal return 0, otherwise return 1
int add_at(listPtr_s list, listPtr_s t, int i)
{
    int status = 1;
    int counter = 0;
    listPtr_s tmp = list;
    if (i < 0 || i >= list_size(list))
    {
        status = 0;
    }

    while (tmp->next_t != NULL || counter != i)
    {
        tmp = tmp->next_t;
        ++counter;
    }
}
// all the remove functions return a copy of the node that was removed, or NULL if it was not found
// all the remove functions must free the removed node
// remove a node from the beginning of the list
listPtr_s remove(listPtr_s list_s, listPtr_s t)
{
    listPtr_s res = NULL;
    if (list_s != NULL)
    {
        res = list_s->next_t;
        res->next_t = NULL;
        list_s = list_s->next_t;
    }
    return res;
}
// remove a node from the end of the list
listPtr_s remove_last(listPtr_s list_s, listPtr_s t)
{
    listPtr_s tmp = list_s;
    listPtr_s res = NULL;
    int counter = 0;
    if (list_s != NULL)
    {
        while (tmp->next_t != NULL)
        {
            if (tmp->next_t->next_t == NULL)
            {
                res = tmp->next_t;
                tmp->next_t = NULL;
                break;
            }
            tmp = tmp->next_t;
            ++counter;
        }
    }
}
// remove a node from the specified index
listPtr_s remove_at(listPtr_s list_s, int i)
{
    listPtr_s tmp = list_s;
    listPtr_s res = NULL;
    int counter = 0;
    if (list_s != NULL)
    {
        while (tmp->next_t != NULL || counter != i)
        {
            tmp = tmp->next_t;
            ++counter;
        }
    }
}

// check if the list contains the given node.
//  return the node position in the list or -1 if it isn't present;
int has_node(listPtr_s list, listPtr_s t)
{
    listPtr_s tmp = list;
    int counter = 0;
    if (list != NULL)
    {
        while (tmp != t || tmp != NULL)
        {
            ++counter;
            tmp = tmp->next_t;
        }
        if (tmp == NULL)
        {
            counter = -1;
        }
    }
    return counter;
}
// print all the nodes in the list
void print_list(listPtr_s t)
{
    int counter = 0;
    while (t)
    {
        printf("%d. %s - ", counter, t->msg_t, t->status);
    }
}
// get the list size
int list_size(listPtr_s t)
{
    int counter = 0;
    while (t)
    {
        counter++;
    }
    return counter;
}

// free all the nodes in the list
void free_list(listPtr_s t)
{
    listPtr_s tmp1 = t;
    listPtr_s tmp2;
    while (tmp1)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next_t; 
        free(tmp2);
    }
}