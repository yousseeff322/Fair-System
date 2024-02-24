/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : EXTI *************************************************/
/*************************** VERSION : 1.00 ********************************************/

#include "STD_type.h"
#include "BIT_math.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

/* Global pointer to function to hold INT0 ISR address */ 
void (*EXTI_pvInt0Func)(void) = NULL ; 
/* Global pointer to function to hold INT1 ISR address */
void (*EXTI_pvInt1Func)(void) = NULL ;
/* Global pointer to function to hold INT2 ISR address */
void (*EXTI_pvInt2Func)(void) = NULL ;


void EXTI_voidInt0Init(void){
	
/* check sense */ 


	/*set sense control INT0
	
	ISC01 ISC00             Description
	0       0               The low level of INT0        
	0       1               Any logical change on INT0   
	1       0               The falling edge of INT0     
	1       1               The rising edge of INT0
	
	 */ 

	#if INT0_SENSE ==LOW_LEVEL
		CLR_BIT(MCUCR , MCUCR_ISC01);
		CLR_BIT(MCUCR , MCUCR_ISC00);
		
	#elif INT0_SENSE ==ON_CHANGE 
	
		CLR_BIT(MCUCR , MCUCR_ISC01);
		SET_BIT(MCUCR , MCUCR_ISC00);

	
	#elif INT0_SENSE ==FALLING_EDGE
	
	SET_BIT(MCUCR , MCUCR_ISC01);
	CLR_BIT(MCUCR , MCUCR_ISC00);
	
			
	#elif INT0_SENSE ==RISING_EDGE
			
	SET_BIT(MCUCR , MCUCR_ISC01);
	SET_BIT(MCUCR , MCUCR_ISC00);
						
	#else 
		#error  "wrong INT0_SENSE CONFIG OPTION "
		
#endif

	#if INT0_INITIAL_SENSE ==ENABLED
		SET_BIT(GICR,GICR_INT0);
		
	#elif INT0_INITIAL_SENSE ==DISABLED
	CLR_BIT(GICR,GICR_INT0);
	
#else
#error  "wrong INT0_INITIAL_SENSE CONFIG OPTION "

#endif
	
}



void EXTI_voidInt1Init(void){


/* check sense */

	/*
	 set sense control INT1
  ISC11   ISC10    Description
	0      0       The low level of INT1      
	0      1       Any logical change on INT1 
	1      0       The falling edge of INT1   
	1      1       The rising edge of INT1    
	*/

#if INT1_SENSE ==LOW_LEVEL
CLR_BIT(MCUCR , MCUCR_ISC11);
CLR_BIT(MCUCR , MCUCR_ISC10);

#elif INT1_SENSE ==ON_CHANGE
CLR_BIT(MCUCR , MCUCR_ISC11);
SET_BIT(MCUCR , MCUCR_ISC10);


#elif INT1_SENSE ==FALLING_EDGE
SET_BIT(MCUCR , MCUCR_ISC11);
CLR_BIT(MCUCR , MCUCR_ISC10);


#elif INT1_SENSE ==RISING_EDGE

SET_BIT(MCUCR , MCUCR_ISC11);
SET_BIT(MCUCR , MCUCR_ISC10);

#else
#error  "wrong INT1_SENSE CONFIG OPTION "

#endif


#if INT1_INITIAL_SENSE ==ENABLED
	SET_BIT(GICR,GICR_INT1);

#elif INT1_INITIAL_SENSE ==DISABLED
    CLR_BIT(GICR,GICR_INT1);


#else
#error  "wrong INT1_INITIAL_SENSE CONFIG OPTION "

#endif

}







void EXTI_voidInt2Init(void){

#if INT2_SENSE ==RISING_EDGE

	    SET_BIT(MCUCSR ,MCUCSR_INT2 );


#elif INT2_SENSE ==FALLING_EDGE
	    CLR_BIT(MCUCSR ,MCUCSR_INT2 );
		
		
#else
#error  "wrong INT2_SENSE CONFIG OPTION "

#endif


#if INT2_INITIAL_SENSE ==ENABLED
SET_BIT(GICR,GICR_INT2);

#elif INT2_INITIAL_SENSE ==DISABLED
CLR_BIT(GICR,GICR_INT2);

#else
#error  "wrong INT2_INITIAL_SENSE CONFIG OPTION "

#endif


}

