#include "inverted_search.h"

extern int created;
Status update_database(Main_Node **ArrayIndex,FILE *fptr)
{
    printf("INFO : Updating Database\n");
    created = 1;
    int index,filecount,wordcount;
    char *word;
    char filename[30];
    char * delimiter = "#:";
    char line[50];
    while(fscanf(fptr,"%s",line) != EOF)
    {
        index = atoi(strtok(line,delimiter));
        word = strtok(NULL,delimiter);
        filecount = atoi(strtok(NULL,delimiter));
        Main_Node *main_node=malloc(sizeof(Main_Node));
        main_node->word=strdup(word);
        main_node->filecount = filecount;
        main_node->Main_link = NULL;
        main_node->Sub_link = NULL;
        for(int i=1;i<filecount;i++)
        {
            strcpy(filename,strtok(NULL,delimiter));
            wordcount = atoi(strtok(NULL,delimiter));
            Sub_Node *sub_node = malloc(sizeof(Sub_Node));
            sub_node->wordcount = wordcount;
            sub_node->name=strdup(filename);
            sub_node->Sub_link = NULL;
            if(main_node->Sub_link == NULL)
            {
                main_node->Sub_link = sub_node;
            }
            else
            {
                Sub_Node * sub_temp = sub_node->Sub_link;
                while(sub_temp->Sub_link != NULL)
                {
                    sub_temp = sub_temp->Sub_link;
                }
                sub_node->Sub_link=sub_node;
            }
        }

        if(ArrayIndex[index] == NULL)
        {
            ArrayIndex[index]= main_node;
        }
        else
        {
            Main_Node * main_temp = ArrayIndex[index];
            while(main_temp->Main_link != NULL)
            {
                main_temp=main_temp->Main_link;
            }
            main_temp->Main_link = main_node;
        }
    }
    return SUCCESS;
}