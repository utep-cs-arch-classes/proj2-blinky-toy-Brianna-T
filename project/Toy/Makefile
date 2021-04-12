# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf 

#additional rules for files
toy.elf: ${COMMON_OBJECTS} Toymain.o stateM.o Blinkled.o wdInterruptHandler.o buzz.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

Blinkled.o: Blinkled.c Blinkled.h
wdInterruptHandler.o: stateM.h
stateM.o:Blinkled.h stateM.h

buzz.c:buzz.h


