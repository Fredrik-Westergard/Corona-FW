all:
	gcc main.c utilities.c date.c -Wall -pedantic -lm -o corona

dateTest:
	gcc dateTest.c date.c -Wall -pedantic -o dateTests

linkedTest:
	gcc linkedTest.c linkedList.c date.c -o linkedListTest
	