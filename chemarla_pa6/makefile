C = gcc
CFLAGS = -Wall -g -std=c99 -lm
TARGET1 = runsim
OBJ1 = runsim.c
TARGET2 = testsim
OBJ2 = testsim.c
all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJ1)
$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJ2)

runsim.o: runsim.c
	$(CC) $(CFLAGS) -c runsim.c
testsim.o: testsim.c
	$(CC) $(CFLAGS) -c testsim.c


clean:
	/bin/rm -f *.o $(TARGET1) $(TARGET2)
