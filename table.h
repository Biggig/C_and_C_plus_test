#ifndef TABLE_H
#define TABLE_H

typedef struct table
{
	char gender;
	char name[10];
	int id;
	int score;
}table;

void intput(table *aaa);

void output(int num,table *aaa);

void action1(int num,table *aaa);

void action2(int num,table *aaa);

void action3(int num1,int num2,table *aaa);

void action4(int num,table *aaa);

