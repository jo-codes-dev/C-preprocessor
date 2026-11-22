//Preprocessor handling main

#include"header.h"

int main(int argc, char **argv){
	if(argc!=2){
		printf("Usage: ./mypreprocessor filename.c\n");
		return 1;
	}
	FILE *fp=fopen(argv[1],"r");
	if(fp==0){
		printf("file %s not found check the file name.\n",argv[1]);
		return 1;
	}
	int i;
	char ch;
	//copying the file content as the string
	char *file_content=cpy_file_to_str(fp);
	
	//comment removal function call
	comment_removal(file_content);
	
	//changing the name of file to *.i file and creating the file
	int len=strlen(argv[1]);
	argv[1][len-1]='i';
	FILE *fp2=fopen(argv[1],"w");
	if(fp2==0){
		printf("File Could Not Be Created\n");
		return 1;
	}
	//file inclusion function call
	file_inclusion(file_content,fp2);
	
	//macro replacement function call
	macro_replacement(&file_content);
	printf("%s\n",file_content);
	

	i=0;
	while(ch=file_content[i]){
		fputc(ch,fp2);
		i++;
	}
	
	fclose(fp);
	fclose(fp2);
	free(file_content);
	return 0;
}
