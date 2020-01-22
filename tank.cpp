   #include <stdio.h>

    int capacity;
    extern int error_flag;

    int pour_in(int volume);
    int let_out(int volume);

    int main(void) {
      int n, operation, volume, result;
      /*for operation, 1 means pour_in and 0 means let_out*/
      scanf("%d%d", &capacity, &n);
      while (n--) {
        scanf("%d%d", &operation, &volume);
        result = operation ? pour_in(volume) : let_out(volume);
        printf("%d %d\n", result, error_flag);
      return 0;  
      }
    }
    int error_flag;
    int ini=capacity;
    int pour_in(int num)
    {
    	ini=ini-num;
    	int result=capacity-ini;
    	if(ini<0)
    	{
    	    error_flag=1;
    		ini=0;
    		result=capacity;
		}
    	return result;	
	}
	int let_out(int num)
	{
		ini=ini+num;
		int result=capacity-ini;
		if(result<0)
		{
			result=0;
			ini=capacity;
		}
		return result;
	}
