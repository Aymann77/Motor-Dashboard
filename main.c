/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: moham
 */

#include "STD_TYPES.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "CLCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "STEPPER_Interface.h"
#include "DCMOTOR_Interface.h"

/* USED PINS IN MC:
 *         PORTD ----> LCD DATA PINS
 *         C0,C1,C2--> LCD CTRL PINS
 *         PORTA ----> KEYPAD PINS
 *                                                  */

u8 HamokshaUpperNormal[]= {	0b00100,	0b01110,	0b10101,0b01110,0b00100,0b00100,0b01110,0b10101};
u8 HamokshaLowerNormal[]={	0b00100,0b00100,0b00100,0b01010,0b10001,0b00000,0b00000,0b00000};
u8 HamokshaLowerRun[]={0b00100,0b00101,0b00110,0b01000,0b10000,0b00000,0b00000,	0b00000	};
u8 HamokshaUpperRun[]={0b00100,0b01110,	0b10101,	0b01110,0b00100,0b00101,	0b01110,	0b10100	};

void Moving( u8 Copy_u8UpperNormalPatternNumber , u8 Copy_u8LowerNormalPatternNumber ) ;

u16 p( u8 Base , u8 power ) ;
u32 Angle( void );

void main( void )
{
	u8 Pressed_Key = KEYPAD_NO_PRESSED_KEY ;
	u8 Motor_Option , Stepper_Option ;

	u32 StepperAngle = 0  ;
	f32 Angleee = 0 ;

	u8 Degree[]={0b01000,0b10100,0b01000,0b00000,0b00000,0b00000,	0b00000,0b00000};

	CLCD_voidInit();
	KEYPAD_voidInit();
	STEPPER_Init( DIO_u8PORTC , DIO_u8Pin3 , DIO_u8Pin4 , DIO_u8Pin5 , DIO_u8Pin6 ) ;
	DCMOTOR_voidInit( DIO_u8PORTB , DIO_u8Pin0 , DIO_u8Pin1 ) ;

	CLCD_u8StoreSpecialChar( HamokshaUpperNormal , 0 ) ;
	CLCD_u8StoreSpecialChar( HamokshaUpperRun    , 1 ) ;
	CLCD_u8StoreSpecialChar( HamokshaLowerNormal , 2 ) ;
	CLCD_u8StoreSpecialChar( HamokshaLowerRun    , 3 ) ;

	CLCD_u8StoreSpecialChar( Degree    , 4 ) ;

	again:

	StepperAngle = 0 ;
	Pressed_Key = KEYPAD_NO_PRESSED_KEY ;

	CLCD_voidClearScreen();
	Moving( 0 , 2 );
	CLCD_voidClearScreen();

	CLCD_u8GoToRowColumn(0,0);
	CLCD_u8SendString("Welcome to Motor");
	CLCD_u8GoToRowColumn( 1, 0 );
	CLCD_u8SendString("Dash board APP");
	_delay_ms(1500);

	CLCD_u8GoToRowColumn(0,0);
	CLCD_u8SendString("For DC Motor-> 1");
	CLCD_u8GoToRowColumn( 1, 0 );
	CLCD_u8SendString("For Stepper -> 2");

	Pressed_Key = KEYPAD_u8PollingUntilKeyPressed() ;

	if( Pressed_Key == 1 ) /*DC MOTOR */
	{
		CLCD_voidClearScreen();
		CLCD_u8GoToRowColumn(0,0);
		CLCD_u8SendString( "CW-->1   CCW-->2" );
		CLCD_u8GoToRowColumn(1,0);
		CLCD_u8SendString("Exit-->3") ;

		Motor_Option = KEYPAD_u8PollingUntilKeyPressed() ;
		_delay_ms(500);
		CLCD_voidClearScreen();
		switch( Motor_Option )
		{
		case 1 :
			DCMOTOR_voidRotateCW( DIO_u8PORTB , DIO_u8Pin0 , DIO_u8Pin1 ) ;
			CLCD_u8GoToRowColumn(0,0);
			CLCD_u8SendString("       CW");
			CLCD_u8GoToRowColumn(1,0);
			CLCD_u8SendString("Any Key To Stop") ;
			break;
		case 2 : DCMOTOR_voidRotateCCW(DIO_u8PORTB , DIO_u8Pin0 , DIO_u8Pin1 ) ;
		CLCD_u8GoToRowColumn(0,0);
		CLCD_u8SendString("      CCW");
		CLCD_u8GoToRowColumn(1,0);
		CLCD_u8SendString("Any Key To Stop") ;
		break;
		case 3 : DCMOTOR_voidTurnOFF(DIO_u8PORTB , DIO_u8Pin0 , DIO_u8Pin1);
		while(1);
		break;
		}
		KEYPAD_u8PollingUntilKeyPressed();   /*if user pressed any key it will start again*/
		 DCMOTOR_voidTurnOFF(DIO_u8PORTB , DIO_u8Pin0 , DIO_u8Pin1);


	}

	else if( Pressed_Key == 2 ) /*STEPPER*/
	{
		CLCD_voidClearScreen();
		CLCD_u8GoToRowColumn(0,0);
		CLCD_u8SendString( "CW-->1   CCW-->2" );
		CLCD_u8GoToRowColumn(1,0);
		CLCD_u8SendString("Exit-->3") ;


	Stepper_Option = KEYPAD_u8PollingUntilKeyPressed() ;
	_delay_ms(500);
	CLCD_voidClearScreen();
	switch( Stepper_Option )
	{
	case 1 :
		CLCD_u8GoToRowColumn(0,0);
		CLCD_u8SendString("Select angle:");

		StepperAngle = Angle();

		Angleee = StepperAngle / 0.17578 ;
		Angleee /= 4 ;
		STEPPER_GoBackward( DIO_u8PORTC , DIO_u8Pin3 , DIO_u8Pin4 , DIO_u8Pin5 , DIO_u8Pin6 , (u32)Angleee ) ;
		CLCD_voidClearScreen();
		CLCD_u8SendString("Angle Reached");
		_delay_ms(2000);
		break;
	case 2 :

		CLCD_u8GoToRowColumn(0,0);
		CLCD_u8SendString("Select angle:");
		StepperAngle = Angle();

		Angleee = StepperAngle / 0.17578 ;
		Angleee /= 4 ;
		STEPPER_GoForward( DIO_u8PORTC , DIO_u8Pin3 , DIO_u8Pin4 , DIO_u8Pin5 , DIO_u8Pin6 , (u32)Angleee ) ;
		CLCD_voidClearScreen();
		CLCD_u8SendString("Angle Reached");
		_delay_ms(2000);
		break;
	case 3 :
		while(1);
		break;
	}
	}
	goto again ;



}





