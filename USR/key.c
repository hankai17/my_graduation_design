#include "pbdata.h"

int KEY_Scanf(void)
{
	//第一行
	Hang_00_L;
	Hang_01_H;
	Hang_02_H;
	Hang_03_H;
	
	if(Lie_00_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_00_V==0)
	   {
			return 1; 
	   }
	}

	if(Lie_01_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_01_V==0)
	   {
	 		return 2;  
	   }
	}

	if(Lie_02_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_02_V==0)
	   {
	 		return 3;  
	   }
	}

	if(Lie_03_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_03_V==0)
	   {
	 		return 11;   
	   }
	}

	//第二行
	Hang_00_H;
	Hang_01_L;
	Hang_02_H;
	Hang_03_H;
	
	if(Lie_00_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_00_V==0)
	   {
			return 4; 
	   }
	}

	if(Lie_01_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_01_V==0)
	   {
	 		return 5; 
	   }
	}

	if(Lie_02_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_02_V==0)
	   {
	 		return 6; 
	   }
	}

	if(Lie_03_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_03_V==0)
	   {
	 		return 12;   
	   }
	}

	//第三行
	Hang_00_H;
	Hang_01_H;
	Hang_02_L;
	Hang_03_H;
	
	if(Lie_00_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_00_V==0)
	   {
			return 7; 
	   }
	}

	if(Lie_01_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_01_V==0)
	   {
	 		return 8;   
	   }
	}

	if(Lie_02_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_02_V==0)
	   {
	 	return 9;  
	   }
	}

	if(Lie_03_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_03_V==0)
	   {
	 		return 13; 
	   }
	}

	//第四行
	Hang_00_H;
	Hang_01_H;
	Hang_02_H;
	Hang_03_L;
	
	if(Lie_00_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_00_V==0)
	   {
		return 14;  
	   }
	}

	if(Lie_01_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_01_V==0)
	   {
	 		return 0; 
	   }
	}

	if(Lie_02_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_02_V==0)
	   {
	 	return 15 ; 
	   }
	}

	if(Lie_03_V==0)
	{	   
	   delay_ms(jpys);
	   if(Lie_03_V==0)
	   {
	 		return 16;  
	   }
	}
	return 10;
}

