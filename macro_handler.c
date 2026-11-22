//macros handling
#include"header.h"

void macro_replacement(char **s){
	char *q;
	while((q=strstr(*s,"#define"))!=0){
		int len_def=7,len_name=0,len_body=0;
		char *start = q;
		char macro_name[300],macro_body[300];
		q=q+len_def;
		len_name=0;
		char *i;
		while(*q!='\0' && (*q==' ' || *q=='\t'))q++;
		//extracting macro name
		while(  *q!='\0' && *q!=' '  && *q!='\t' && *q!='\n' && len_name<299){
			macro_name[len_name++]=*q;
			q++;
		}	macro_name[len_name]='\0';
		
		//handling the spaces and tabs
		while(*q!='\0' && (*q==' ' || *q=='\t'))q++;
		
		//extracting macro  body
		while(*q!='\0' &&  *q!='\n'){
			macro_body[len_body++]=*q;
			q++;
		}	macro_body[len_body]='\0';
		//erasing the #define line
		for(char *i=start; i<q; i++)
			*i=' ';
		//skipping if no name
		if(len_name==0)continue;
		
		printf("macros:%s\nbody:%s\n\n",macro_name,macro_body);
		char *p,*search=q;
		while((p=strstr(q,macro_name))!=0){
			int pos=p-*s;
			int tail_len=strlen(p+len_name);
			
			//resizeing memory if macro body is longer than macro name
			if(len_body > len_name){
				char *temp=realloc(*s,strlen(*s)+(len_body-len_name)+1);
				if(temp==0){
					printf("Memory reallocation failed\n");
					return;
				}
				*s=temp;
				p=*s + pos;
			}
			//shifting remaining string and copy macros body into place
			memmove(p+len_body, p+len_name,tail_len +1);
			memcpy(p,macro_body, len_body);
			
			//move search past the newly inserted macro body
			search= p +len_body;
			
		}
	}
}
