CFLAGS=-Wall -DDEBUG
CFLAGS_CC=-std=c++11 -Wall -DDEBUG
LDFLAGS_CC=-lstdc++ 

TWO_SUM_SRC=array/twoSum.c
TWO_SUM_SRC_CC=array/twoSum.cc
MEDIAN_SORTED_ARRAY=array/findMedianSortedArrays.c

LEN_LONGEST_SUBSTR=string/lengthOfLongestSubstring.c


PROGRAMS=twoSum twoSum_cc findMedianSortedArrays longestSubString
OUTPUT=out

all: ${PROGRAMS}

twoSum:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(TWO_SUM_SRC) ${LDFLAGS} 
twoSum_cc:
	${CC} ${CFLAGS_CC} -o $(OUTPUT)/$@ $(TWO_SUM_SRC_CC) ${LDFLAGS_CC}
findMedianSortedArrays:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(MEDIAN_SORTED_ARRAY) ${LDFLAGS} 
longestSubString:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(LEN_LONGEST_SUBSTR) ${LDFLAGS} 
clean:
	@rm -rf $(OUTPUT)/*
	
recompile:	clean all
