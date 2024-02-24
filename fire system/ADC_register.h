/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : ADC *************************************************/
/*************************** VERSION : 1.00 ********************************************/

#ifndef  ADC_REGISTER_H_ 
#define  ADC_REGISTER_H_ 




 #define ADMUX           *(( volatile u8*) 0x27 )    // ADC Multiplexer selection reister 

 #define ADMUX_REFS1    7							// Reference selection bit1 
 #define ADMUX_REFS0    6							// Reference selection bit0		
 #define ADMUX_ADLAR    5							// ADC Left adjust result 
 #define ADMUX_MUX4_BIT 4
 #define ADMUX_MUX3_BIT 3
 #define ADMUX_MUX2_BIT 2
 #define ADMUX_MUX1_BIT 1
 #define ADMUX_MUX0_BIT 0
 
 #define ADCSRA         *(( volatile u8*) 0x26 )	//ADC control and status register A
 #define ADCSRA_ADEN			  7					// ADC enable	
 #define ADCSRA_ADSC			  6					// start conversion 
 #define ADCSRA_ADATE			  5					// Auto trigger enable 
 #define ADCSRA_ADIF			  4					// Interrupt flag 
 #define ADCSRA_ADIE			  3					// Interrupt flag		
 #define ADCSRA_ADPS2			  2					//  Prescaler bit2
 #define ADCSRA_ADPS1			  1					//  Prescaler bit1
 #define ADCSRA_ADPS0			  0					//  Prescaler bit0	
 
 
 #define ADCH           *(( volatile u8*) 0x25 )		//ADC high register
 
 #define ADCL           *(( volatile u8*) 0x24 )		//ADC low register
#define ADC             *((volatile u16 *)(0x24))


 #define SFIOR           *(( volatile u8*) 0x50)		//Special FunctionIO Register 
 #define SFIOR_ADTS2			  7					//  ADC Auto Trigger Source
 #define SFIOR_ADTS1			  6				    //  ADC Auto Trigger Source
 #define SFIOR_ADTS0			  5					//  ADC Auto Trigger Source



#endif