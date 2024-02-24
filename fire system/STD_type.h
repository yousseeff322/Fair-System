#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;



#define OK   1
#define NOK  0
#define NULL_POINTER  2
#define BUSY_FUNC  3


/* Error status */
#define STATUS_OK (u8)0
#define STATUS_ERROR (u8)1

/* Boolean type */
#define TRUE 1
#define FALSE 0

/* Macro for NULL */
#define NULL ((void *)0)





#define NULL_PTR_ERR	2u

#endif
