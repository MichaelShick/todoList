#include "console.h"
int main()
{
    listPtr_s list;
    int input = 1;
    char string_input[STR_LEN];
    display_options();

    while (input)
    {
        display_options();

        fgets(string_input, STR_LEN, stdin);
        input = atoi(string_input);
        switch (input)
        {
        case VIEW_TASKS:
            display_list(list);
            break;
        case ADD_TASKS:

            system("clear");
            puts("describe the task\n");
            fgets(string_input, STR_LEN, stdin);

            add_task(&list, string_input);

            break;
        case REMOVE_TASKS:
            if (get_list_size(list) == 0)
            {
                puts("the list is empty\n");
            }
            else
            {
                system("clear");
                display_list(list);
                puts("please choose a task or press escape to exit\n");
                fgets(string_input, STR_LEN, stdin);

                input = atoi(string_input);
                if (input <= 0 || input > get_list_size(list))
                {
                    puts("invalid index -_- \n");
                    break;
                }
                delete_task(&list, input - 1);
            }
            break;
        case EDIT_TASKS:
            if (get_list_size(list) == 0)
            {
                puts("the list is empty\n");
            }
            else
            {
                system("clear");
                printf("would you like to edit the task or the status?\n"
                       "1. Task\n"
                       "2. Status\n");
                fgets(string_input, STR_LEN, stdin);

                input = atoi(string_input);
                if (input == 1)
                {
                    system("clear");
                    display_list(list);
                    puts("choose a task to edit\n");
                    fgets(string_input, STR_LEN, stdin);

                    input = atoi(string_input);
                    if (input <= 0 || input > get_list_size(list))
                    {
                        puts("invalid index -_- \n");
                        break;
                    }
                    puts("please type in the task\n");
                    fgets(string_input, STR_LEN, stdin);

                    edit_task_content(&list, input - 1, string_input);
                }

                else if (input == 2)
                {
                    system("clear");
                    display_list(list);
                    puts("choose a task to edit\n");
                    fgets(string_input, STR_LEN, stdin);

                    input = atoi(string_input);
                    if (input <= 0 || input > get_list_size(list))
                    {
                        puts("invalid index -_- \n");
                        break;
                    }
                    puts("please type in the status\n");
                    fgets(string_input, STR_LEN, stdin);

                    edit_task_status(&list, input - 1, string_input);
                }
            }
            break;
        case EXIT_SYS:
            puts("bye!");
            free_list(list);
            break;

        default:
            puts("unknown command");
            break;
        }
    }
    return 1;
}
