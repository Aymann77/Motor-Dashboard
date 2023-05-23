/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   HAL  			      ***************************/
/*************                SWC :     CLCD	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 7/9/2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

/*Preprocessor file guard*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define SHIFT_LEFT  1
#define SHIFT_RIGHT 2

/***************************************************************************************************************/
/***************************************************************************************************************/
/*****************      NAME : CLCD_voidInit             								  **********************/
/*****************      FUNCTION : INTIALIZATION FOR CLCD		                          **********************/
/*****************      ARGUMENT : NO ARGUMENTS	(void)							          **********************/
/*****************      RETURN : NO RETURN (void) 										  **********************/
/***************************************************************************************************************/
/***************************************************************************************************************/
void CLCD_voidInit( void ) ;



/***************************************************************************************************************/
/***************************************************************************************************************/
/*****************      NAME : CLCD_voidSendCommand               						  **********************/
/*****************      FUNCTION : SEND COMMAND ON CLCD DATA PINS                         **********************/
/*****************      ARGUMENT : COMMAND TO SEND TO CLCD                                **********************/
/*****************      RETURN : NO RETURN (void) 									      **********************/
/***************************************************************************************************************/
/***************************************************************************************************************/
void CLCD_voidSendCommand( u8 Copy_u8Command ) ;



/***************************************************************************************************************/
/***************************************************************************************************************/
/*****************      NAME : CLCD_voidSendData               				    		  **********************/
/*****************      FUNCTION : SEND DATA ON CLCD DATA PINS                            **********************/
/*****************      ARGUMENT : DATA TO SEND TO CLCD                                   **********************/
/*****************      RETURN : NO RETURN (void) 									      **********************/
/***************************************************************************************************************/
/***************************************************************************************************************/
void CLCD_voidSendData( u8 Copy_u8Data ) ;



/***************************************************************************************************************/
/***************************************************************************************************************/
/*****************      NAME : CLCD_u8SendString               					     	  **********************/
/*****************      FUNCTION : SEND STRING OF DATA ON CLCD DATA PINS                  **********************/
/*****************      ARGUMENT : STRING OF DATA TO SEND TO CLCD                         **********************/
/*****************      RETURN : U8 ERROR STATE TO CHECK ON POINTER ( IF == NULL )        **********************/
/***************************************************************************************************************/
/***************************************************************************************************************/
u8 CLCD_u8SendString( const char *Copy_pcString ) ;



/**********************************************************************************************************************/
/**********************************************************************************************************************/
/*****************      NAME : CLCD_u8GoToRowColumn                  			     	         **********************/
/*****************      FUNCTION : GO TO CERTAIN DDRAM ADDRESS TO DISPLAY                        **********************/
/*****************      ARGUMENT : ROW POSITION , COLUMN POSITION                                **********************/
/*****************      RETURN : U8 ERROR STATE TO CHECK IF USER PUT THE RIGHT ROW ( 0 OR 1 )    **********************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
u8 CLCD_u8GoToRowColumn( u8 Copy_u8RowPos , u8 Copy_u8ColumnPos ) ;



/*****************************************************************************************************************************/
/*****************************************************************************************************************************/
/*****************      NAME : CLCD_voidWriteSpecialChar                  			                    **********************/
/*****************      FUNCTION : DISPLAY SPECIAL CHARACTER MADE BY USER ON DDRAM in certain position  **********************/
/*****************      ARGUMENT :  PATTERN NUMBER (0->7) , X Position , Y Position			            **********************/
/*****************      RETURN : NOTHING         											            **********************/
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/
void CLCD_voidWriteSpecialChar( u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos  );


/**************************************************************************************************************************/
/**************************************************************************************************************************/
/*****************      NAME : CLCD_u8StoreSpecialChar                  			                 **********************/
/*****************      FUNCTION : STORE SPECIAL CHARACTER IN CGRAM                                  **********************/
/*****************      ARGUMENT :  PATTERN NUMBER (0->7) , PATTERN IN FORM OF ARRAY		         **********************/
/*****************      RETURN : U8 ERROR STATE 											         **********************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/
u8 CLCD_u8StoreSpecialChar( u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber ) ;



/**************************************************************************************************************************/
/**************************************************************************************************************************/
/*****************      NAME : CLCD_voidWriteNumber                  			                     **********************/
/*****************      FUNCTION : DISPLAY NUMBER s32  , X POSITION , Y POSITION                         **********************/
/*****************      ARGUMENT : NUMBER TO DISPLAY                                                 **********************/
/*****************      RETURN : VOID            											         **********************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/
void CLCD_voidWriteIntegerNumber( s32 Copy_s32Number , u8 Copy_u8XPos , u8 Copy_u8YPos ) ;



/**************************************************************************************************************************/
/**************************************************************************************************************************/
/*****************      NAME : CLCD_voidClearScreen                  			                     **********************/
/*****************      FUNCTION : Clear LCD Screen								                     **********************/
/*****************      ARGUMENT : VOID                                                              **********************/
/*****************      RETURN : VOID            											         **********************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/
void CLCD_voidClearScreen( void ) ;



/**************************************************************************************************************************/
/**************************************************************************************************************************/
/*****************      NAME : CLCD_WriteFloatingNumber                  	                         **********************/
/*****************      FUNCTION : Display Floating Number						                     **********************/
/*****************      ARGUMENT : Floating Number , Expected Number of Digits after Decimal point   **********************/
/*****************                                  X Position , Y Position                          **********************/
/*****************      RETURN : VOID            											         **********************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/
void CLCD_WriteFloatingNumber( f32 Copy_f32Number , u8 Copy_u8NumberofDigitsAfterDecimal , u8 Copy_u8XPos , u8 Copy_u8YPos   ) ;



/**************************************************************************************************************************/
/**************************************************************************************************************************/
/*****************      NAME : CLCD_ShiftDisplay                  	                                 **********************/
/*****************      FUNCTION : Shift Entire Screen To Left Or To Right ( POST CONFIGURATION )    **********************/
/*****************      ARGUMENT : SHIFTING DIRECTION (  SHIFT_LEFT  OR  SHIFT_RIGHT  )              **********************/
/*****************      RETURN : U8 ERROR STATE VARIABLE           								     **********************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/
u8 CLCD_ShiftDisplay( u8 Copy_u8ShiftingDirection );

/*Service Function*/
s32 Power ( u8 Base , u16 Power );

#endif /* 2_HAL_CLCD_CLCD_INTERFACE_H_ */
