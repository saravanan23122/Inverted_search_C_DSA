#include "inverted_search.h"

void display_total_database(Main_Node * Array_index[])
{
    int index = 0;
    printf("Index\t Word\t\t Filecount\t\t Filename - Word count\n");

    while(index < 27)
    {
        if(Array_index[index]!=NULL)
        {
            int flag;
            Main_Node * temp = Array_index[index];
            while(temp !=NULL)
            {
                printf(" [%d]\t %-20s\t%d\t",tolower(temp->word[0]) % 97,temp->word,temp->filecount);
                Sub_Node *sub_temp=temp->Sub_link;
                while(sub_temp != NULL)
                {
                    printf("\t  %s - %d",sub_temp->name,sub_temp->wordcount);
                    sub_temp=sub_temp->Sub_link;
                }
                printf("\n");
                free(sub_temp);
                temp=temp->Main_link;
            }
            printf("\n");
            printf("_________________________________________________________________________\n");    
            free(temp);
        }
        //printf("_________________________________________________________________________\n");
        index ++;
    }
}