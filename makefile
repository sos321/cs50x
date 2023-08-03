CC=gcc
OUTFLAG=-o

create_cs50_exe: cs50.c
	@echo "Compiling with cs50 lib"
	@${CC} ${DIR}/${FILE} cs50.c ${OUTFLAG} ${FILE:%.c=%}.exe

create_exe:
	@echo "Compiling w/o cs50 lib"
	@${CC} ${DIR}/${FILE} ${OUTFLAG} ${FILE:%.c=%}.exe

clean:
	@echo "Cleaning all .exe files"
	@- del *.exe


