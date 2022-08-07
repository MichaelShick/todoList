#include "inputer.h"

int main()
{
    display_options();
    return 1;
}
// functions to controll tasks input and display with list.h
void display_options()
{
    int input = 1;
    char string_input[task_len];
    listPtr_s list;
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
    sleep(2);
    while (input != -1)
    {
        sleep(2);
        system("clear");
        puts("-------tasks MANAGER - very cool yes-------------\n\n"
             "press escape to exit\n"
             "1. View tasks\n"
             "2. Add tasks\n"
             "3. Remove tasks\n"
             "4. Edit tasks\n");
        fgets(string_input, 128, stdin);
        input = atoi(string_input);
        switch (input)
        {
        case 1:
            if (list_size_g == 0)
            {
                puts("there are no tasks\n");
            }
            else
            {
                system("clear");
                display_list(list);
            }
            break;
        case 2:

            system("clear");
            puts("describe the task\n");
            fgets(string_input, 128, stdin);

            add_task(&list, string_input);

            break;
        case 3:
            if (list_size_g == 0)
            {
                puts("thw list is empty\n");
            }
            else
            {
                system("clear");

                display_list(list);
                puts("please choose a task or press escape to exit\n");
                fgets(string_input, 128, stdin);
                input = atoi(string_input);
                if (input <= 0 || input > list_size_g)
                {
                    puts("invalid index -_- \n");
                    break;
                }
                delete_task(&list, input - 1);
            }
            break;
        case 4:
            if (list_size_g == 0)
            {
                puts("thw list is empty\n");
            }
            else
            {
                system("clear");
                printf("would you like to edit the task or the status?\n"
                       "1. Task\n"
                       "2. Status\n");
                fgets(string_input, 128, stdin);
                input = atoi(string_input);
                if (input == 1)
                {
                    system("clear");
                    display_list(list);
                    puts("choose a task to edit\n");
                    fgets(string_input, 128, stdin);
                    input = atoi(string_input);
                    if (input <= 0 || input > list_size_g)
                    {
                        puts("invalid index -_- \n");
                        break;
                    }
                    puts("please type in the task\n");
                    fgets(string_input, 128, stdin);
                    edit_task_content(&list, input - 1, string_input);
                }

                else if (input == 2)
                {
                    system("clear");
                    display_list(list);
                    puts("choose a task to edit\n");
                    fgets(string_input, 128, stdin);
                    input = atoi(string_input);
                    if (input <= 0 || input > list_size_g)
                    {
                        puts("invalid index -_- \n");
                        break;
                    }
                    puts("please type in the status\n");
                    fgets(string_input, 128, stdin);
                    edit_task_status(&list, input - 1, string_input);
                }
            }
            break;
        case 0:
            puts("bye!");
            free(list);
            break;

        default:
            puts("unknown command");
            break;
        }
    }
}
// display all the tasks in the list
void display_list(listPtr_s list)
{
    if (list_size_g != 0)
    {
        print_list(list, 20);
    }
}

// add task
void add_task(listPtr_s *list, char *taskName)
{
    int stat = append(list, taskName, "Pending");

    if (!stat)
    {
        printf("memory problem :c\n");
        free_list(list);
        exit(1);
    }
}
// edit task content
void edit_task_content(listPtr_s *list, int taskNum, char *taskName)
{
    list_s tmp = get_node(*list, taskNum);
    if (taskNum == 0)
    {
        remove_first(list);

        add(list, taskName, tmp.status);
    }
    else if (taskNum > 0)
    {
        remove_at(list, taskNum);
        add_at(list, taskName, tmp.status, taskNum);
    }
}
// edit task status
void edit_task_status(listPtr_s *list, int taskNum, char *status)
{
    list_s tmp = get_node(list, taskNum);
    if (taskNum == 0)
    {
        remove_first(list);

        add(list, tmp.task_t, status);
    }
    else if (taskNum > 0)
    {
        remove_at(list, taskNum);
        add_at(list, tmp.task_t, tmp.status, taskNum);
    }
}
// delete task from list
void delete_task(listPtr_s *list, int taskNum)
{

    if (taskNum == 0)
    {
        remove_first(list);
    }
    else
    {
        remove_at(list, taskNum);
    }
}
