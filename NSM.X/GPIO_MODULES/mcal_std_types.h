 /* 
 * File:   mcal_std_types.h
 * Author: Mohamed Samy
 *
 * Created on March 19, 2024, 8:55 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*Include Section*/
#include "std_libraries.h"
#include "compiler.h"


/*Macros Function Declarations Section*/



/*Data Type Function Declarations Section*/
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long   uint32;
typedef signed char    sint8;
typedef signed short   sint16;
typedef signed long     sint32;

typedef uint8 Std_ReturnType;



/*Macros Declarations Section*/

#define E_OK        (Std_ReturnType)0x00
#define E_NOK       (Std_ReturnType)0x01

#define STD_HIGH    0x01
#define STD_LOW     0x00

#define STD_ACTIVE  0x01
#define STD_IDLE    0x00

#define STD_ON      0x01
#define STD_OFF     0x00

#define ZERO_INIT   0X00

/*Function Declarations Section*/



#endif	/* MCAL_STD_TYPES_H */

