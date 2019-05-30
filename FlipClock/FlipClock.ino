#include "Servo.h"


#if defined(ARDUINO_AVR_NANO)
	//	if this is the elegoo nano, https://www.amazon.co.uk/ask/questions/asin/B072BMYZ18/ref=ask_dp_dpmw_ql_hza?isAnswered=true
	//	select arduino nano, processor ATMega32p (old bootloader)
	//	and needs the CH30 driver installed
	#define FIVEVOLT_PIN	2
	#define SERVO_PIN		3
#else
#error expecting elegoo nano
#endif


Servo TheServo;
//	when calibrating, just set 90 and turn screw until it stops moving
//	https://alexkychen.wordpress.com/2017/12/12/continuous-servo-fs90r-with-arduino/
//#define CALIBRATION_MODE

void setup() 
{
	Serial.begin( 115200 );
	
	//	make digital pin as 5v 
	pinMode( FIVEVOLT_PIN, OUTPUT );
	digitalWrite( FIVEVOLT_PIN, HIGH );

	pinMode( SERVO_PIN, OUTPUT );

#if defined(CALIBRATION_MODE)
	//	calibrate
   	TheServo.attach( SERVO_PIN );
   	TheServo.write(90);
#endif

	TheServo.attach( SERVO_PIN );
   	TheServo.write(90);
   	TheServo.detach();
}


int AngleIndex = 0;
#define AngleCount	11
int Angles[AngleCount] = { 90, 1, 90, 89, 1, 90, 80, 90, 90, 1, 90 };
void loop() 
{
#if defined(CALIBRATION_MODE)
	return;
#endif

	TheServo.attach( SERVO_PIN );
	TheServo.write(80);
	delay(140);
	TheServo.write(90);
	delay(1000);
	//TheServo.write(80);
/*
	TheServo.write(90);
	TheServo.write(1);
	delay(50);
	TheServo.write(90);
	delay(2000);
	*/
/*
	TheServo.attach( SERVO_PIN );
	int Angle = Angles[AngleIndex];
	TheServo.write(Angle);
	Serial.print("Angle=");
	Serial.println(Angle);
	delay(1000);

	//TheServo.detach();
	delay(2000);

	AngleIndex += 1;
	AngleIndex = AngleIndex % AngleCount;
	*/
}
