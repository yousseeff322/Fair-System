/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : ADC *************************************************/
/*************************** VERSION : 1.00 ********************************************/



#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_ 


/*set refrence selection bit 
        OPTIONS 
1- ADC_REF_BIT_AREF
2- ADC_REF_BIT_AVCC
3- ADC_REF_BIT_INTRNAL_2_56V
*/
#define ADC_REF_SELECTION_BIT   ADC_REF_BIT_AVCC

/*Left Or Right Adjust Result
      OPTIONS 
1- ADC_LEFT_ADJUST
2- ADC_RIGHT_ADJUST
*/
#define ADC_ADLAR_RESULT       ADC_RIGHT_ADJUST

/*
PRESCALER options 
        1-DIV_BY_2 
		2-DIV_BY_4
		3-DIV_BY_8
		4-DIV_BY_16
		5-DIV_BY_32 
		6-DIV_BY_64
		7-DIV_BY_128
		
*/
#define ADC_PRESCALER  	DIV_BY_128 	

/* 
CONVERSION options
	1- SINGLE_CONVERSION 
	2- Auto_Trigger 
	
*/  
	
#define ADC_CONVERSION  SINGLE_CONVERSION

/* choose ADC Auto_Trigger sorce ONLY work in Auto_Trigger MODE 
	1- FREE_RUNNING
	2-Analog_Comparator
	3-External_Interrupt
	4-Timer_0_Compare_Match
	5-Timer_0_Compare_Overflow
	6-Timer_Compare_Match_B
	7-Timer_1_Overflow
	8- Timer_1_Capture_Event
*/ 

#define  ADC_AUTO_TRIG  FREE_RUNNING


/*
ADC MODE options 
 ADC_10BITS 
 ADC_8BITS 
*/
#define  ADC_RESLETION  ADC_10BITS

#define ADC_u32TIMEOUT   50000



#endif

