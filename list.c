#include "list.h"


// call malloc and return the pointer. in case of memory allocation failure return NULL;
listPtr_s init_list()
{
    listPtr_s tmp = (listPtr_s)malloc(sizeof(list_s));
    if (tmp == NULL)
    {
        perror("malloc");
    }
    return tmp;
}
// add a node to the beginning of the list
int add(listPtr_s *list, char msg_t[task_len], char status[status_len])
{
    int stat = 1;
    listPtr_s tmp;

    if (list_size == 0)
    {
        *list = init_list();
        strncpy((*list)->task_t, msg_t, task_len);
        strncpy((*list)->status, status, status_len);
        list_size++;
    }
    else
    {

        tmp = init_list();

        if (tmp == NULL)
        {
            stat = 0;
        }
        else
        {
            strncpy((tmp)->task_t, msg_t, task_len);
            strncpy((tmp)->status, status, status_len);
            tmp->next_t = *list;
            *list = tmp;
            list_size++;
        }
        printf("added second\n");
    }
    return stat;
}
// add a node to the end of the list
int append(listPtr_s *list, char msg_t[task_len], char status[status_len])
{
    int stat = 1;
    listPtr_s tmp;
    if (list == NULL)
    {
        *list = init_list();
        if (*list == NULL)
        {
            stat = 0;
            perror("malloc");
        }
        else
        {
            strncpy((*list)->task_t, msg_t, task_len);
            strncpy((*list)->status, status, status_len);
            list_size++;
        }
    }
    else
    {
        tmp = *list;
        while (tmp->next_t != NULL)
        {
            tmp = tmp->next_t;
        }
        tmp->next_t = init_list();
        if (tmp->next_t == NULL)
        {
            stat = 0;
            perror("malloc");
        }
        else
        {
            strncpy((tmp->next_t)->task_t, msg_t, task_len);
            strncpy((tmp->next_t)->status, status, status_len);
            list_size++;
        }
    }
    return stat;
}
// add a node after the specified index.
// in case of error or if the index is illegal return 0, otherwise return 1
int add_at(listPtr_s *list, char msg_t[task_len], char status[status_len], int i)
{
    int stat = 1;
    int counter = 0;
    listPtr_s tmp;
    listPtr_s res;
    listPtr_s tmp1;
    if (i < 0 || i > list_size)
    {
        stat = 0;
    }
    else
    {
        if (*list == NULL)
            *list = init_list();
        tmp = *list;
        if (tmp == NULL)
        {
            stat = 0;
            perror("malloc");
        }
        while (tmp && counter != i - 1)
        {
            tmp = tmp->next_t;
            ++counter;
        }

        if (counter == i - 1)
        {
            tmp1 = tmp->next_t;
            tmp->next_t = init_list();
            if (tmp->next_t == NULL)
            {
                stat = 0;
                perror("malloc");
            }
            else
            {
                tmp = tmp->next_t;
                strncpy((tmp)->task_t, msg_t, task_len);
                strncpy((tmp)->status, status, status_len);
                tmp->next_t = tmp1;
                list_size++;
            }
        }
    }
    return stat;
}
// all the remove functions must free the removed node
void remove_first(listPtr_s *list)
{
    listPtr_s res = NULL;
    if (*list != NULL)
    {
        res = (*list);
        *list = (*list)->next_t;
        free(res);
        list_size--;
    }
}
// remove a node from the end of the list
void remove_last(listPtr_s *list)
{
    listPtr_s tmp = *list;
    listPtr_s res = NULL;
    int counter = 0;
    if (*list != NULL)
    {
        if (tmp->next_t == NULL)
        {
            free(list);
        }
        else
        {

            while (tmp->next_t != NULL)
            {
                if (tmp->next_t->next_t == NULL)
                {
                    res = tmp->next_t;
                    tmp->next_t = NULL;
                    free(res);
                    list_size--;
                    break;
                }
                tmp = tmp->next_t;
                ++counter;
            }
        }
    }
}
// remove a node from the specified index
int remove_at(listPtr_s *list, int i)
{
    listPtr_s tmp = *list;
    listPtr_s res = NULL;
    int counter = 0;
    int stat = 1;
    if (i < 0 || i > list_size)
    {
        stat = 0;
    }
    else if (*list != NULL)
    {
        while (tmp && counter != i - 1)
        {
            res = tmp;
            tmp = tmp->next_t;
            ++counter;
        }
        if (counter == (i - 1) && (i - 1) == 0)
        {
            res = *list;
            *list = (*list)->next_t;
            free(res);
            list_size--;
        }
        else if (counter = i - 1)
        {
            res = tmp->next_t;
            tmp->next_t = tmp->next_t->next_t;
            free(res);
            list_size--;
        }
    }
    return stat;
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
void print_list(listPtr_s t, int n)
{
    int counter = 0;
    listPtr_s tmp = t;
    while (tmp && counter != n)
    {
        printf("%d. %s - %s\n", ++counter, tmp->task_t, tmp->status);
        tmp = tmp->next_t;
    }
}
/* get the list size
int list_size(listPtr_s t)
{
    int counter = 0;
    while (t)
    {
        counter++;
        t = t->next_t;
    }
    return counter;
}
*/

// get a specified node by index
list_s get_node(listPtr_s list, int i)
{
    listPtr_s tmp;
    int counter;
    if (i > 0 && i < list_size)
    {
        for (tmp = list, counter = 0;
             tmp != NULL && counter != i;
             tmp = tmp->next_t, counter++);
    }

    return *tmp;
}

// free all the nodes in the list
void free_list(listPtr_s t)
{
    listPtr_s tmp1 = t;
    listPtr_s tmp2;
    list_size = 0;
    while (tmp1)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next_t;
        free(tmp2);
    }
}