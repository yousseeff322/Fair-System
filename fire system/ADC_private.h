/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : ADC *************************************************/
/*************************** VERSION : 1.00 ********************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_REF_BIT_AREF 1
#define ADC_REF_BIT_AVCC 2
#define ADC_REF_BIT_INTRNAL_2_56V 3

#define ADC_LEFT_ADJUST 1
#define ADC_RIGHT_ADJUST 2

#define SINGLE_CONVERSION 1
#define Auto_Trigger 2


#define DIV_BY_2 2
#define DIV_BY_4 4
#define DIV_BY_8 8
#define DIV_BY_16 16
#define DIV_BY_32 32
#define DIV_BY_64 64
#define DIV_BY_128 128



#define FREE_RUNNING 0
#define Analog_Comparator 1
#define External_Interrupt 2
#define Timer_0_Compare_Match 3
#define Timer_0_Compare_Overflow 4
#define Timer_Compare_Match_B 5
#define Timer_1_Overflow 6
#define Timer_1_Capture_Event 6


#define ADC_10BITS 0
#define ADC_8BITS 1


#define Auto_Trigger_Mask 0 
#define ADC_MUX_MUSK 0b11100000
#define PRESCALER_MASK 0b11111000


#define SingleChannelAsync 0 
#define ChainChannelAsync 1



#define IDLE 0
#define BUSY 1




#endif