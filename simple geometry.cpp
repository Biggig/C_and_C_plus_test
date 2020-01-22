#include<stdio.h>
#include<math.h>
#define PI 3.1415926
int main()
{
	double area;
	scanf("%lf",&area);
	double len=pow(area,0.5);
	double rad=pow(area/PI,0.5);
	double cirarea=PI*pow(len,2)/2;
	printf("%.3lf %.3lf %.3lf\n",len,rad,cirarea);
	return 0;
}
