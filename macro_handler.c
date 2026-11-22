//macros handling
#include"header.h"

void macro_replacement(char **s){
	int def_pos=0;
	char *q;
	while((q=strstr(*s,"#define"))!=0){
		int len_def=7,len_name=0,len_body=0;
		char *start = q;
		char macro_name[300],macro_body[300];
		char params[10][50];
		int has_args=0,param_count=0;
		
		q=q+len_def;
		while(*q!='\0' && (*q==' ' || *q=='\t'))q++;
		//extracting macro name
		while(  *q!='\0' && *q!=' '  && *q!='\t' && *q!='\n' && *q!='(' && len_name<299){
			macro_name[len_name++]=*q;
			q++;
		}	macro_name[len_name]='\0';
		
		//extracting the parameters if arguments exists
		if(*q=='('){
			has_args=1;
			q++;
			while(*q!='\0' && *q!=')' && *q!='\n' && param_count<10){
				int k=0;
				while(*q==' ' || *q=='\t')q++;
				while(*q!='\0' && *q!=',' && *q!=')' && *q!=' ' && *q!='\t' && *q!='\n' && k<49){
					params[param_count][k++]=*q++;
				}	params[param_count][k]='\0';
				if(k>0) param_count++;  	//countion the arguments
				while(*q==' ' || *q=='\t')q++;  //handling spaces
				if(*q==',')q++;
			}
			if(*q==')') q++;
		}
		
		//handling the spaces and tabs
		while(*q!='\0' && (*q==' ' || *q=='\t'))q++;
		
		//extracting macro  body
		while(*q!='\0' &&  *q!='\n' && len_body<299){
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
		
		while( (p=strstr(search,macro_name))!=0 ){
			int pos = p-*s,match_len=len_name;
			char expanded[500],*rep=macro_body;
			
			if(has_args){
				char *r=p+len_name,args[10][100];
				int arg_count=0;
				if(*r!='('){ search=p+len_name;continue;}
				r++;
				while(*r && *r!=')' && arg_count<10){
					int a=0;
					while(*r==' ' || *r=='\t')r++;
					while(*r && *r!=',' && *r!=')' && a<99)
						args[arg_count][a++]=*r++;
					args[arg_count][a]='\0';
					arg_count++;
					if(*r==',')r++;
				}
				if( *r!=')' || arg_count!=param_count){ search=p+len_name;continue;}
				match_len=(r+1)-p;
				
				//replace params with args in macro body
				strcpy(expanded, macro_body);
				for(int k=0 ; k<param_count; k++){
					char *m,*cur=expanded;
					int plen=strlen(params[k]),alen=strlen(args[k]);
					while((m=strstr(cur,params[k]))!=0){
						memmove(m+alen, m+plen, strlen(m+plen)+1);
						memcpy(m,args[k],alen);
						cur=m+alen;
					}
				}
				rep=expanded;
			}	
			int rep_len=strlen(rep), tail_len=strlen(p+match_len);
			if(rep_len > match_len){
				char *temp=realloc(*s, strlen(*s)+(rep_len-match_len)+1);
				if(temp==0){ printf("Memory reallocation failed\n"); return; }
				*s=temp;
				p=*s+pos;
			}
			memmove(p+rep_len, p+match_len, tail_len+1);
			memcpy(p, rep, rep_len);
			search=p+rep_len;	
		}
				
		//for without argument
		/*
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
		*/
	}
}
