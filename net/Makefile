#makefile

CC = gcc
CFLAGS = -Wall -g

SRCG = %$(wildcard *.c)

TARGET = $(SRCG:.c=)

all: $(TARGET)
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)