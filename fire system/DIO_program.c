/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : DIO *************************************************/
/*************************** VERSION : 1.00 ********************************************/


#include "STD_type.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_privite.h"
#include "DIO_config.h"


u8 DIO_u8SetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{

u8 Local_u8ErrorState = 0 ;
 if (copy_u8Pin <= DIO_u8PIN7 ) {

 if(copy_u8Value == DIO_u8PIN_LOW ) {

switch( copy_u8Port ) {
	case  DIO_u8PORTA :  CLR_BIT(PORTA , copy_u8Pin ) ; break ;
	case  DIO_u8PORTB :  CLR_BIT(PORTB , copy_u8Pin ) ; break ;
	case  DIO_u8PORTC :  CLR_BIT(PORTC , copy_u8Pin ) ; break ;
	case  DIO_u8PORTD :  CLR_BIT(PORTD , copy_u8Pin ) ; break ;
default : Local_u8ErrorState = 1 ; break ;
}

 }
 else  if( copy_u8Value == DIO_u8PIN_HIGH ) {

switch( copy_u8Port ) {
	case  DIO_u8PORTA :  SET_BIT(PORTA , copy_u8Pin ) ; break ;
	case  DIO_u8PORTB  : SET_BIT(PORTB , copy_u8Pin ) ; break ;
	case  DIO_u8PORTC  : SET_BIT(PORTC , copy_u8Pin ) ; break ;
	case  DIO_u8PORTD  : SET_BIT(PORTD , copy_u8Pin ) ; break ;
default : Local_u8ErrorState = 1 ; break ;
}

 }
 else {
	 Local_u8ErrorState = 1 ;
 }
 }

return Local_u8ErrorState ;
}




u8 DIO_u8SetPortValue(u8 copy_u8Port, u8 copy_u8Value)
{
u8 Local_u8ErrorState = 0 ;

switch( copy_u8Port ) {
		case  DIO_u8PORTA  : PORTA = copy_u8Value  ; break ;
		case  DIO_u8PORTB  : PORTB = copy_u8Value  ; break ;
		case  DIO_u8PORTC  : PORTC = copy_u8Value; break ;
		case  DIO_u8PORTD  : PORTD = copy_u8Value ; break ;
		default : Local_u8ErrorState = 1 ; break ;
}
return Local_u8ErrorState ;

}




u8 DIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 *copy_pu8Value)
{

u8 Local_u8ErrorState = 0 ;

 if ( (copy_u8Pin <= DIO_u8PIN7 ) && ( copy_pu8Value != NULL  ) )  {
switch( copy_u8Port ) {
	case  DIO_u8PORTA  : *copy_pu8Value =   GET_BIT(PINA , copy_u8Pin ) ; break ;
	case  DIO_u8PORTB  : *copy_pu8Value =   GET_BIT(PINB , copy_u8Pin ) ; break ;
	case  DIO_u8PORTC  : *copy_pu8Value =   GET_BIT(PINC , copy_u8Pin ) ; break ;
	case  DIO_u8PORTD  : *copy_pu8Value =   GET_BIT(PIND , copy_u8Pin ) ; break ;

    default : Local_u8ErrorState = 1 ; break ;
}


 }
else {

		 Local_u8ErrorState = 1 ;


}

return Local_u8ErrorState ;

}
