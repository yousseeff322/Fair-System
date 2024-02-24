/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : HAL **********************************************/
/*************************** SWC : KEYPAD *************************************************/
/*************************** VERSION : 1.00 ********************************************/

#include "STD_type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_privite.h"


u8 KEYPAD_u8GetPressKEY(void){
	
	u8 Local_u8PressKey= KEYPAD_NO_PRESSED_KEY  ,Local_u8ColumeIndex , Local_u8RowIndex  , Local_u8PinState ; 
static 	u8 Local_u8KAYPADArr[4][4]=KPD_ARR_VAL ;  
static 	u8 Local_u8KEYPADColumeArr [COLUME_NUM] = {KEYPAD_COLUME0_PIN,KEYPAD_COLUME1_PIN,KEYPAD_COLUME2_PIN,KEYPAD_COLUME3_PIN} ;
static 	u8 Local_u8KEYPADRowArr [ROW_NUM] = {KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};
		
		
	for (Local_u8ColumeIndex =0 ; Local_u8ColumeIndex<COLUME_NUM;Local_u8ColumeIndex++)	{
		
		/* Active Current column */ 
		DIO_u8SetPinValue(KEY_COULMES,Local_u8KEYPADColumeArr[Local_u8ColumeIndex] , DIO_u8PIN_LOW) ;
		
		for(Local_u8RowIndex =0; Local_u8RowIndex < ROW_NUM ; Local_u8RowIndex++ )
		{
			/* Read current row */ 
			DIO_u8GetPinValue(KEY_ROWS,Local_u8KEYPADRowArr[Local_u8RowIndex] ,&Local_u8PinState) ;
			
			/* check switch */
			if (DIO_u8PIN_LOW == Local_u8PinState ) {
				
				Local_u8PressKey = Local_u8KAYPADArr[Local_u8RowIndex][Local_u8ColumeIndex] ;
				 
				 while (DIO_u8PIN_LOW == Local_u8PinState ){
					 
					DIO_u8GetPinValue(KEY_ROWS,Local_u8KEYPADRowArr[Local_u8RowIndex] ,&Local_u8PinState) ;

					 
				 }
				
								 return Local_u8PressKey ;
 
			}
			
		}
		/*deactive */ 
		
				DIO_u8SetPinValue(KEY_COULMES,Local_u8KEYPADColumeArr[Local_u8ColumeIndex] , DIO_u8PIN_HIGH) ;

	}
	
	
	
	
	return Local_u8PressKey ;
	
}








