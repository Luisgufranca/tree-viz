CC = gcc
CFLAGS = -Wall -g
TARGET = treeviz
OBJS = main.o abp.o stack.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c abp.h
	$(CC) $(CFLAGS) -c main.c

abp.o: abp.c abp.h stack.h
	$(CC) $(CFLAGS) -c abp.c

stack.o: stack.c stack.h abp.h
	$(CC) $(CFLAGS) -c stack.c

clean: # pra limpar o que o make gerou
ifeq ($(OS),Windows_NT)
	del /Q *.o *.exe *.dot *.png 2>NUL
else
	rm -f *.o $(TARGET) *.dot *.png
endif

run: $(TARGET)
	./$(TARGET)