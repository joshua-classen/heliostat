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
//Hier werden die nötigen Headerdateien für den µC eingebunden.
#include <avr/io.h>
#include <util/delay.h>


/*Die Funktion "wait_ms" ist eine Funktion die den µC mit einer gewissen Zeit mit nichts tun beschäftigt. "wait_ms" übernimmt einen Parameter vom Typ const unsigned als Referenz. 
Dieser Parameter steht für die Millisekunden die gewartet werden soll.*/
void wait_ms(const unsigned &wartems);



void init_atmega(void); //Grundlegende Initialisierung des µC findet hier statt


#endif //GLOBAL_HPP
