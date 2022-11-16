/*
 * global.hpp
 *
 * Created: 10.05.2015 17:00:43
 *  Author: Joshua Classen
 */

#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define F_CPU 8000000UL       //Taktfrequenz 18MHz
//#define F_CPU 1000000UL
//Hier werden die n�tigen Headerdateien f�r den �C eingebunden.
#include <avr/io.h>
#include <util/delay.h>


/*Die Funktion "wait_ms" ist eine Funktion die den �C mit einer gewissen Zeit mit nichts tun besch�ftigt. "wait_ms" �bernimmt einen Parameter vom Typ const unsigned als Referenz. 
Dieser Parameter steht f�r die Millisekunden die gewartet werden soll.*/
void wait_ms(const unsigned &wartems);



void init_atmega(void); //Grundlegende Initialisierung des �C findet hier statt


#endif //GLOBAL_HPP
