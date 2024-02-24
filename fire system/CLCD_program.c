/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : HAL **********************************************/
/***************************  CLCD *************************************************/
/*************************** VERSION : 1.00 ********************************************/


#include "STD_type.h" 
#include "BIT_math.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_privite.h"

void CLCD_voidSendCommand(u8 Copy_u8Command){
	
	/*set RS , RW low to send command*/
#if CLCD_MODE==CLCD_EIGHT_BIT_ModE
	{
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_LOW) ; 
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW) ;
	DIO_u8SetPortValue(CLCD_DATA_PORT ,Copy_u8Command );
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH) ;
    _delay_ms(3);
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW) ;
	
}
#elif   CLCD_MODE==CLCD_FOUR_BIT_ModE
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_LOW) ;
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW) ;
	
	DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN1 , GET_BIT(Copy_u8Command,4)) ;
	DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN2 , GET_BIT(Copy_u8Command,5)) ;
	DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN3 , GET_BIT(Copy_u8Command,6)) ;
	DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN4 , GET_BIT(Copy_u8Command,7)) ;

	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH) ;
	_delay_ms(3);
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW) ;
	
	
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN1 , GET_BIT(Copy_u8Command,0)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN2 , GET_BIT(Copy_u8Command,1)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN3 , GET_BIT(Copy_u8Command,2)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN4 , GET_BIT(Copy_u8Command,3)) ;

		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH) ;
		_delay_ms(3);
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW) ;
	
}
#endif

}




void CLCD_voidSendData(u8 Copy_u8Data){
	#if CLCD_MODE==CLCD_EIGHT_BIT_ModE
	{
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_HIGH) ;
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW) ;
		DIO_u8SetPortValue(CLCD_DATA_PORT ,Copy_u8Data );
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH) ;
		_delay_ms(3);
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW) ;
		
	}
	#elif   CLCD_MODE==CLCD_FOUR_BIT_ModE
	{
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_HIGH) ;
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW) ;
		
		
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN1 , GET_BIT(Copy_u8Data,4)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN2 , GET_BIT(Copy_u8Data,5)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN3 , GET_BIT(Copy_u8Data,6)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN4 , GET_BIT(Copy_u8Data,7)) ;

		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH) ;
		_delay_ms(3);
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW) ;
		
		
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN1 , GET_BIT(Copy_u8Data,0)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN2 , GET_BIT(Copy_u8Data,1)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN3 , GET_BIT(Copy_u8Data,2)) ;
		DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN4 , GET_BIT(Copy_u8Data,3)) ;

		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH) ;
		_delay_ms(3);
		DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW) ;
		
	}
#endif

}



void CLCD_voidInit(void){
	
	#if CLCD_MODE==CLCD_EIGHT_BIT_ModE
{
	_delay_ms(40); 
	CLCD_voidSendCommand(0x38); /*two line font 5*8   function set */
	CLCD_voidSendCommand(0x0C);   /* Display On / off control  Display enable Cursor and Blink Cursor are disable */
	CLCD_voidSendCommand(0x01);    /* Display Clear */ 
}
#elif CLCD_MODE==CLCD_FOUR_BIT_ModE 
{
	
_delay_ms(40);

DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN1 ,0 ) ;
DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN2 ,1 ) ;
DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN3 , 0) ;
DIO_u8SetPinValue(CLCD_DATA_PORT , CLCD_DATA_PIN4 , 0) ;

	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH) ;
	_delay_ms(3);
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW) ;

CLCD_voidSendCommand(0x28); /*two line font 5*8   function set */
CLCD_voidSendCommand(0x0c);	/* Display On / off control  Display enable Cursor and Blink Cursor are disable */
CLCD_voidSendCommand(0x01);    /* Display Clear */


}
	
#endif
	
}



void CLCD_voidSendString( const char *Copy_pcString)
{
u8 Local_u8Counter =0 ; 

while (Copy_pcString[Local_u8Counter]!= '\0' ) {
	
	CLCD_voidSendData(Copy_pcString[Local_u8Counter]) ; 
	Local_u8Counter++ ; 
    _delay_ms(1);

}
	
	 
}




void CLCD_voidGotoXY(u8 Copy_u8XPos , u8 Copy_u8YPos){
	u8 Local_u8Adress =0 ;
	/* frist line */ 
	if(Copy_u8XPos == 0){
	Local_u8Adress = Copy_u8YPos ; 
	}
	/*second line */ 

	else if (Copy_u8XPos == 1) {
			Local_u8Adress = Copy_u8YPos+40 ;

	}
	else if (Copy_u8XPos == 2) {
			Local_u8Adress = Copy_u8YPos+80 ;

	}
	
	CLCD_voidSendCommand(Local_u8Adress + 128 ) ; 
}


void CLCD_voidWriteSpecialCharacter(u8 *Copy_pu8Pattern , u8 PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos ) {
	
	u8 Local_u8CGRAMAdress=0  , Local_u8Iterator; 
	
	Local_u8CGRAMAdress = PatternNumber * 8 ; 
	
	CLCD_voidSendCommand(Local_u8CGRAMAdress + 64 ) ; 
	/* write pattern in CGRAM */ 
	for (Local_u8Iterator =0 ; Local_u8Iterator < 8 ; Local_u8Iterator++ ){
		
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]) ; 
		
	}
	/* send to DDRAM */ 
	CLCD_voidGotoXY(Copy_u8XPos , Copy_u8YPos) ; 
	
	CLCD_voidSendData(PatternNumber) ; 
	
}




void CLCD_voidWriteNumber(s32 Copy_s32Number){
	if (Copy_s32Number > 2147483647) {
		Copy_s32Number = 2147483647;
		} else if (Copy_s32Number < -2147483648) {
		Copy_s32Number = -2147483648;
	}


	// Handle negative numbers
	if (Copy_s32Number < 0) {
		CLCD_voidSendData('-');
		Copy_s32Number = -Copy_s32Number;
		} else {
		CLCD_voidSendData(' ');
	}

	// Flag to indicate if the first non-zero digit has been found
	u8 nonZeroFound = 0;

	// Loop through each digit's place value
	for (s32 digitPlace = 1000000000; digitPlace > 0; digitPlace /= 10) {
		s32 digit = (Copy_s32Number / digitPlace) % 10;

		if (digit != 0 || nonZeroFound) {
			CLCD_voidSendData('0' + digit);
			nonZeroFound = 1;
			} else if (digitPlace == 1) {
			// Display at least the least significant digit if it's zero
			CLCD_voidSendData('0');
		}
	}
}


void CLCD_VidDisplayClear(void)
{
	CLCD_voidSendCommand(0x01);

	_delay_ms(3);
}	










void CLCD_voidWriteFloat(float Copy_f32Number, u8 decimalPlaces) {
    // Handle negative numbers
    if (Copy_f32Number < 0) {
        CLCD_voidSendData('-');
        Copy_f32Number = -Copy_f32Number;
    } else {
        CLCD_voidSendData(' ');
    }

    // Display the integer part
    s32 integerPart = (s32)Copy_f32Number;
    CLCD_voidWriteNumber(integerPart);

    // Display the decimal point
    CLCD_voidSendData('.');

    // Extract the fractional part
    float fractionalPart = Copy_f32Number - (float)integerPart;

    // Display the decimal places
    for (u8 i = 0; i < decimalPlaces; i++) {
        fractionalPart *= 10.0;
        s32 digit = (s32)fractionalPart;
        CLCD_voidSendData('0' + digit);
        fractionalPart -= (float)digit;
    }
}


