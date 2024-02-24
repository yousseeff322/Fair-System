/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : ADC *************************************************/
/*************************** VERSION : 1.00 ********************************************/
#include "STD_type.h"
#include "BIT_math.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"

 

 
static u16* ADC_pu16Reading = NULL ; 
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL ; 
u8 ADC_u8BusyState = IDLE   ;
/* chain */ 
static u8 * ADC_pu8ChainChannelArr = NULL ;   /*Global var to carry chain array  */
static u8  ADC_u8ChainSize   ; 
static u16 * ADC_pu16ChainResultArr = NULL ;
static u8  ADC_u8ChainConverstionIndex =0    ;
static u8  ADC_u8ISRSource     ;





void ADC_voidInt(void){
	
	/* choose voltage ref */
	#if (ADC_REF_SELECTION_BIT==ADC_REF_BIT_AREF)
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	#elif (ADC_REF_SELECTION_BIT==ADC_REF_BIT_AVCC)
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	#elif (ADC_REF_SELECTION_BIT==ADC_REF_BIT_INTRNAL_2_56V)
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
	#else
	#error "wrong Voltage ref "
	#endif
	
	
	/* choose  adjust result */

	#if (ADC_ADLAR_RESULT==ADC_LEFT_ADJUST)
	SET_BIT(ADMUX,ADMUX_ADLAR);
	#elif (ADC_ADLAR_RESULT==ADC_RIGHT_ADJUST)
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	#else
	#error "wrong adjust result "
	#endif

	/* set PRESCALER */
	
	#if ADC_PRESCALER == DIV_BY_2
	{
		CLR_BIT(ADCSRA,  ADCSRA_ADPS2);
		CLR_BIT(ADCSRA,  ADCSRA_ADPS1);
		SET_BIT(ADCSRA,  ADCSRA_ADPS0);
	}
	#elif ADC_PRESCALER == DIV_BY_4
	{
		CLR_BIT(ADCSRA,  ADCSRA_ADPS2);
		SET_BIT(ADCSRA,  ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,  ADCSRA_ADPS0);
	}
	#elif ADC_PRESCALER == DIV_BY_8
	{
		CLR_BIT(ADCSRA,  ADCSRA_ADPS2);
		SET_BIT(ADCSRA,  ADCSRA_ADPS1);
		SET_BIT(ADCSRA,  ADCSRA_ADPS0);
	}
	#elif ADC_PRESCALER == DIV_BY_16
	{
		SET_BIT(ADCSRA, ADCSRA_ADPS2);
		CLR_BIT(ADCSRA, ADCSRA_ADPS1);
		CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	}
	#elif ADC_PRESCALER == DIV_BY_32
	{
		SET_BIT(ADCSRA,  ADCSRA_ADPS2);
		CLR_BIT(ADCSRA,  ADCSRA_ADPS1);
		SET_BIT(ADCSRA,  ADCSRA_ADPS0);
	}
	#elif ADC_PRESCALER_SELECT == DIV_BY_64
	{
		SET_BIT(ADCSRA,  ADCSRA_ADPS2);
		SET_BIT(ADCSRA,  ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,  ADCSRA_ADPS0);
	}
	#elif ADC_PRESCALER == DIV_BY_128
	{
		SET_BIT(ADCSRA, ADCSRA_ADPS2);
		SET_BIT(ADCSRA, ADCSRA_ADPS1);
		SET_BIT(ADCSRA, ADCSRA_ADPS0);
	}
	#endif


	/* enable peripheral*/
	SET_BIT(ADCSRA , ADCSRA_ADEN);


	#if (ADC_CONVERSION==SINGLE_CONVERSION)
	/* disable interrupt */
	CLR_BIT(ADCSRA,ADCSRA_ADIE) ;
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
	
	#elif (ADC_CONVERSION==Auto_Trigger)
	/* enable interrupt */
	SET_BIT(ADCSRA,ADCSRA_ADIE) ;
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	 switch (ADC_AUTO_TRIG)
	 {
		 
		  case FREE_RUNNING:
		  CLR_BIT(SFIOR, SFIOR_ADTS0);
		  CLR_BIT(SFIOR, SFIOR_ADTS1);
		  CLR_BIT(SFIOR, SFIOR_ADTS2);
		  break;
		 case Analog_Comparator:
		 SET_BIT(SFIOR, SFIOR_ADTS0);
		 CLR_BIT(SFIOR, SFIOR_ADTS1);
		 CLR_BIT(SFIOR, SFIOR_ADTS2);
		 break;

		 case External_Interrupt:
		 SET_BIT(SFIOR, SFIOR_ADTS1);
		 break;

		 case Timer_0_Compare_Match:
		 SET_BIT(SFIOR, SFIOR_ADTS0);
		 SET_BIT(SFIOR, SFIOR_ADTS1);
		 CLR_BIT(SFIOR, SFIOR_ADTS2);
		 break;

		 case Timer_0_Compare_Overflow:
		 CLR_BIT(SFIOR, SFIOR_ADTS0);
		 CLR_BIT(SFIOR, SFIOR_ADTS1);
		 SET_BIT(SFIOR, SFIOR_ADTS2);
		 break;

		 case Timer_Compare_Match_B:
		 SET_BIT(SFIOR, SFIOR_ADTS0);
		 CLR_BIT(SFIOR, SFIOR_ADTS1);
		 SET_BIT(SFIOR, SFIOR_ADTS2);
		 break;

		 case Timer_1_Overflow:
		 CLR_BIT(SFIOR, SFIOR_ADTS0);
		 SET_BIT(SFIOR, SFIOR_ADTS1);
		 SET_BIT(SFIOR, SFIOR_ADTS2);
		 break;

		 case Timer_1_Capture_Event:
		 SET_BIT(SFIOR, SFIOR_ADTS0);
		 SET_BIT(SFIOR, SFIOR_ADTS1);
		 SET_BIT(SFIOR, SFIOR_ADTS2);
		 break;
	 }
 
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	#else
	#error "wrong conversion mode "
	#endif


}


