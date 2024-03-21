#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void search(char c, char *s, char *fn)
{
	int handle,i=1,cnt=0,j=0;
	char ch,buff[80],*p;
	if((handle=open(fn,O_RDONLY))==-1)
	{
		printf("file %s not found \n",fn);
		return;
	}
	switch(c)
	{
		case 'f':
			while(read(handle,&ch,1)!=0)
			{
				if(ch=='\n')
				{
					buff[j]='\0';
					j=0;
					if(strstr(buff,s)!=NULL)
					{
						printf("%d : %s\n",i,buff);
						break;
					}
					i++;
				}
				else
					buff[j++]=ch;
			}
			break;
		case 'c':
			while (read(handle,&ch,1)!=0)
			{
				if(ch=='\n')
				{
					buff[j]='\0';
					j=0;
					if(strstr(buff,s)!=NULL)
					{
						cnt++;
					}
				}
				else
					buff[j++]=ch;
			}
			printf("Total No. of occurrence = %d\n",cnt);
			break;

		case 'a':
			while(read(handle,&ch,1)!=0)
			{
				if(ch=='\n')
				{
					buff[j]='\0';
					j=0;
					if(strstr(buff,s)!=NULL)
						printf("%d : %s\n",i,buff);
					i++;
				}
				else
					buff[j++]=ch;
			}
	}
	close(handle);
}
int main()
{
	char command[80],t1[20],t2[20],t3[20],t4[20];
	int n;
	system("clear");
		while(1)
		{
			printf("myshell$");
			fflush(stdin);
			fgets(command,80,stdin);
			n=sscanf(command,"%s %s %s %s",t1,t2,t3,t4);
			if(strcmp(t1,"search")==0)
				search(t2[0],t3,t4);
			else
				exit(0);
		}
}

			


