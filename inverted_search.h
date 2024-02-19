#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LIST_Empty -2

typedef enum{
	SUCCESS,
	FAILURE
}Status;

typedef struct filenames  
{
    char *name;
    struct filenames* link;
}File_Name;


typedef struct mainnode  
{
    char *word;
    int filecount;
    struct mainnode *Main_link;
    struct subnode *Sub_link;
}Main_Node;

typedef struct subnode
{
    int wordcount;
    char * name;
    struct subnode *Sub_link;
}Sub_Node;

Status file_validation(char*argv[],File_Name **head);

void display_menu();

Status Create_database(File_Name *head,Main_Node *Array_index[]);

Main_Node * insert_main(Main_Node * main_link ,const char * word,const char * filename);

Sub_Node * insert_sub(Main_Node *main_link,Sub_Node * sub_link ,const char * filename);

void display_total_database(Main_Node * Array_index[]);

void search_database(Main_Node * Array_index[],char *word);

Status update_database(Main_Node **ArrayIndex,FILE *fptr);

Status save_database(Main_Node *Array_index[]);
//void traverse(Main_Node * temp,char * word,char* filename);
#endif