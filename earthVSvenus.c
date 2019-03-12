#define EARTH_DAY 365
#define VENUS_DAY 225
#define EARTH_DIS 1.0
#define VENUS_DIS 0.7
#define PI 3.1415926

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	const int total_day = 16425; // a total period in earth days
	int step = 5;
	int ret = sscanf(argv[1], "%d", &step);
	char outname[100];
	int ret1 = sscanf(argv[2], "%s", outname);
	if (ret != 1)
	{
		printf("Enter an integer as steps on command line!\n");
	}
	if (ret1 != 1)
	{
		printf("Enter a name for output file!\n");
	}
	else
	{
		double earth_x = 1.0;
		double earth_y = 0.0;
		double venus_x = VENUS_DIS;
		double venus_y = 0.0;
		double degree_in_earth_day = 0.0;
		double degree_in_venus_day = 0.0;
		FILE *fp = fopen(outname,"wr");
		if(fp)
		{
			for (int i = 0; i < total_day/step; ++i)
			{
				
				degree_in_earth_day = (double) ((step * i)%EARTH_DAY)/EARTH_DAY;
				earth_x = EARTH_DIS * cos(degree_in_earth_day * 2 * PI);
				earth_y = EARTH_DIS * sin(degree_in_earth_day * 2 * PI);
				degree_in_venus_day = (double) ((step * i)%VENUS_DAY)/VENUS_DAY;
				venus_x = VENUS_DIS * cos(degree_in_venus_day * 2 * PI);
				venus_y = VENUS_DIS * sin(degree_in_venus_day * 2 * PI);
				fprintf(fp,"%lf\t%lf\t%lf\t%lf\n", earth_x, earth_y, venus_x, venus_y);
			}
			fclose(fp);		
		}
		else
		{
			printf("Cant't open file: %s\n", outname);
		}
	}
	return 0;
}
