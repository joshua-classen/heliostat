/*
 * motor.cpp
 *
 * Created: 10.05.2015 17:00:43
 *  Author: Joshua Classen
 */

//Die Dokumentation zu den Funktionen finden Sie in den Header (.hpp) Dateien
#include "motor.hpp"




motor::motor(const uint8_t &pin0_ = 0, const uint8_t &pin1_ = 0, const uint8_t &pin2_ = 0, const uint8_t &pin3_ = 0, volatile uint8_t *port_of_motor = 0):
                                                                                pin0(pin0_), pin1(pin1_), pin2(pin2_), pin3(pin3_), port_motor(port_of_motor) {}







void motor::setPin(const unsigned &pin_num ,const bool &status)
{
	if(status) //if high
	{
		//sezte bit pin_num auf high.
        *port_motor |= (1<<pin_num);
	}

	else
	{
		//setze bit pin_num auf low.
		*port_motor &= ~(1<<pin_num);
	}
}








void motor::stop(void)
{
	setPin(pin0, LOW);
	setPin(pin1, LOW);
	setPin(pin2, LOW);
	setPin(pin3, LOW);
}


void motor::rechtsrum(unsigned motorspeed, const double &degree)
{
	/*	Der Schrittmotor benötigt 512 Schritte für eine volle Umdrehung.
		Deshalb rechnet man 512 / 360 = 1.42222222222
	*/


	if(motorspeed == 0) ++motorspeed; //Motor darf keine unendliche Geschwindigkeit haben



	for(unsigned ix = 0; ix < degree*1.4222222; ++ix)
	{
		//1
		setPin(pin0, HIGH);
		setPin(pin1, LOW);
		setPin(pin2, LOW);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//2
		setPin(pin0, HIGH);
		setPin(pin1, HIGH);
		setPin(pin2, LOW);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//3
		setPin(pin0, LOW);
		setPin(pin1, HIGH);
		setPin(pin2, LOW);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//4
		setPin(pin0, LOW);
		setPin(pin1, HIGH);
		setPin(pin2, HIGH);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//5
		setPin(pin0, LOW);
		setPin(pin1, LOW);
		setPin(pin2, HIGH);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//6
		setPin(pin0, LOW);
		setPin(pin1, LOW);
		setPin(pin2, HIGH);
		setPin(pin3, HIGH);

		wait_ms(motorspeed);

		//7
		setPin(pin0, LOW);
		setPin(pin1, LOW);
		setPin(pin2, LOW);
		setPin(pin3, HIGH);

		wait_ms(motorspeed);

		//8
		setPin(pin0, HIGH);
		setPin(pin1, LOW);
		setPin(pin2, LOW);
		setPin(pin3, HIGH);

		wait_ms(motorspeed);
	}
	stop();
}



void motor::linksrum(unsigned motorspeed, const double &degree)
{
	/*	Der Schrittmotor benötigt 512 Schritte für eine volle Umdrehung.
		Deshalb rechnet man 512 / 360 = 1.42222222222
	*/

	if(motorspeed == 0) ++motorspeed; //Motor darf keine unendliche Geschwindigkeit haben, darum wird Wert auf 1 gesetzt falls er auf 0 stehen sollte.

	for(unsigned ix = 0; ix < degree*1.42222222; ++ix)
	{
		//8
		setPin(pin0, HIGH);
		setPin(pin1, LOW);
		setPin(pin2, LOW);
		setPin(pin3, HIGH);

		wait_ms(motorspeed);

		//7
		setPin(pin0, LOW);
		setPin(pin1, LOW);
		setPin(pin2, LOW);
		setPin(pin3, HIGH);

		wait_ms(motorspeed);

		//6
		setPin(pin0, LOW);
		setPin(pin1, LOW);
		setPin(pin2, HIGH);
		setPin(pin3, HIGH);

		wait_ms(motorspeed);

		//5
		setPin(pin0, LOW);
		setPin(pin1, LOW);
		setPin(pin2, HIGH);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//4
		setPin(pin0, LOW);
		setPin(pin1, HIGH);
		setPin(pin2, HIGH);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//3
		setPin(pin0, LOW);
		setPin(pin1, HIGH);
		setPin(pin2, LOW);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//2
		setPin(pin0, HIGH);
		setPin(pin1, HIGH);
		setPin(pin2, LOW);
		setPin(pin3, LOW);

		wait_ms(motorspeed);

		//1
		setPin(pin0, HIGH);
		setPin(pin1, LOW);
		setPin(pin2, LOW);
		setPin(pin3, LOW);

		wait_ms(motorspeed);
	}
	stop();
}
