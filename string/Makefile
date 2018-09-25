CFLAGS := -Wall -DDEBUG -std=c99
CFLAGS_CC := -std=c++11 -Wall -DDEBUG
LDFLAGS_CC := -lstdc++ 
OUTPUT ?= ../out

targets := $(patsubst %.c,%,$(wildcard *.c))
cc_targets := $(patsubst %.cc,%_cc,$(wildcard *.cc))
all: $(targets) $(cc_targets)

$(targets): %: %.c
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $< ${LDFLAGS}

$(cc_targets): %_cc: %.cc
	${CC} ${CFLAGS_CC} -o $(OUTPUT)/$@ $< ${LDFLAGS_CC}
