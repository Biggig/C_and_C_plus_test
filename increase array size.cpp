
int *doubleCapacity(int *list,int size,int addSize)
{
	int *newlist;
	newlist=(int *)malloc(sizeof(int)*(size+addSize));
	int in1;
	for(in1=0;in1<size+addSize;in1++)
	{
		newlist[in1]=0;
	}
	for(in1=0;in1<size;in1++)
	{
		newlist[in1]=list[in1];
	}
	return newlist;
}
