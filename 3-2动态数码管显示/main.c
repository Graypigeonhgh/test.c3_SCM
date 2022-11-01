#include <REGX52.H>

unsigned char Nixietable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Delay(unsigned int xms)		
{
	unsigned char i, j;
	while(xms--)
	{
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
}


void Nixie(unsigned char Location,Number)
{
	switch(Location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=Nixietable[Number];
	Delay(1);//延迟1秒
	P0=0x00;//屏幕清零
}
void main()
{
	while(1)
	{	
		Nixie(1,1);
		//Delay(1000);
		Nixie(2,2);
		//Delay(1000);
		Nixie(3,3);
		//Delay(1000);
		Nixie(4,4);	
		//Delay(1000);
		Nixie(5,5);	
		//Delay(1000);
		Nixie(6,6);
		//Delay(1000);
		Nixie(7,7);
		//Delay(1000);
		Nixie(8,8);
	}
}
