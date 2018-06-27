CFLAGS=-Wall -DDEBUG -std=c99
CFLAGS_CC=-std=c++11 -Wall -DDEBUG
LDFLAGS_CC=-lstdc++ 

TWO_SUM_SRC=array/twoSum.c
TWO_SUM_SRC_CC=array/twoSum.cc
MEDIAN_SORTED_ARRAY=array/findMedianSortedArrays.c
MAX_AREA=array/maxArea.c

LEN_LONGEST_SUBSTR=string/lengthOfLongestSubstring.c
LONGEST_PALINDROME=string/longestPalindrome.c
ZIGZAG=string/zigzag.c
RE_MATCHING=string/REMatching.c

REVERSE=math/reverse.c

TEST_SRC=test/test.c
TEST_SRC_CC=test/test.cc


PROGRAMS=twoSum twoSum_cc findMedianSortedArrays longestSubString longestPalindrome zigzag reverse \
REMatching maxArea
OUTPUT=out

all: ${PROGRAMS}

twoSum:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(TWO_SUM_SRC) ${LDFLAGS} 
twoSum_cc:
	${CC} ${CFLAGS_CC} -o $(OUTPUT)/$@ $(TWO_SUM_SRC_CC) ${LDFLAGS_CC}
findMedianSortedArrays:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(MEDIAN_SORTED_ARRAY) ${LDFLAGS} 
maxArea:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(MAX_AREA) ${LDFLAGS} 
	
longestSubString:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(LEN_LONGEST_SUBSTR) ${LDFLAGS} 
longestPalindrome:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(LONGEST_PALINDROME) ${LDFLAGS} 
zigzag:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(ZIGZAG) ${LDFLAGS} 
REMatching:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(RE_MATCHING) ${LDFLAGS} 	
reverse:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(REVERSE) ${LDFLAGS} 
	
test_c:
	${CC} ${CFLAGS} -o $(OUTPUT)/$@ $(TEST_SRC) ${LDFLAGS} 
test_cc:
	${CC} ${CFLAGS_CC} -o $(OUTPUT)/$@ $(TEST_SRC_CC) ${LDFLAGS_CC}
clean:
	@rm -rf $(OUTPUT)/*
	
recompile:	clean all
