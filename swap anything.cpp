#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapAnyThing(void *a, void *b, size_t val_size)
{
	void *hold=malloc(val_size);
	memcpy(hold,a,val_size);
	memcpy(a,b,val_size);
	memcpy(b,hold,val_size);
	free(hold);
}
