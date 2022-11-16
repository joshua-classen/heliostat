/*
 * main.cpp
 *
 * Created: 10.05.2015 17:00:43
 *  Author: Joshua Classen
 */
//Die Dokumentation zu den Funktionen finden Sie in den Header (.hpp) Dateien
#define F_CPU 8000000UL       //Taktfrequenz 8MHz
//#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "motor.hpp"
#include "global.hpp"


//motor1

#define MOTOR1_PIN0  PC0
#define MOTOR1_PIN1  PC1
#define MOTOR1_PIN2  PC2
#define MOTOR1_PIN3  PC3


//motor2
#define MOTOR2_PIN0 PB0
#define MOTOR2_PIN1 PB1
#define MOTOR2_PIN2 PB2
#define MOTOR2_PIN3 PB3




#define TASTER_M1_MANUELL PD4
#define TASTER_M2_MANUELL PD5
#define TASTER_UMSCHALT_MANUELL PD6



/*

INFO:
step motor 28byj-48
Schrittmotor benötigt 2048 steps für 360°

*/
// .equ	DDRB	=$17

static bool manualcontroll = false; //manuelle Kontrolle über Taster standardmäßig nicht aktiviert.
static bool warmanualcontrollvorheraktiviert = false;




int main(void)
{
    init_atmega(); //ports initialisieren

    motor motorRollall(MOTOR1_PIN0, MOTOR1_PIN1, MOTOR1_PIN2, MOTOR1_PIN3, &PORTC);
    motor motorRollSolarpanele(MOTOR2_PIN0, MOTOR2_PIN1, MOTOR2_PIN2, MOTOR2_PIN3, &PORTB);




    while(true)
    {
		//Tasterabfrage
        if ( !(PIND & (1<<TASTER_UMSCHALT_MANUELL)) ) //wenn bit gesetz ist (pull up widerstände) // Wenn Taster gedrückt
		{
            if(warmanualcontrollvorheraktiviert == false)
            {
                manualcontroll = true;
            }
            else
            {
                manualcontroll = false;
            }
			//abfragen ob Taster vorher schon aktiviert wurde

		}

		if ( PIND & (1<<TASTER_UMSCHALT_MANUELL) ) //wenn bit nicht gesetz ist (pull up widerstände) // Wenn Taster nicht gedrückt
		{
            if(manualcontroll == true) // manualcontroll ist noch an
            {
                warmanualcontrollvorheraktiviert = true; //manualcontroll war vorher an

            }
            else //manualcontroll == false
            {
                warmanualcontrollvorheraktiviert = false;
            }
		}



		if(manualcontroll == false) //wenn manuelle Kontrolle nicht aktiviert ist, dann fürhre automatische Steuerung aus
		{

			//MOTOR1
			if ( !(PIND & (1<<PIND0)) ) //wenn bit gesetz ist (pull up widerstände)
			{
				motorRollall.rechtsrum(10,1);
			}


			if ( !(PIND & (1<<PIND1)) ) //wenn bit gesetz ist (pull up widerstände)
			{
				motorRollall.linksrum(10,1);
			}




			//MOTOR2
			if ( !(PIND & (1<<PIND2)) ) //wenn bit gesetz ist (pull up widerstände)
			{
				motorRollSolarpanele.linksrum(10,1);
			}


			if ( !(PIND & (1<<PIND3)) ) //wenn bit gesetz ist (pull up widerstände)
			{
				motorRollSolarpanele.rechtsrum(10,1);
			}

		}


		if(manualcontroll == true) //wenn manuelle Ḱontrolle aktiviert ist
		{
            if ( !(PIND & (1<<TASTER_M1_MANUELL)) ) //wenn bit gesetz ist (pull up widerstände)
            {
                motorRollall.linksrum(10,1);
            }

            if ( !(PIND & (1<<TASTER_M2_MANUELL)) ) //wenn bit gesetz ist (pull up widerstände)
            {
                motorRollSolarpanele.linksrum(10,1);
            }
		}
    }


}
