/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : ADC *************************************************/
/*************************** VERSION : 1.00 ********************************************/

#ifndef  ADC_INTERFACE_H_ 
#define  ADC_INTERFACE_H_ 

typedef struct
 {
	u8 *Channel ; 
	u16 *Result ; 
	u8 Size ; 
	void (*NotificationFunc)(void) ; 	
	
}Chain_t; 


void ADC_voidInt(void); 

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16 * copy_puReading); 

 u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16 *Copy_Pu16Reading , void (*copy_pvNotificationFunc)(void)); 

u8 ADC_u8StartChainAsynch(Chain_t * Copy_Chain ); 

#endif