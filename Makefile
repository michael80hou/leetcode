CFLAGS=-Wall -DDEBUG
CFLAGS_CC=-std=c++11 -Wall -DDEBUG
LDFLAGS_CC=-lstdc++ 
TWO_SUM_SRC=array/twoSum.c
TWO_SUM_SRC_CC=array/twoSum.cc

PROGRAMS=twoSum twoSum_cc
OUTPUT=out

all: ${PROGRAMS}

twoSum:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(TWO_SUM_SRC) ${LDFLAGS} 
twoSum_cc:
	${CC} ${CFLAGS_CC} -o $(OUTPUT)/$@ $(TWO_SUM_SRC_CC) ${LDFLAGS_CC}
clean:
	@rm -rf $(OUTPUT)/*
	
recompile:	clean all
