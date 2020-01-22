#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int num;
  scanf("%d",&num);
  char aaa[1010][110];
  int in1;
  for(in1=0;in1<num;in1++)
  {
    scanf("%s",aaa[in1]);
  }
  for(in1=0;in1<num-1;in1++)
  {
    char temp[110]={'\0'};
    int in2;
    for(in2=in1+1;in2<num;in2++)
    {
      if(strcmp(aaa[in1],aaa[in2])>0)
      {
        strcpy(temp,aaa[in1]);
        strcpy(aaa[in1],aaa[in2]);
        strcpy(aaa[in2],temp);
      }
    }
  }
  int in3;
  for(in3=0;in3<num;in3++)
  {
    printf("%s",aaa[in3]);
    printf("\n");
  }
  return 0;
}