u8 EXTI_u8Int0SetSenseControl(u8 copy_u8Sense) {
	
	u8 Local_u8ErrorState = OK ;        

	switch (copy_u8Sense){
		case LOW_LEVEL  : CLR_BIT(MCUCR , MCUCR_ISC01);CLR_BIT(MCUCR , MCUCR_ISC00);break ;
		case FALLING_EDGE  :SET_BIT(MCUCR , MCUCR_ISC01);CLR_BIT(MCUCR , MCUCR_ISC00);break ;
		case ON_CHANGE  :CLR_BIT(MCUCR , MCUCR_ISC01);SET_BIT(MCUCR , MCUCR_ISC00);break ;
		case RISING_EDGE  :SET_BIT(MCUCR , MCUCR_ISC01);SET_BIT(MCUCR , MCUCR_ISC00);break ;
		default: Local_u8ErrorState =NOK ;break;
	}
	return Local_u8ErrorState ;
	
}

u8 EXTI_u8Int1SetSenseControl(u8 copy_u8Sense) {
	
u8 Local_u8ErrorState = OK ; 	
	
	switch (copy_u8Sense){
	case LOW_LEVEL  : CLR_BIT(MCUCR , MCUCR_ISC11);CLR_BIT(MCUCR , MCUCR_ISC10);break ; 
	case FALLING_EDGE  :SET_BIT(MCUCR , MCUCR_ISC11);CLR_BIT(MCUCR , MCUCR_ISC10);break ;
	case ON_CHANGE  :CLR_BIT(MCUCR , MCUCR_ISC11);SET_BIT(MCUCR , MCUCR_ISC10);break ;
	case RISING_EDGE  :SET_BIT(MCUCR , MCUCR_ISC11);SET_BIT(MCUCR , MCUCR_ISC10);break ;
	default: Local_u8ErrorState =NOK ;break;
	}
	return Local_u8ErrorState ; 
}


u8 EXTI_u8Int2SetSenseControl(u8 copy_u8Sense) {
	
	u8 Local_u8ErrorState = OK ;

	switch (copy_u8Sense){
		case FALLING_EDGE  : CLR_BIT(MCUCSR ,MCUCSR_INT2 );break ;
		case RISING_EDGE  :	 SET_BIT(MCUCSR ,MCUCSR_INT2 );break ;
		default: Local_u8ErrorState =NOK ;break;
	}
	return Local_u8ErrorState ;
	
}



u8 EXIT_u8IntEnable(u8 copy_u8Int){
		u8 Local_u8ErrorState = OK ;

		switch (copy_u8Int){
			case INT0 :SET_BIT(GICR,GICR_INT0);break;
			case INT1 :SET_BIT(GICR,GICR_INT1);break;
			case INT2 :SET_BIT(GICR,GICR_INT2);break;
		    default: Local_u8ErrorState =NOK ;break;
	
		}
			return Local_u8ErrorState ;

}
u8 EXIT_u8IntDisable(u8 copy_u8Int){
	
			u8 Local_u8ErrorState = OK ;

			switch (copy_u8Int){
				case INT0 :CLR_BIT(GICR,GICR_INT0);break;
				case INT1 :CLR_BIT(GICR,GICR_INT1);break;
				case INT2 :CLR_BIT(GICR,GICR_INT2);break;
				default: Local_u8ErrorState =NOK ;break;
				
			}
			return Local_u8ErrorState ;
}




u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func) (void)){
	u8 Local_u8ErrorState = OK ;
if(Copy_pvInt0Func != NULL){
	EXTI_pvInt0Func = Copy_pvInt0Func ; 
}
else {
	Local_u8ErrorState = NULL_POINTER ; 
	}
			return Local_u8ErrorState ;
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvInt0Func != NULL) {
	EXTI_pvInt0Func() ; 
}
 else {
	 
 }
}



u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func) (void)){
	u8 Local_u8ErrorState = OK ;
	if(Copy_pvInt1Func != NULL){
		EXTI_pvInt1Func = Copy_pvInt1Func ;
	}
	else {
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pvInt1Func != NULL) {
		EXTI_pvInt1Func() ;
	}
	else {
		
	}
}

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func) (void)){
	u8 Local_u8ErrorState = OK ;
	if(Copy_pvInt2Func != NULL){
		EXTI_pvInt2Func = Copy_pvInt2Func ;
	}
	else {
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pvInt2Func != NULL) {
		EXTI_pvInt2Func() ;
	}
	else {
		
	}
}

