#include <REGX52.H>
#include <INTRINS.H>

void Delay1000ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 154;
	k = 122;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	while(1)
	{
		P2=0xFE;
		Delay1000ms();	
		P2=0xFD;
		Delay1000ms();
		P2=0xFB;
		Delay1000ms();
		P2=0xF7;
		Delay1000ms();
		P2=0xEF;
		Delay1000ms();
		P2=0xDF;
		Delay1000ms();
		P2=0xBF;
		Delay1000ms();
		P2=0x7F;
		Delay1000ms();
		P2=0x55;
		Delay1000ms();
		P2=0xFF;
		Delay1000ms();

	}
}
