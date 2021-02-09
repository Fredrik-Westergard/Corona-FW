CFLAGS = -Wall -pedantic

all: corona-App linkedTest dateTest clean

corona-App: main.o utilities.o date.o linkedList.o
	gcc $(CFLAGS) main.o utilities.o date.o linkedList.o -o corona -lm

dateTest: date.o
	gcc $(CFLAGS) dateTest.c date.o -o dateTests

linkedTest: linkedList.o date.o utilities.o
	gcc $(CFLAGS) linkedTest.c linkedList.o date.o utilities.o -o linkedListTest -lm

main.o: utilities.h date.h linkedList.h
	gcc $(CFLAGS) -c main.c -o main.o

utilities.o: utilities.h date.h linkedList.h
	gcc $(CFLAGS) -c utilities.c -o utilities.o

date.o: date.h
	gcc $(CFLAGS) -c date.c -o date.o

linkedList.o: linkedList.h
	gcc $(CFLAGS) -c linkedList.c -o linkedList.o

clean:
	-rm *.o