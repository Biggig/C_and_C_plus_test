#include <stdio.h>

#define MAXLENGTH (1000+1)

int main() {
    char s1[MAXLENGTH], s2[101];
    scanf("%s%s", s1, s2);
    int strMatch(const char *, const char *);
    printf("%d\n", strMatch(s1, s2));
    return 0;
}
#include<string.h> 
int strMatch(const char* s1,const char* s2)
{
	int in1;
	int hold=-1;
	for(in1=0;in1<strlen(s1);in1++)
	{
		if(s1[in1]==s2[0])
		{
			hold=in1;
			int in2,counter=0;
			for(in2=0;in2<strlen(s2);in2++)
			{
				if(s1[in1+in2]!=s2[in2])
				   break;
				else
				   counter=counter+1;   
			}
			if(counter==strlen(s2))
			   break;
			else
			   hold=-1;   	
		}
	}
	return hold;	
} 
