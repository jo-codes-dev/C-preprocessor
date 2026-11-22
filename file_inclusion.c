//handling file inclusion
#include"header.h"

void file_inclusion(char *s , FILE *fp2){
	char *q,*path[100];
	int k;
	FILE *temp;
	while((q=strstr(s,"#include"))!=0){
		int len=8;
		char symbol=0,*start=q;
		char path[300],file_name[100];
		q=q+len;
		while(*q==' ' || *q=='\t')q++;
		if(*q=='<'){
			symbol=*q;
			q++;
			k=0;
			while(*q!='\0' && *q!='>' && k<99){
				file_name[k++]=*q;
				q++;
			}
			file_name[k]='\0';
			for(char *i=start; i<=q ;i++)
				*i=' ';
		}else if(*q=='"'){
			symbol=*q;
			q++;
			k=0;
			while(*q!='\0' && *q!='"' && k<99 ){
				file_name[k++]=*q;
				*q=' ';
				q++;
			}
			file_name[k]='\0';
			for(char *i=start; i<=q ;i++)
				*i=' ';
		}
		if(symbol=='<'){
			sprintf(path,"/usr/include/%s",file_name);
			temp=fopen(path,"r");
			if(temp==0){
				printf("%s:No Such Inclusion File Found\n",file_name);
				return ;
			}
		}else if(symbol=='"'){
			sprintf(path,"%s",file_name);
			temp=fopen(path,"r");
			if(temp==0){
				sprintf(path,"/usr/include/%s",file_name);
				temp=fopen(path,"r");
				if(temp==0){
					printf("%s:No Such Inclusion File Found\n",file_name);
					return ;
				}
			}
			
		}
		
		if(symbol){
			fseek(temp,0,SEEK_END);
			int size = ftell(temp);
			rewind(temp);
			char ch;
			while((ch=fgetc(temp))!=EOF){
				fputc(ch,fp2);
			}
			fclose(temp);
		}
	}
}
