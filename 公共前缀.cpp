#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
        char * prefix(char* s1, char* s2);
        char *s1;
        char *s2;
        s1 = (char*)malloc(sizeof(char) * 51);
        s2 = (char*)malloc(sizeof(char) * 51);
        scanf("%s", s1);
        scanf("%s", s2);
        char *ans = prefix(s1, s2);
        if (strlen(ans) == 0) {
                printf("no common prefix\n");
        } else {
                printf("%s\n", ans);
        }
        free(ans);
        free(s1);
        free(s2);
        return 0;
}

char *prefix(char *s1,char *s2)
{
	char *p;
	if(s1[0]==s2[0])
	{
		int in1,counter=0;
		for(in1=0;in1<51;in1++)
		{
			if(s1[in1]==s2[in1])
			{
				counter=counter+1;
			}
			else
				break;
		}
		p=(char*)malloc(sizeof(char)*(counter+1));
		int in2;
		for(in2=0;in2<counter;in2++)
		{
			p[in2]=s1[in2];
		}
		p[counter]='\0';//用strlen时，加\0 
	}
	else
	{
		p=(char*)malloc(sizeof(char));//分配内存，使之不释放。 
		p[0]='\0';
	}
	return p;
}