u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16 *copy_puReading) {
	u32 Local_u32Counter = 0;
	u8 Local_u8ErrorState = OK;
	
	// Check if the ADC is not busy
	if (ADC_u8BusyState == IDLE) {
		// Clear the previous channel selection
		// Set the new channel to be converted
				ADMUX &= ADC_MUX_MUSK;
				ADMUX |= Copy_u8Channel;

		// Start the conversion by setting ADSC bit
        SET_BIT(ADCSRA, ADCSRA_ADSC);

		// Wait until the conversion is complete (ADIF becomes 1) or a timeout occurs
		while ((GET_BIT(ADCSRA, ADCSRA_ADIF) == 0) && (Local_u32Counter != ADC_u32TIMEOUT)) {
			Local_u32Counter++;
		}

		// Check if the timeout occurred
		if (Local_u32Counter == ADC_u32TIMEOUT) {
			// Timeout occurred, set error state to NOK
			Local_u8ErrorState = NOK;
			} else {
			// Conversion completed successfully, set ADC state to BUSY
			ADC_u8BusyState = BUSY;
			// Clear ADIF by writing one to it
            SET_BIT(ADCSRA, ADCSRA_ADIF);
		}

		#if (ADC_RESLETION == ADC_8BITS)
		// Read the result in 8-bit mode
		*copy_puReading = ADCH;
		ADC_u8BusyState = IDLE;
		#elif (ADC_RESLETION == ADC_10BITS)
		// Read the result in 10-bit mode
		*copy_puReading = ADC;
		ADC_u8BusyState = IDLE;
		#endif
		} else {
		// ADC is busy, set error state to BUSY_FUNC
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

 
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16 *Copy_Pu16Reading, void (*copy_pvNotificationFunc)(void)) {
	u8 Local_u8ErrorState = OK;
	
	
	
	// Check if the ADC is not busy
	if (ADC_u8BusyState == IDLE) {
		// Check if either the provided result pointer or notification function is NULL
		if ((Copy_Pu16Reading == NULL) || (copy_pvNotificationFunc == NULL)) {
			Local_u8ErrorState = NULL_POINTER;
			} else {
			ADC_u8ISRSource = SingleChannelAsync	;
			// Set the ADC state to BUSY
			ADC_u8BusyState = BUSY;
			
			// Store the provided result pointer and notification function as global variables
			ADC_pu16Reading = Copy_Pu16Reading;
			ADC_pvCallBackNotificationFunc = copy_pvNotificationFunc;
			
			// Clear the previous channel selection from ADMUX and set the new channel
		    ADMUX = (ADMUX & 0xF0) | (Copy_u8Channel);

			#if (ADC_CONVERSION == SINGLE_CONVERSION)
			// Start the conversion by setting ADSC bit
			SET_BIT(ADCSRA, ADCSRA_ADSC);
			// Enable ADC interrupt
			SET_BIT(ADCSRA, ADCSRA_ADIE);
			#endif
		}
		} else {
		// ADC is busy, set error state to BUSY_FUNC
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

 
u8 ADC_u8StartChainAsynch(Chain_t * Copy_Chain ){
	
	u8 Local_u8ErrorState = OK ; 
	

    if(Copy_Chain == NULL){
	 
	 	Local_u8ErrorState = NULL_POINTER ;
}
 	
if(ADC_u8BusyState == IDLE) {
	
	ADC_u8BusyState = BUSY ; 
	
	ADC_u8ISRSource = ChainChannelAsync ; 
	
    ADC_pu8ChainChannelArr= Copy_Chain->Channel ; 
	
	ADC_u8ChainSize = Copy_Chain->Size ; 
	
	ADC_pu16ChainResultArr = Copy_Chain->Result;
	
	ADC_pvCallBackNotificationFunc = Copy_Chain->NotificationFunc;
	
	ADC_u8ChainConverstionIndex =0 ; 
	
	
	ADMUX &= ADC_MUX_MUSK;
	ADMUX |= ADC_pu16ChainResultArr[ADC_u8ChainConverstionIndex];
	
	SET_BIT(ADCSRA,ADCSRA_ADSC) ; 
	 
	SET_BIT(ADCSRA,ADCSRA_ADIE) ;
}
	
else {
	
		 	Local_u8ErrorState = BUSY_FUNC ;
	  }	
	
	return Local_u8ErrorState ; 
}



 void __vector_16(void)  __attribute__((signal));
 void __vector_16(void)
 {
	 
if(ADC_u8ISRSource == SingleChannelAsync){
	 		#if (ADC_RESLETION == ADC_8BITS)
	 		// Read the result in 8-bit mode
	 		*ADC_pu16Reading = ADCH;
	 		ADC_u8BusyState = IDLE;
	 		#elif (ADC_RESLETION == ADC_10BITS)
	 		// Read the result in 10-bit mode
	 		*ADC_pu16Reading = ADC;
	 		ADC_u8BusyState = IDLE;
	 		#endif
		 if (ADC_pvCallBackNotificationFunc != NULL) {
			 ADC_pvCallBackNotificationFunc();
		 }
		 
		 /* Disable ADC Conversation Interrupt */ 
		 CLR_BIT(ADCSRA,ADCSRA_ADIE); 

 }
 
else if (ADC_u8ISRSource == ChainChannelAsync) 
{     
	 /* read the current conversation */ 
	 #if (ADC_RESLETION == ADC_8BITS)
	 ADC_pu16ChainResultArr[ADC_u8ChainConverstionIndex] = ADCH ; 
	 #elif (ADC_RESLETION == ADC_10BITS)
	 // Read the result in 10-bit mode
	 ADC_pu16ChainResultArr[ADC_u8ChainConverstionIndex] = ADC;
	 
	 #endif
	 /* increment index */ 
	 
	 ADC_u8ChainConverstionIndex++ ; 
	 
	 /*check finish or not */ 
	 
	 if(ADC_u8ChainConverstionIndex == ADC_u8ChainSize)
	 {
		 	ADC_u8BusyState = IDLE;
			
			/*Notification function */ 
			
			ADC_pvCallBackNotificationFunc() ;
		 
		 /* disable interrupt */ 
		  CLR_BIT(ADCSRA , ADCSRA_ADIE)	; 
	 }
	 else {
		 /* not finished */ 
		 
		 /* set new channal */ 
		 
		 
		 ADMUX &= ADC_MUX_MUSK;
		 ADMUX |= ADC_pu16ChainResultArr[ADC_u8ChainConverstionIndex];
		 
		 /* start new conversation */ 
		 
		 	SET_BIT(ADCSRA,ADCSRA_ADSC) ;

	 }
}

 }
 