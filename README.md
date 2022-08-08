#todoList
the task is to implement a modular todo list that shall allow the user to add, remove, edit and view "tasks"
"task" is two strings - the task itself and it's completion status
to do the task modulary i sepereated it into three .c files, with two of them having .h files and one having a single main function.
list.c implements the linked list used to store the task
console.c uses list.c to edit and display tasks
inputer.c is used to control console.c
