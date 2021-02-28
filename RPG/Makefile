CC = gcc
EXEC = program
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o newSleep.o showInfo.o linkedList.o gamePlay.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c newSleep.h showInfo.h linkedList.h gamePlay.h
	$(CC) -c main.c $(CFLAGS)
newSleep.o : newSleep.c
	$(CC) -c newSleep.c $(CFLAGS)
showInfo.o : showInfo.c
	$(CC) -c showInfo.c $(CFLAGS)
linkedList.o : linkedList.c
	$(CC) -c linkedList.c $(CFLAGS)
gamePlay.o : gamePlay.c
	$(CC) -c gamePlay.c $(CFLAGS)

.PHONY : clean
clean :
	rm -f &(EXEC) $(OBJ)


