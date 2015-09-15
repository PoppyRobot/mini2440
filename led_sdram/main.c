/*
main.c:
Copyright (C) 2011  zhenguoyao <yaozhenguo2006@126.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses/.
*/

#include "2440addr.h"

//延时函数
void delay(int a)  
{
       int i,j;
       for(i=0;i<a;i++)
          for(j=0;j<100;j++)
              ;

}
int Main(void)
{
    int light,i;
    
    //定义PB5~PB8为输出
    rGPBCON = (0x1<<10)|(0x1<<12)|(0x1<<14)|(0x1<<16);
    //使PB上拉功能失效
    rGPBUP  = 0x7ff;
    
    light = 0x10;
    light = light<<1;
    
    rGPBDAT = ~light;//第一个LED被点亮
    delay(5000);//延时一段时间
    //主程序死循环
    while(1)
    {
           //从一端向另一端
           for (i=0;i<3;i++)
           {
                  light = light<<1;
                  rGPBDAT = ~light;
                  delay(5000);
           }

           //返回
           for (i=0;i<3;i++)
           {
                  light = light>>1;
                  rGPBDAT = ~light;
                  delay(5000);  
           }
    } 
}

