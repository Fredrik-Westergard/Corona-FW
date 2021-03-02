CFLAGS = -Wall -pedantic

all: corona linkedListTest dateTest createCodes codeListTest

corona: main.o utilities.o date.o linkedList.o codesList.o
	gcc $(CFLAGS) main.o utilities.o date.o linkedList.o codesList.o -o corona -lm

dateTest: date.o
	gcc $(CFLAGS) dateTest.c date.o -o dateTest

linkedListTest: linkedList.o date.o
	gcc $(CFLAGS) linkedTest.c linkedList.o date.o -o linkedListTest -lm

codeListTest: codeListTest.c codesList.o
	gcc $(CFLAGS) codeListTest.c codesList.o -o codeListTest

main.o: main.c utilities.h date.h linkedList.h codesList.h
	gcc $(CFLAGS) -c main.c -o main.o

utilities.o: utilities.c utilities.h date.h linkedList.h codesList.c codesList.h
	gcc $(CFLAGS) -c utilities.c -o utilities.o

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c -o date.o

linkedList.o: linkedList.c linkedList.h
	gcc $(CFLAGS) -c linkedList.c -o linkedList.o

codesList.o: codesList.c codesList.h
	gcc $(CFLAGS) -c codesList.c -o codesList.o

createCodes:
	gcc $(CFLAGS) createCodes.c -o createCodes

clean:
	-rm *.o