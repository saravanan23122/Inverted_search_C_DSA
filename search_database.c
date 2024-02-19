#include "inverted_search.h"

void search_database(Main_Node * Array_index[],char *word)
{
    int index=0;
    index = (tolower(word[0]) -'a');
    if(Array_index[index]!=NULL)
    {
        Main_Node * main_node=Array_index[index];
        while(main_node != NULL)
        {
            if(!strcmp(main_node->word,word))
            {
                printf("Word present in %d file \n",main_node->filecount);
                Sub_Node * sub_node=main_node->Sub_link;
                while(sub_node != NULL)
                {
                    printf("File name %s word count %d ",sub_node->name,sub_node->wordcount);
                    sub_node=sub_node->Sub_link;
                }
                printf("\n");
                break;
            }
            main_node=main_node->Main_link;
        }
    }
    else
    {
        printf("ERROR : No word found in the list\n");
    }
    
}