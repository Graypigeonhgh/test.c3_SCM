#include <REGX52.H>
#include <LCD1602.h>
#include <Delay.h>

int Result=0;

void main()
{
	LCD_Init();
//	LCD_ShowChar(1,1,'A');//1行1列+字符
//	LCD_ShowString(1,3,"Hello");//1行3列+字符串
//	LCD_ShowNum(1,9,123,3);//1行9列+数字+数字位数（长度）
//	LCD_ShowSignedNum(1,13,-456,3);//有符号的数字
//	LCD_ShowHexNum(2,1,0xA8,2);
//	LCD_ShowBinNum(2,4,0xAA,8);//只能写成十六进制的数字，不能写成1010
	
	while(1)
	{
		Result++;
		Delay(1000);
		LCD_ShowNum(1,2,Result,3);
	}
}