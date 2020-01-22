#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,m;
	scanf("%lld%lld",&n,&m);
	long long x,y;
	x=365*n;
	y=pow(2,x);
	printf("%lld\n",(y-x)%400009);
	return 0;
}
