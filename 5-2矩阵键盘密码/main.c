#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;//全局变量如果不赋值，就初始为0.
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)//如果s1~s10的按键被按下，输入密码
			{
				if(Count<4)//只输入4位密码
				{
					Password*=10;//密码左移一位
					Password+=KeyNum%10;//取余数，只获取一位密码，（10余后为0）
					Count++;
				}
				LCD_ShowNum(2,1,Password,4);//更新显示
			}			

			if(KeyNum==11) //按下11键，确认
			{
				if(Password==2345)
				{
					LCD_ShowString(1,14,"OK");
					Password=0;//密码清零
					Count=0;//计次清零
					LCD_ShowNum(2,1,Password,4);//更新显示
				}
				else
				{
					LCD_ShowString(1,14,"ERR");
					Password=0;//密码清零
					Count=0;//计次清零
					LCD_ShowNum(2,1,Password,4);//更新显示					
				}
			}
			if(KeyNum==12)//如果按下12键，就取消
			{
					Password=0;//密码清零
					Count=0;//计次清零
					LCD_ShowNum(2,1,Password,4);//更新显示				
			}
		}
	}
}