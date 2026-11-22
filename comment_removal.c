//comment removal file
#include"header.h"
char *cpy_file_to_str(FILE *fp){
	int c=0,i;
	while(fgetc(fp)!=EOF)c++;
	rewind(fp);
	char *file_content=malloc(c+1);
	if(file_content==NULL) return NULL;
	char ch;
	i=0;
	while((ch=fgetc(fp))!=EOF)
		file_content[i++]=ch;
	file_content[i]='\0';
	rewind(fp);
	return file_content;

}
void comment_removal(char *s){
	int i,j;
	for(i=0; s[i]!='\0' ;i++){
		if( s[i]=='"' || s[i]=='\''){
			char quote=s[i];
			i++;
			while(s[i]!=0 && s[i]!=quote){
				if(s[i]=='\\' && (s[i+1]!='\0' )){
					i=i+2;
					continue;
				}
				i++;
			}
			if (s[i] == '\0')break;
		}
		else if(s[i]=='/' && s[i+1]=='*'){
			s[i]=' ';
			s[i+1]=' ';
			for(j=i+2;s[j]!='\0' && !(s[j]=='*' && s[j+1]=='/'); j++){
				if(s[j]=='\n')continue;
				s[j]=' ';
			}
			if (s[j] == '*' && s[j + 1] == '/') {
			s[j++]=' ';
			s[j]=' ';
			}
			i=j-1;
		} else if(s[i]=='/' && s[i+1]=='/'){
			for(j=i;s[j] && s[j]!='\n' ; j++)
				s[j]=' ';
			i=j-1;
		}	
		
	}
}

