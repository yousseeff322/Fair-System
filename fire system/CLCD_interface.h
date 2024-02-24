#include "STD_type.h"

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


/* Function to send a command to the LCD */
void CLCD_voidSendCommand(u8 Copy_u8Command);

/* Function to send data to display on the LCD */
void CLCD_voidSendData(u8 Copy_u8Data);

/* Initialize the LCD */
void CLCD_voidInit(void);

/* Function to send a string to be displayed on the LCD */
void CLCD_voidSendString(const char *Copy_pcString);

/* Set the cursor position on the LCD */
void CLCD_voidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

/* Clear the LCD display */
void CLCD_VidDisplayClear(void);

/* Write a special custom character to the LCD */
void CLCD_voidWriteSpecialCharacter(u8 *Copy_pu8Pattern, u8 PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);

/* Write a number to the LCD */
void CLCD_voidWriteNumber(s32 Copy_s32Number);

/* Write a floating-point number to the LCD with specified decimal places */
void CLCD_voidWriteFloat(float Copy_f32Number, u8 decimalPlaces);

#endif /* CLCD_INTERFACE_H_ */
