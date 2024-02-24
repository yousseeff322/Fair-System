#include "STD_type.h"
#include "BIT_math.h"
#include <util/delay.h>
#include "KEYPAD_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"
#include "PORT_interface.h"
#include "sensor.h"

void main(void) {
	PORT_voidInit();
	CLCD_voidInit();
	ADC_voidInt();

	u16 ADCValue = 0 , gasValue , LPG  , temp ; // Declare variable to hold MQ-5 gas sensor value

	u8 PressedKey=0xff ;
	CLCD_voidGotoXY(0, 0);
	CLCD_voidSendString("Welcome Dr Abeer") ;
	_delay_ms(2000);
	CLCD_VidDisplayClear();
	CLCD_voidGotoXY(0, 0);
	CLCD_voidSendString("press to measure  ") ;
	CLCD_voidGotoXY(1, 0);
	CLCD_voidSendString("1-Gas  2-temperature ") ;
	_delay_ms(1000);


	while (1) {
		DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_LOW);


		PressedKey = KEYPAD_u8GetPressKEY();

		if (PressedKey != 0xff) {

			if(PressedKey == '1' ){

				CLCD_VidDisplayClear();

				while (1){


					PressedKey = KEYPAD_u8GetPressKEY();
					if(PressedKey == '0' ){

						break ;
					}


					if (ADC_u8StartConversionSynch(0, &ADCValue) == OK) {
						// Perform calculations or processing based on the sensor values
						// You may need to convert the gas sensor ADC value to meaningful data based on sensor specifications


						gasValue= ConvertToGasConcentration(ADCValue) ;

						LPG =  (u16) ConvertToLPG( (u16)gasValue) ;

						// Display the gas sensor value on the LCD
						CLCD_voidGotoXY(0, 0);
						CLCD_voidSendString("Gas Value: ");
						CLCD_voidSendString("   ");
						CLCD_voidGotoXY(0, 12);
						CLCD_voidWriteFloat(gasValue , 2 ); // Display gas sensor ADC value




						// Add necessary delay before the next reading
					}



					if  (    (gasValue >=40) || (LPG >= 40)   ) {
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_LOW);

					}
					else if (   (   (gasValue >= 10)  &&   (gasValue < 40)    ) || (  (LPG >= 10)  &&  (LPG < 40)  )    ) {
						// Set LED pin high
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_HIGH);

					} else  if (    (gasValue <=10) || (LPG <= 10)   ) {
						// Set LED pin low if the temperature falls below 10°C
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_LOW);

					}
				}
			}
			else 	if(PressedKey == '2' ){

				CLCD_VidDisplayClear();

				while (1){

					PressedKey = KEYPAD_u8GetPressKEY();
					if(PressedKey == '0' ){

						break ;
					}


					if (ADC_u8StartConversionSynch(7, &ADCValue) == OK) {
						// Perform calculations or processing based on the sensor values
						// You may need to convert the gas sensor ADC value to meaningful data based on sensor specifications


						temp= ConvertToTemp(ADCValue) ;

						// Display the gas sensor value on the LCD
						CLCD_voidGotoXY(0, 0);
						CLCD_voidSendString("Temperature: ");
						CLCD_voidSendString("   ");
						CLCD_voidGotoXY(0, 13);
						CLCD_voidWriteNumber(temp); // Display Temperature sensor ADC value
					}



					if  (    (temp >=40)   ) {
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_LOW);

					}
					else if (   (   (temp >= 10)  &&   (temp < 40)    )    ) {
						// Set LED pin high
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_HIGH);

					} else  if (    (temp <=10)   ) {
						// Set LED pin low if the temperature falls below 10°C
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_LOW);

					}
				}
			}
			else {
				CLCD_voidGotoXY(0, 0);
				CLCD_voidSendString("ERROR CHOISE ") ;
				_delay_ms(2000);
				CLCD_VidDisplayClear();


			}

		}

	}
}
