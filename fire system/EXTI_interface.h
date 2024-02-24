/***************************************************************************************/
/***************************************************************************************/
/***************************  YOUSSEF **************************************************/
/*************************** LAYER : MCAL **********************************************/
/*************************** SWC : EXTI *************************************************/
/*************************** VERSION : 1.00 ********************************************/



#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL		  1
#define ON_CHANGE		  2
#define FALLING_EDGE	  3
#define RISING_EDGE		  4

#define INT0  1
#define INT1  2
#define INT2  3

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);


/* Description Function to set the reuired sense control of INT0 using postbuild */ 

/* INPUT :  Copy_u8 sense 1- LOW_LEVEL
				          2- ON_CHANGE
						  3- FALLING_EDGE
						  4- RISING_EDGE 
				 */ 
u8 EXTI_u8Int0SetSenseControl(u8 copy_u8Sense) ;
/* Description Function to set the reuired sense control of INT1 using postbuild */ 

/* INPUT :  Copy_u8 sense 1- LOW_LEVEL
						  2- ON_CHANGE
						  3- FALLING_EDGE
						  4- RISING_EDGE 
				 */ 
u8 EXTI_u8Int1SetSenseControl(u8 copy_u8Sense) ;
/* Description Function to set the reuired sense control of INT2 using postbuild */ 

/* INPUT :  Copy_u8 sense 
				 1- FALLING_EDGE
				 2- RISING_EDGE 
				 */ 
u8 EXTI_u8Int2SetSenseControl(u8 copy_u8Sense) ;
/* Description Function to set the reuired enable control using postbuild */ 

/* INPUT :  Copy_u8 sense 
				 1- INT0
				 2-INT1 
				 3-INT2
				 */

u8 EXIT_u8IntEnable(u8 copy_u8Int);
/* Description Function to set the reuired disable control using postbuild */ 

/* INPUT :  Copy_u8 sense 
				 1- INT0
				 2-INT1 
				 3-INT2
				 */


u8 EXIT_u8IntDisable(u8 copy_u8Int);


u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func) (void));

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt0Func) (void));

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt0Func) (void));


     
#endif