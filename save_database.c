#include "inverted_search.h"

Status save_database(Main_Node *Array_index[])
{
    char file_name[25];
    printf("Enter the name of the file to save the database \n");
    scanf("%s",file_name);
    if((strchr(file_name,'.') == NULL) || strcmp(strchr(file_name,'.'),".txt")!=0)
    {
        printf("INFO : Extension .txt is added to the given filename\n");
        strcat(file_name,".txt");
    }
    FILE * fptr = fopen(file_name,"w");

    //fprintf(fptr, "Index        word    File count  Files/s     File name       word count\n");
    for(int i=0;i<27;i++)
    {
        if(Array_index[i] != NULL)
        {
            Main_Node * main_temp=Array_index[i];
            while (main_temp != NULL)
            {
                fprintf(fptr,"#%d:%s:%d",(tolower(main_temp->word[0])-'a'),main_temp->word,main_temp->filecount);
                Sub_Node *sub_temp =main_temp->Sub_link;
                while(sub_temp !=NULL)
                {
                    fprintf(fptr,":%s:%d",sub_temp->name,sub_temp->wordcount);
                    sub_temp=sub_temp->Sub_link;
                }
                fprintf(fptr,"#\n");
                main_temp=main_temp->Main_link;
            }
        }
    }
    return SUCCESS;
}