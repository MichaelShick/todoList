#include "console.h"

// functions to controll tasks using list.h
// all the functions are for printing and therefor don't return anything

// print a main menu - displaying all the options available for the user
void display_options()
{
    system("clear");
    puts("a                         aaaaaaaa(/////////4aaaaaaaa                        aa\n"
         "a                   4aaaa/////////////////////////////aaaa(                  aa\n"
         "a               aaaa//s////////////////////////////////4s//aaa/              aa\n"
         "a            aaa//sssss////////////////a///////////////(sssss/4aaa           aa\n"
         "a         ,aa(/ssssssss///////////////a,a///////////////ssssssss/saa         aa\n"
         "a       &aa///4ssssssss//////////////a,,,4//////////////ssssssss(///aa/      aa\n"
         "a     *aa/ss///ssssssss//////////////,,,,///////////////ssssssss//4ss/aa     aa\n"
         "a    aa/4ssss//ssssssss/////////////s,,,,,a/////////////ssssssss//ssss((aa   aa\n"
         "a   aa/ssssss//4sssssss////////////a,,,,,,,a////////////sssssss//(ssssss/aa  aa\n"
         "a /aa/ssssssss//sssssss///////////4,,,,,,,,,///////////4sssssss//ssssssss/aa aa\n"
         "a aa/4ssssssss//sssssss4//////////a,,,,,,,,,a//////////sssssss(/(ssssssss//aaaa\n"
         "aaa////ssssssss//sssssss//////////a,,,,,,,,,&//////////sssssss//ssssssss////aaa\n"
         "aa/ss///sssssss4/4ssssss//////////s,,,,,,,,,(//////////ssssss(/ssssssss///s44aa\n"
         "aa/sss///sssssss//ssssss//////////a,,,aaa,,,&//////////ssssss//sssssss///sss/aa\n"
         "aa/ssss///sssssss//sssss4///////aaa   4 4   aaa///////ssssss//sssssss///ssss/aa\n"
         "aa/sssss///sssssss/4sssss///saaa     4   4     (aa&///sssss(/sssssss///sssss/aa\n"
         "aa/ssssss///ssssss4/sssss(//(a.     (4. .44     ,a(//ssssss/ssssss4///ssssss/aa\n"
         "aa/4ssssss///(sssss//sssss//a   /   4     4   /   a//sssss/4sssss///(ssssss(/aa\n"
         "aa(//sssssss///sssss//sssssaa    4(.4  a  4 (4    aa&ssss/4sssss///sssssss//saa\n"
         "aaa////ssssss///sssss(/ssss4aa 4    4 4,4 4    4  asssss/4sssss//(ssssss////aaa\n"
         "a aa/////ssssss///sssss/sssaaaa(44(         (44(4aaasss/sssss///ssssss/////aaaa\n"
         "a  aa/(////ssssss//(ssss/4a,,,,aa    *   /    aa,,,,a//ssss///ssssss////4/aa aa\n"
         "a   aa/ss////(sssss//ssssa,,,,,,aaaaaaaaaaaaaaa,,,,,,asss4//sssss(////ss/aa  aa\n"
         "a    aa((ss(////sssss(/sa,,,,,,,,,,,a,,,,,a,,,,,,,,,,,a4/4ssss4////sss/saa   aa\n"
         "a      aa/ssss4////sssss/4sss/sss///a,,,,,(///sss/sss(/ssss4////ssss4/aa     aa\n"
         "a       *aa/4sssss(///4sss4/ss4sss///,,,,*//(ss4sss/ssss(///4sssss(/aa       aa\n"
         "a          aa&/ssssssss///sss(ss4sss/     /ssssss4sss///ssssssss/aaa         aa\n"
         "a            aaa&///sssssss4/ssssss    s    ssssss/ssssssss///aaa/           aa\n"
         "a               ,aaa///////ssssss(   sssss   (sssss4//////(aaa               aa\n"
         "a                   .aaaa(//4sss/     (s.     ,sss4//saaaa                   aa\n"
         "a                         saaaaaaaa*.     .*aaaaaaaas                        aa\n");
    sleep(1);
    system("clear");
    puts("-------tasks MANAGER - very cool yes-------------\n\n"
         "press escape to exit\n"
         "1. View tasks\n"
         "2. Add tasks\n"
         "3. Remove tasks\n"
         "4. Edit tasks\n");
}
// display all the tasks in the list
// listptr_s list - the list to print from
void display_list(listPtr_s list)
{
    if (list_size_g == 0)
    {
        puts("there are no tasks\n");
    }
    else
    {
        system("clear");
        print_list(list, list_size_g);
    }
    sleep(5);
}

// add task to the list - fill the task_t field with task_name and status with "pending"
// listptr_s *list -  a pointer to the list
// char *task_name - the task name to fill in.

void add_task(listPtr_s *list, char *task_name)
{
    int stat = append(list, task_name, "Pending");
    if (!stat)
    {
        perror("memory problem :c\n");
        free_list(list);
        exit(1);
    }
}
// edit task content - remove the task wit hindex task_num and add it again with task_t replaced by task_name keeping the status the same
// listptr_s *list -  a pointer to the list
// char task_num - the task index
// char *task_name - the task name to fill in.
void edit_task_content(listPtr_s *list, int task_num, char *task_name)
{
    list_s tmp = get_node(*list, task_num);
    if (task_num == 0)
    {
        remove_first(list);

        add(list, task_name, tmp.status);
    }
    else if (task_num > 0)
    {
        remove_at(list, task_num);
        add_at(list, task_name, tmp.status, task_num);
    }
}
// edit task status - remove the task with index task_num and add it again with status_t replaced by status keeping the task_t the same
// listptr_s *list -  a pointer to the list
// char task_num - the task index
// char *status - the task name to fill in.
void edit_task_status(listPtr_s *list, int task_num, char *status)
{
    list_s tmp = get_node(list, task_num);
    if (task_num == 0)
    {
        remove_first(list);

        add(list, tmp.task_t, status);
    }
    else if (task_num > 0)
    {
        remove_at(list, task_num);
        add_at(list, tmp.task_t, tmp.status, task_num);
    }
}
// delete task from list
// // listptr_s *list -  a pointer to the list
// char task_num - the task index
void delete_task(listPtr_s *list, int task_num)
{

    if (task_num == 0)
    {
        remove_first(list);
    }
    else
    {
        remove_at(list, task_num);
    }
}
