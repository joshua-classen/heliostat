/*
 * motor.hpp
 *
 * Created: 10.05.2015 17:00:43
 *  Author: Joshua Classen
 */

#ifndef MOTOR_HPP
#define MOTOR_HPP

//Hier werden die nötigen Headerdateien für den µC eingebunden.
#define F_CPU 8000000UL       //Taktfrequenz 18MHz
//#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h> //eventuell löschen
#include "global.hpp"





#ifndef HIGH
	#define HIGH 1
#endif
#ifndef LOW
	#define LOW 0
#endif


//Die Klasse Motor beinhaltet Funktionen zur Steuerung der Schrittmotoren.
class motor
{
	public:

		//Konstruktor übernimmt Adressen für die Pins die angesprochen werden sollen.
		motor(const uint8_t &pin0_, const uint8_t &pin1_, const uint8_t &pin2_, const uint8_t &pin3_, volatile uint8_t *port_of_motor);

		//write a destructor


		/*
		Die Funktion "rechtsrum" lässt den Motor rechts drehen. Der Parameter "motorspeed" gibt an wie schnell sich der Motor drehen soll. Wenn der Wert auf 1 steht, dann dreht sich der Motor am schnellsten.
		Größere Werte lassen ihn langsamer laufen. Wenn "motorspeed" auf 2 steht, dann läuft der Motor um die hälfte langsamer als wenn er auf 1 stehen würde. Bevor sich die Funktion terminiert, ruft sie
		noch die Funktion "stop" auf, damit die Spannung vom Motor genommen wird. Falls die Funktion mit "motorspeed = 0" aufgerufen wird, wird intern "motorspeed" auf 1 gesetzt, weil der Motor andernfalls überhitzen würde.

		Mit dem Parameter "degree" kann man der Funktion angeben um wieviel Grad sich der Motor drehen soll. Dies ist aber aufgrund von Rundungsfehlern nicht zu 100% korrekt.
		Eine Abweichung von +- 1° ist möglich.
		*/
		void rechtsrum(unsigned motorspeed, const double &degree); //Warnung: die Nutzung von "degree" kann ungenau sein, da es zu Rundungsfehlern kommen kann.

		/*Die Funktion "linksrum" funktioniert genauso wie die Funktion "rechtsrum", allerdings dreht sich der Motor hier nach links.*/
		void linksrum(unsigned motorspeed, const double &degree);	//Warnung: die Nutzung von "degree" kann ungenau sein, da es zu Rundungsfehlern kommen kann.



	protected:
	private:
		/*pin0, pin1, pin2 und pin3 speichern die pins an die der Motor angeschlossen ist. */
		const uint8_t pin0, pin1, pin2, pin3;
        volatile uint8_t *port_motor;

		/* Die Funktion "setPin" setzt einen Pin auf high oder low, je nachdem welchen Wert "status" hat.
		Hat "status" den Wert 0, also false, dann wird der Pin "pin_num" auf NULL gesetzt. Andernfalls auf 1, also true.*/
		void setPin(const unsigned &pin_num, const bool &status);

		//Die Funktion "stop" nimmt die Spannung vom Motor. Wenn dies nicht gemacht wird, wenn der Motor stehen soll, dann kann es sein, dass der Motor überhizt, weil durch eine Spule im Motor die ganze Zeit ein Strom fließt!
		void stop(void);
};




#endif //MOTOR_HPP
