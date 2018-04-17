C = gcc
CFLAGS = -Wall -g -std=c99 -lm
TARGET1 = wc
OBJ1 = fileStat.c
TARGET2= bank
OBJ2 = ams.o deposit.o withdraw.o addAccount.o remAccount.o balInquiry.o viewAcc.o

all: $(TARGET1) $(TARGET2)
$(TARGET1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJ1)
$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJ2)

fileStat.o: fileStat.c
	$(CC) $(CFLAGS) -c fileStat.c

ams.o: ams.c ams.h deposit.h withdrawl.h addAccount.h remAccount.h balInquiry.h viewAcc.h
	$(CC) $(CFLAGS) -c ams.c
deposit.o: deposit.c deposit.h ams.h
	$(CC) $(CFLAGS) -c deposit.c
withdrawl.o: withdrawl.c withdrawl.h ams.h
	$(CC) $(CFLAGS) -c withdraw.c
addAccount.o: addAccount.c addAccount.h ams.h
	$(CC) $(CFLAGS) -c addAccount.c
remAccount.o: remAccount.c remAccount.h ams.h
	$(CC) $(CFLAGS) -c remAccount.c
balInquiry.o: balInquiry.c balInquiry.h ams.h
	$(CC) $(CFLAGS) -c balInquiry.c
viewAcc.o: viewAcc.c viewAcc.h ams.h
	$(CC) $(CFLAGS) -c viewAcc.c


clean:
	/bin/rm -f *.o $(TARGET1) $(TARGET2)
