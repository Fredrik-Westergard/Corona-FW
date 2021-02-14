CFLAGS = -Wall -pedantic

all: corona linkedListTest dateTest clean

corona: main.o utilities.o date.o linkedList.o
	gcc $(CFLAGS) main.o utilities.o date.o linkedList.o -o corona -lm

dateTest: date.o
	gcc $(CFLAGS) dateTest.c date.o -o dateTest

linkedListTest: linkedList.o date.o utilities.o
	gcc $(CFLAGS) linkedTest.c linkedList.o date.o utilities.o -o linkedListTest -lm

main.o: main.c utilities.h date.h linkedList.h
	gcc $(CFLAGS) -c main.c -o main.o

utilities.o: utilities.c utilities.h date.h linkedList.h
	gcc $(CFLAGS) -c utilities.c -o utilities.o

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c -o date.o

linkedList.o: linkedList.c linkedList.h
	gcc $(CFLAGS) -c linkedList.c -o linkedList.o

clean:
	-rm *.o