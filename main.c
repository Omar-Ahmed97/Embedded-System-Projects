/*
 * node_controller.c
 *
 * Created: 25/01/2020 03:43:54 م
 * Author : Omar
 */ 


#include "main.h"
#include "Port.h"
#include "Sos.h"
#include "Switch.h"
#include "Segments.h"

int main(void)
{

	volatile unsigned int NO_List=0;        //index of main list
	volatile unsigned int Digital_panel_Frequency_Command  = 0 ;
	volatile unsigned int Command_frequency_source_select =0;
	volatile unsigned int Operation_Command_source =0;
	volatile unsigned int Acceleration_time = 0;
	volatile unsigned int Deceleration_time = 0;

	volatile unsigned int Output_Cur = 0;
	volatile unsigned int Motor_RPM = 0;

	volatile unsigned int DClink_Voltage = 0;
	
	volatile char SELECTED = LOW;    // this index have been selected
	
	port_init();
	Timer0_init();
    while (1) 
    {
		UP_pressed(&NO_List,1);    //switch UP_pressed increment counter
		DOWN_pressed(&NO_List,1);   //switch DOWN_pressed decrement counter
		OK_pressed(&SELECTED,HIGH); // selsction has done
		
		if(NO_List > NO_List+1)
			NO_List =MAX_NUM_ITEMS;
		if(NO_List > MAX_NUM_ITEMS)
			NO_List =0;
		
		switch (NO_List)
		{
			case 0 :
			{   s1=0;
				s2=0;
				s3=0;
				if(SELECTED){
					do{
						
						if(Digital_panel_Frequency_Command < 400)
						UP_pressed(&Digital_panel_Frequency_Command,1);
						else UP_pressed(&Digital_panel_Frequency_Command,0);
						
						if(Digital_panel_Frequency_Command > 0)
						DOWN_pressed(&Digital_panel_Frequency_Command,1);
						else  DOWN_pressed(&Digital_panel_Frequency_Command,0);
						OK_pressed(&SELECTED,LOW);

						s1=Digital_panel_Frequency_Command%10;
						s2=(Digital_panel_Frequency_Command/10)%10;
						s3=(Digital_panel_Frequency_Command/100)%10;
						
					}while(SELECTED);
					
					
					
				}
			}
			
			break;
			case 1:
			{      s1=q;
				s2=r;
				s3=F;
				if(SELECTED){
					do{
						
						if(Command_frequency_source_select < 4)
						UP_pressed(&Command_frequency_source_select,1);
						else UP_pressed(&Command_frequency_source_select,0);
						
						if(Command_frequency_source_select > 0)
						DOWN_pressed(&Command_frequency_source_select,1);
						else  DOWN_pressed(&Command_frequency_source_select,0);
						OK_pressed(&SELECTED,LOW);

						s1=Command_frequency_source_select%10;
						s2=(Command_frequency_source_select/10)%10;
						s3=(Command_frequency_source_select/100)%10;
						
					}while(SELECTED);
				
				}
			}
			break;
			case 2:
			{      s1=v;
				s2=r;
				s3=d;
				if(SELECTED){
					do{
						
						if(Operation_Command_source < 4)
						UP_pressed(&Operation_Command_source,1);
						else UP_pressed(&Operation_Command_source,0);
						
						if(Operation_Command_source > 0)
						DOWN_pressed(&Operation_Command_source,1);
						else  DOWN_pressed(&Operation_Command_source,0);
						OK_pressed(&SELECTED,LOW);

						s1=Operation_Command_source%10;
						s2=(Operation_Command_source/10)%10;
						s3=(Operation_Command_source/100)%10;
						
					}while(SELECTED);
					
				}
			}
			break;
			case 3:
			{      s1=C;
				s2=C;
				s3=A;
				if(SELECTED){
					do{
						
						if(Acceleration_time < 600)
						UP_pressed(&Acceleration_time,10);
						else UP_pressed(&Acceleration_time,0);
						
						if(Acceleration_time > 0)
						DOWN_pressed(&Acceleration_time,10);
						else  DOWN_pressed(&Acceleration_time,0);
						OK_pressed(&SELECTED,LOW);

						s1=Acceleration_time%10;
						s2=(Acceleration_time/10)%10;
						s3=(Acceleration_time/100)%10;
						
					}while(SELECTED);
					
					
				}
			}
			break;
			
			case 4:
			{   
				s1=C;
				s2=E;
				s3=d;
				if(SELECTED){
					do{
						
						if(Deceleration_time < 600)
						UP_pressed(&Deceleration_time,10);
						else UP_pressed(&Deceleration_time,0);
						
						if(Deceleration_time > 0)
						DOWN_pressed(&Deceleration_time,10);
						else  DOWN_pressed(&Deceleration_time,0);
						OK_pressed(&SELECTED,LOW);

						s1=Deceleration_time%10;
						s2=(Deceleration_time/10)%10;
						s3=(Deceleration_time/100)%10;
						
					}while(SELECTED);


				}
			}
			break;
			case 5:
			{   
				s1=r;
				s2=U;
				s3=C;
				if(SELECTED){
					do{
						
						// READ(&OUTPUT_CURR)
						OK_pressed(&SELECTED,LOW);

						s1=Output_Cur%10;
						s2=(Output_Cur/10)%10;
						s3=(Output_Cur/100)%10;
						
					}while(SELECTED);

					
				}
			}
			break;
			case 6:
			{      s1=M;
				s2=p;
				s3=r;
				if(SELECTED){
					do{
						
						OK_pressed(&SELECTED,LOW);

						//READ(RPM)
						s1=Motor_RPM%10;
						s2=(Motor_RPM/10)%10;
						s3=(Motor_RPM/100)%10;
						
					}while(SELECTED);
					
				}
			}
			break;
			case 7:
			{      s1=L;
				s2=C;
				s3=d;
				if(SELECTED){
					do{
						

						OK_pressed(&SELECTED,LOW);

						//SHOW(DC_LINK_VOLTAGE)

						s1=DClink_Voltage%10;
						s2=(DClink_Voltage/10)%10;
						s3=(DClink_Voltage/100)%10;
						
					}while(SELECTED);
					
				}
			}
			break;
			case 8:
			{      s1=n;
				s2=o;
				s3=n;
				if(SELECTED){
					do{
						
						
						OK_pressed(&SELECTED,LOW);
						

						//Displays the types of faults, frequency and operating status at the time of the fault

						
					}while(SELECTED);
					
				}
			}
			break;
			
			
		}

	    
    }
}

