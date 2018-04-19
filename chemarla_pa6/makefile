C = gcc
CFLAGS = -Wall -g -std=c99 -lm
TARGET1 = runsim
OBJ1 = runsim.c

$(TARGET1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJ1)

runsim.o: runsim.c
	$(CC) $(CFLAGS) -c runsim.c



clean:
	/bin/rm -f *.o $(TARGET1) $(TARGET2)
