#CC=arm-linux-gcc
CC=arm-linux-gnueabihf-gcc
CFLAGS=-g
LFLAGS=
LIBS=-lpthread -lrt -lm
SRCS= main.c logger.c my_uart.c timer.c 
TARGET=main
OBJS=$(SRCS:.c=.o)
all:$(TARGET)
INCLUDES=-I../include/

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS) $(INCLUDES)
#	scp $(TARGET) debian@192.168.1.81: #debian@128.138.189.97: #debian@10.0.0.77:
.c.o:
	$(CC) -c $(SRCS) $(INCLUDES) 

clean:
	rm -f *.o $(TARGET)
