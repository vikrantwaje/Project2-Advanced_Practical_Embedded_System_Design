#CC=arm-linux-gcc
CC=arm-linux-gnueabihf-gcc
CFLAGS=-g
LFLAGS=
LIBS=-lpthread -lrt -lm
SRCS= my_uart.c 
TARGET=main
OBJS=$(SRCS:.c=.o)
all:$(TARGET)
INCLUDES=-I../include/

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS) $(INCLUDES)
	scp $(TARGET) debian@128.138.189.97: #debian@10.0.0.77:
.c.o:
	$(CC) -c $(SRCS) $(INCLUDES) 

clean:
	rm -f *.o $(TARGET)
