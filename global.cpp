/*
 * global.cpp
 *
 * Created: 10.05.2015 17:00:43
 *  Author: Joshua Classen
 */

//Die Dokumentation zu den Funktionen finden Sie in den Header (.hpp) Dateien
#include "global.hpp"


void init_atmega(void) //Grundlegende Initialisierung des µC findet hier statt
{
    //portC als ausgang
	DDRC = 0xFF; //pins für den motor1 als ausgang definieren
    //portB als ausgang
    DDRB = 0xFF; //pins für den motor2 als ausgang definieren


	//portD als eingang
	DDRD = 0x00;



	PORTD = 0xFF; //pullups
	wait_ms(2000);  // 2sekunden warten
}


void wait_ms(const unsigned &wartems)
{
	for(unsigned ix = 0; ix != wartems; ++ix)
	{
		_delay_ms(1);
	}

}
