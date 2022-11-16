CC = avr-g++
CFLAGS  = -g
OBJECTS = main.o motor.o global.o
MCU = -mmcu=atmega8
TARGET = motorcontroll


OBJCOPY = avr-objcopy
SECTIONS = -j .text -j .data
OBJCOPYFLAGS = -O ihex

all: $(TARGET).hex


main.o:  main.cpp motor.hpp global.hpp
	$(CC) $(MCU) -Os $(CFLAGS) -c main.cpp


global.o: global.cpp global.hpp
	$(CC) $(MCU) -Os $(CFLAGS) -c global.cpp


motor.o: motor.cpp motor.hpp global.hpp
	$(CC) $(MCU) -Os $(CFLAGS) -c motor.cpp


$(TARGET).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(MCU) -o $(TARGET).elf $(OBJECTS)


$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) $(SECTIONS) $(OBJCOPYFLAGS) $(TARGET).elf $(TARGET).hex

clean:
	rm -f *.o


# funktioniert hier nur mit dem atmel avrispmk2
# program: schreibt .hex datei in flash Speicher vom µC
program: $(TARGET).hex #fixen damit normale user auf avrdude zugreifen können
	avrdude -c avrispmkII -p m8 -P usb -v -U flash:w:$(TARGET).hex:i


