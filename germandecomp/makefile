# germandecomp

NAME = "germandecomp"
SRC = ${NAME}.c
OBJ = ${SRC:.c=.o}
PREFIX = /usr/local
LDFLAGS = -std=gnu99
CC ?= cc

all: options clean ${NAME}

options:
	@echo "${NAME} build options:"
	@echo "CC= ${CC}"
	@echo "LDFLAGS: "
${NAME}:
	@echo CC -o $@
	@${CC} -o $@ ${SRC} ${LDFLAGS}

clean:
	@rm -f ${NAME}

dist: clean
	@echo creating dist tarball
	@mkdir -p ${NAME}
	@cp makefile ${SRC} ${NAME}
	@tar cf ${NAME}.tar ${NAME}
	@bzip2 ${NAME}.tar
	@rm -rf ${NAME}

install: all
	@echo installing to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f ${NAME} ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/${NAME}

uninstall:
	@echo removing from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/${NAME}
