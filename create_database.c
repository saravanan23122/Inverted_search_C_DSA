#include "inverted_search.h"
extern int created;

Status Create_database(File_Name *head,Main_Node *Array_index[])
{
    while(head != NULL)
    {
        FILE *fptr = fopen(head->name,"r");
        if(fptr == NULL)
        {
            fprintf(stderr,"Unable to open the file\n");
            exit(1);
        }
        char word[50];
        while(fscanf(fptr,"%s",word) != EOF)    
        {
            int index = (tolower(word[0]) - 'a');
            if(index >=0 && index < 26);
            else
            {
                index=26;
            }       
            Array_index[index] = insert_main(Array_index[index],word,head->name);        
        }
        fclose(fptr);
        head = head->link;
    }
    created=1;
    return SUCCESS;

}



Main_Node * insert_main(Main_Node * main_link ,const char * word,const char * filename)
{
    Main_Node * current = main_link;
    Main_Node * previous = NULL;
    while(current != NULL)
    {
        if(!strcmp(word,current->word))
        {
            current->Sub_link = insert_sub(current,current->Sub_link, filename);
            return main_link;
        }
        previous = current;
        current = current->Main_link;
    }

    Main_Node * new_main = malloc(sizeof(Main_Node));
    if(new_main == NULL)
    {
        printf("ERROR : Main node creation error\n");
        return main_link;
    }
    new_main->filecount = 0;
    new_main->word = strdup(word);
    new_main->Main_link = NULL;
    new_main->Sub_link=insert_sub(new_main,NULL,filename);

    if(previous != NULL)
    {
        previous->Main_link = new_main;
    }
    else
    {
        main_link = new_main;
    }

    return main_link;
}


Sub_Node * insert_sub(Main_Node *main_node ,Sub_Node* sub_link,const char * filename)
{
    Sub_Node * current =sub_link;
    Sub_Node * previous = NULL;
    int file_name_found=0;
    while(current != NULL)
    {
        if(!strcmp(current->name,filename))
        {
            file_name_found=1;
            current->wordcount += 1;
            return sub_link;
        }
        previous = current;
        current = current->Sub_link;
    }
    Sub_Node * new_sub = malloc(sizeof(Sub_Node));
    if(new_sub == NULL)
    {
        printf("ERROR : Sub Node Creation error\n");
        return sub_link;
    }

    new_sub->wordcount = 1;
    new_sub->name = strdup(filename);
    new_sub->Sub_link =NULL;
    if(previous != NULL)
    {
        previous->Sub_link =new_sub;
    }
    else
    {
        sub_link = new_sub;
    }
    if(!file_name_found)
    {
        main_node->filecount+=1;
    }
    return sub_link;
}


