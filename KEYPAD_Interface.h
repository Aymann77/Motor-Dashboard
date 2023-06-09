/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL  			      ***************************/
/*************                SWC :     KEYPAD	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 18/9/2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KEYPAD_NO_PRESSED_KEY   0xff


/***************************************************************************************************************/
/***************************************************************************************************************/
/*****************      NAME : KEYPAD_voidInit             								  **********************/
/*****************      FUNCTION : INTIALIZATION FOR KEYPAD Pins Direction		          **********************/
/*****************      ARGUMENT : NO ARGUMENTS	(void)							          **********************/
/*****************      RETURN : NO RETURN (void) 										  **********************/
/***************************************************************************************************************/
/***************************************************************************************************************/
void KEYPAD_voidInit(void);




/**********************************************************************************************************************/
/**********************************************************************************************************************/
/*****************      NAME : KEYPAD_u8GetPressedKey             								 **********************/
/*****************      FUNCTION : Get Pressed Key From Keypad if nothing Pressed return (0xFF)  **********************/
/*****************      ARGUMENT : NO ARGUMENTS	(void)							          		 **********************/
/*****************      RETURN : Pressed Key      										  		 **********************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
u8 KEYPAD_u8GetPressedKey(void);



/**********************************************************************************************************************/
/**********************************************************************************************************************/
/*****************      NAME : KEYPAD_u8PollingUntilKeyPressed             						 **********************/
/*****************      FUNCTION : Polling in GetPressedKey Function Until User Press a Key      **********************/
/*****************      ARGUMENT : NO ARGUMENTS	(void)							          		 **********************/
/*****************      RETURN : Pressed Key 							     			  		 **********************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
u8 KEYPAD_u8PollingUntilKeyPressed(void);

#endif /* 2_HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
