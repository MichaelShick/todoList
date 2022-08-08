#include "list.h"

#include <stdio.h>
#define EXIT_SYS 0
#define VIEW_TASKS 1
#define ADD_TASKS 2
#define REMOVE_TASKS 3
#define EDIT_TASKS 4
// functions to controll tasks using list.h
// all the functions are for printing and therefor don't return anything

// print a main menu - displaying all the options available for the user
void display_options();

// display all the tasks in the list
// listptr_s list - the list to print from
void display_list(listPtr_s list);

// add task to the list - fill the task_t field with task_name and status with "pending"
// listptr_s *list -  a pointer to the list
// char *task_name - the task name to fill in.
void add_task(listPtr_s *list, char *taskName);
// edit task content - remove the task wit hindex task_num and add it again with task_t replaced by task_name keeping the status the same
// listptr_s *list -  a pointer to the list
// char task_num - the task index
// char *task_name - the task name to fill in.
void edit_task_content(listPtr_s *list, int taskNum, char *taskName);

// edit task status - remove the task with index task_num and add it again with status_t replaced by status keeping the task_t the same
// listptr_s *list -  a pointer to the list
// char task_num - the task index
// char *status - the task name to fill in.
void edit_task_status(listPtr_s *list, int taskNum, char *status);
// delete task from list
// // listptr_s *list -  a pointer to the list
// char task_num - the task index
void delete_task(listPtr_s *list, int taskNum);