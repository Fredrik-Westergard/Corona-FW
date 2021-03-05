CFLAGS = -Wall -pedantic -g

all: corona linkedListTest dateTest createCodes codeListTest hashMapTest

corona: main.o utilities.o date.o codesList.o hashMap.o
	gcc $(CFLAGS) main.o utilities.o date.o codesList.o hashMap.o -o corona -lm

dateTest: date.o
	gcc $(CFLAGS) dateTest.c date.o -o dateTest

linkedListTest: linkedList.o date.o
	gcc $(CFLAGS) linkedTest.c linkedList.o date.o -o linkedListTest -lm

codeListTest: codeListTest.c codesList.o
	gcc $(CFLAGS) codeListTest.c codesList.o -o codeListTest

hashMapTest: hashMapTest.c hashMap.o date.o
	gcc $(CFLAGS) hashMapTest.c hashMap.o date.o -o hashMapTest -lm

main.o: main.c utilities.c date.c codesList.c hashMap.c utilities.h date.h codesList.h hashMap.h
	gcc $(CFLAGS) -c main.c -o main.o

utilities.o: utilities.c utilities.h date.c codesList.c codesList.c hashMap.c date.h codesList.h codesList.h hashMap.h
	gcc $(CFLAGS) -c utilities.c -o utilities.o

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c -o date.o

linkedList.o: linkedList.c linkedList.h
	gcc $(CFLAGS) -c linkedList.c -o linkedList.o

codesList.o: codesList.c codesList.h
	gcc $(CFLAGS) -c codesList.c -o codesList.o

hashMap.o: hashMap.c hashMap.h date.o
	gcc $(CFLAGS) -c hashMap.c -o hashMap.o

createCodes:
	gcc $(CFLAGS) createCodes.c -o createCodes

clean:
	-rm *.o