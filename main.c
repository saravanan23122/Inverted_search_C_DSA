#include "inverted_search.h"

extern int no_args;
int no_args = 0;
int created = 0;
int main(int argc,char *argv[])
{
    int choice;
    char option='y';
    File_Name *head = NULL;
    if(argc == 1)
    {
        no_args=1;
        printf("INFO : No Files passed\n");
    }
    if(file_validation(argv,&head)==SUCCESS);
    {
        Main_Node * Array_index[27]={NULL};
        while(option == 'y' || option == 'Y')
        {
            display_menu();
            scanf("%d",&choice);
            int database=0;
            char search_word[20];
            char filename[30];
            switch(choice)
            {
                case 1:
                    //Create database
                    if(no_args == 0)
                    {
                        if(created == 0)
                        {
                            printf("INFO : Creating Database\n");
                            if(Create_database(head,Array_index)==SUCCESS)
                            {
                                printf("INFO : Database Created Successufully\n");
                            }
                            else
                            {
                                printf("ERROR : Database creation Failure\n");
                            }
                        }
                    }
                    break;
                case 2:
                    //Display Database
                    display_total_database(Array_index);
                    break;
                case 3:
                    //Update Database
                    if(created==0)
                    {
                        printf("Enter the Backup file to update : ");
                        scanf("%s",filename);
                        FILE *fptr = fopen(filename,"r");
                        if(fptr != NULL)
                        {
                            char first =fgetc(fptr);
                            fseek(fptr,-2,SEEK_END);
                            char last =fgetc(fptr);
                            rewind(fptr);
                            if(first =='#' && last == '#')
                            {
                                if(update_database(Array_index,fptr) == SUCCESS)
                                {
                                    printf("INFO : Data Updated Successfully\n");
                                }
                                else
                                {
                                    printf("ERROR : Unable to create database\n");
                                }
                            }
                            else
                            {
                                printf("INFO : File is not a backup file\n");
                            }
                        }
                        else
                        {
                            printf("INFO : File not exist\n");
                        }
                    }
                    else
                    {
                        printf("INFO : The Database is already created\n");
                    }
                    break;
                case 4:
                    //Search
                    if(created == 1)
                    {
                        printf("Enter the word you want to search : ");
                        scanf("%s",search_word);
                        search_database(Array_index,search_word);
                    }
                    else
                    {
                        printf("INFO : Database is empty unable to search for word\n");
                    }
                    break;
                case 5:
                    //Save Database
                    if(created == 1)
                    {
                        if(save_database(Array_index)==SUCCESS)
                        {
                            printf("INFO : Database saved successfully\n");
                        }
                        else
                        {
                            printf("INFO : Saving Database file failure\n");
                        }
                    }
                    else
                    {
                        printf("INFO : Database is empty unable to save database file\n");
                    }
                    break;
                default:
                    printf("ERROR : Enter valid option: \n");
                    //Enter the correct option
            }
            printf("Do You Want To Continue Y/N\n");
            scanf(" %c",&option);
        }
    }
}


void display_menu()
{
    printf("Select the choice among the following options : \n");
    printf("1.Create Database\n2.Display Database\n3.Update Database\n4.Search\n5.Save Database\nEnter your choice: ");
}