//preprocessor header file

#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//main function declaration

//comment removal
void comment_removal(char *);
//macros replacement
void macro_replacement(char **s);
//include file
void file_inclusion(char *,FILE *fp);



//other function declaration
char *cpy_file_to_str(FILE *fp);




#endif