void Moving( u8 Copy_u8UpperNormalPatternNumber , u8 Copy_u8LowerNormalPatternNumber  )
{
	u8 FirstLine = 0 ;
	u8 SecondLine = 1 ;
	u8 YPos = 0 ;

	while( YPos <= 15 )
	{
		CLCD_voidWriteSpecialChar( Copy_u8UpperNormalPatternNumber , FirstLine , YPos ) ;
		CLCD_voidWriteSpecialChar( Copy_u8LowerNormalPatternNumber , SecondLine , YPos ) ;

		_delay_ms(250);

		YPos++ ;
		CLCD_voidClearScreen() ;

		CLCD_voidWriteSpecialChar( Copy_u8UpperNormalPatternNumber+1 , FirstLine , YPos ) ;
		CLCD_voidWriteSpecialChar( Copy_u8LowerNormalPatternNumber+1 , SecondLine , YPos ) ;

		_delay_ms(250);

		YPos++ ;
		CLCD_voidClearScreen() ;

	}
}


u16 p( u8 Base , u8 power )
{
	u16 res = 1 ;
	u8 iterator = 0;
	for( iterator=0 ; iterator < power ; iterator++ )
	{
		res = res * Base ;
	}
	return res;
}

u32 Angle( void )
{
	u8 AngleArr[4] = { 0 } ;
	u8 i = 0 , LoopCounter = 0 ;
	u8 Pressed_Key = KEYPAD_NO_PRESSED_KEY ;

	u32 StepperAngle = 0 ;

	while( Pressed_Key != '=' )
	{
		Pressed_Key = KEYPAD_u8PollingUntilKeyPressed();
		if( Pressed_Key != '=' )
		{
			AngleArr[i]= Pressed_Key ;
			CLCD_voidWriteIntegerNumber( (s32)Pressed_Key , 1 , i );
			i++;
		}
		else
		{
			CLCD_voidWriteSpecialChar( 4 , 1 , i ) ;
		}
	}
	i--;
	/*To get angle*/
	for( LoopCounter = 0 ; LoopCounter <=i ; LoopCounter++ )
	{
		StepperAngle  = StepperAngle + ( p( 10,(i-LoopCounter) ) * AngleArr[LoopCounter] );
	}

	return StepperAngle ;
}

