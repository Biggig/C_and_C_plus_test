int *doubleCapacity(int *list, int size)
{
	int *newlist;
	newlist=(int *)malloc(sizeof(int)*size*2);
	int in1;
	for(in1=0;in1<size*2;in1++)
	{
		newlist[in1]=0;
	}
	for(in1=0;in1<size;in1++)
	{
		newlist[in1]=list[in1];
	}
	return newlist;
}
