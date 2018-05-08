CFLAGS=-Wall -DDEBUG
TWO_SUM_SRC=array/twoSum.c

PROGRAMS=twoSum
OUTPUT=out

all: ${PROGRAMS}

twoSum:
	${CC} ${CFLAGS} ${LDFLAGS} -o $(OUTPUT)/$@ $(TWO_SUM_SRC)
clean:
	@rm -rf $(OUTPUT)/*
	
recompile:	clean all
