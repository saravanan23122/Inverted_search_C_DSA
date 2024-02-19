#include "inverted_search.h"
//#define CYAN "\x1b[36m"
//#define CC_CLEAR "\x1b[0m" // Console Color CLEAR
void textcolor(char *color);

Status file_validation (char *argv[],File_Name **head)
{
    int i=1;
    if(argv[i]==NULL)
    {
        printf("INFO : Database can created through Update Database option\n");
        return SUCCESS;
    }
    while (argv[i]!=NULL)
    {
        FILE *fptr=fopen(argv[i],"r");
        if(fptr != NULL)
        {
            fseek(fptr, 0, SEEK_END);
            int File_Size=ftell(fptr);
            rewind(fptr);

            if(File_Size>=1)
            {
                File_Name *new = malloc(sizeof(File_Name));
                if(new == NULL)
                {
                    printf("ERROR: File Name List creation failure\n");
                    exit(1);
                }
                new->name=malloc(strlen(argv[i])+1);
                strcpy(new->name,argv[i]);
                new->link=NULL;
                if(*head == NULL)
                {
                    *head = new;
                    printf("INFO: %s Appended In The List Successfully\n",new->name);    
                }
                else
                {
                    File_Name *temp = *head;
                    File_Name *previous_temp = *head;
                    while(temp!=NULL)
                    {
                        if(!strcmp(argv[i],temp->name))
                        {
                            //textcolor(CYAN);
                            printf("ERROR:The File Name %s Already exist\n",argv[i]);
                            //textcolor(CC_CLEAR);
                            break;
                        } 
                        previous_temp = temp;
                        temp=temp->link;
                    }
                    if(temp ==NULL)
                    {
                        previous_temp->link=new;
                        printf("INFO: %s Appended In The List Successfully\n",new->name);
                    }
                }
            }
            else
            {
                printf("ERROR: The File %s Is Empty\n",argv[i]);
            }
            fclose(fptr);
        }
        else
        {
            printf("ERROR:UNABLE TO OPEN THE FILE %s May not Exist\n",argv[i]);
        }
        i++;
    }

    printf("Contents Of The Filename Linked List\n");
    File_Name * print_temp = *head;
    int count=0;
    while(print_temp != NULL)
    {
        printf("[%d] %s -> ",count,print_temp->name);
        count++;
        print_temp = print_temp->link;
    }
    printf("NULL\n");
    return SUCCESS;
}

void textcolor(char *color)
{
    printf("%s", color);
}

