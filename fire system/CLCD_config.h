/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : HAL **********************************************/
/***************************  CLCD *************************************************/
/*************************** VERSION : 1.00 ********************************************/


#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_


/*Config Data & control Ports And Bins
===========================
        PORT OPTIONS 
===========================
1- DIO_PORTA
2- DIO_PORTB
3- DIO_PORTC
4- DIO_PORTD
===========================
        PINS OPTIONS
===========================
1- DIO_PIN0
2- DIO_PIN1
3- DIO_PIN2
4- DIO_PIN3
5- DIO_PIN4
6- DIO_PIN5
7- DIO_PIN6
8- DIO_PIN7
*/


/* choose CLCD_FOUR_BIT_ModE  , CLCD_EIGHT_BIT_ModE  */


#define  CLCD_MODE    CLCD_FOUR_BIT_ModE



	
#define CLCD_DATA_PORT		 DIO_u8PORTA
#define CLCD_DATA_PIN1       DIO_u8PIN3
#define CLCD_DATA_PIN2       DIO_u8PIN4
#define CLCD_DATA_PIN3       DIO_u8PIN5
#define CLCD_DATA_PIN4       DIO_u8PIN6


//#endif



#define CLCD_CTRL_PORT		DIO_u8PORTA
#define CLCD_RS_PIN			DIO_u8PIN1
#define CLCD_RW_PIN			DIO_u8PIN7
#define CLCD_E_PIN			DIO_u8PIN2


#endif







