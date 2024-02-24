/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : PORT *************************************************/
/*************************** VERSION : 1.00 ********************************************/




#include "STD_type.h"

#include "PORT_config.h"
#include "PORT_privite.h"
#include "PORT_interface.h"
#include "PORT_register.h"


void PORT_voidInit(void){
	
	DDRA =PORTA_DIR ; 
	DDRB =PORTB_DIR ;
	DDRC =PORTC_DIR ;
	DDRD =PORTD_DIR ;
	
	PORTA = PORTA_INT ;
	PORTB = PORTB_INT ;
	PORTC = PORTC_INT ;
	PORTD = PORTD_INT ;

}






