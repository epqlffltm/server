#makefile
CC = gcc
CFLAGS = -Wall -g

SRCG = $(wildcard *.c)

TARGER = $(SRCG: .c=)

all: $(TARGET)

#일반화된 규칙: 이름이 %인 타겟은 %.c를 의존성으로 가짐
# $@ : 타겟 이름 (예: add)
# $< : 첫 번째 의존성 파일 (예: add.c)
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)