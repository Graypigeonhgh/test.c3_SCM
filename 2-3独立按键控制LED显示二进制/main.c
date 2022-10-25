#include <REGX52.H>

void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
	}
}


void main()
{
	unsigned int LEDnum=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			LEDnum++;
			P2=~LEDnum;
		}
	}
}