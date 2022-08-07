#include "list.h"

#include <stdio.h>

// functions to controll tasks input and display with list.h
void display_options();

// display all the tasks in the list
void display_list(listPtr_s list);

// open add task
void add_task(listPtr_s *list, char *taskName);
// change task
void edit_task_content(listPtr_s *list, int taskNum, char *taskName);

// edit task_menu
void edit_task_status(listPtr_s *list, int taskNum, char *status);
// delete task from list
void delete_task(listPtr_s *list, int taskNum);