PREFIX = /usr/local

CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -O3

CC = cc

SRC = main.c

TARGET = collatz

all:
	${CC} ${CFLAGS} ${SRC} -o ${TARGET}

install: all
	${CC} ${CFLAGS} ${SRC} -o  ${TARGET}
	cp -f ${TARGET} ${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/${TARGET}

uninstall:
	rm -f ${PREFIX}/bin/${TARGET}


