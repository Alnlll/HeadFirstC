CUR_PATH = ./

SRC_PATH = ${CUR_PATH}src/
INC_PATH = ${CUR_PATH}include/
OUTPUT_PATH = ${CUR_PATH}output/
LIB_PATH = /my_lib/

CGLAGS = -I${INC_PATH}
CC = gcc

main: main.o libhfcal.so
	${CC} ${OUTPUT_PATH}main.o -L${LIB_PATH} -lhfcal -o main

libhfcal.so: calories_UK.o
	${CC} -shared ${OUTPUT_PATH}calories_UK.o -o ${LIB_PATH}libhfcal.so

main.o: ${SRC_PATH}main.c
	${CC} ${CGLAGS} -c ${SRC_PATH}main.c
	mv *.o ${OUTPUT_PATH}
calories_UK.o: ${SRC_PATH}calories_UK.c ${INC_PATH}calories_UK.h
	${CC} ${CGLAGS} -fPIC -c ${SRC_PATH}calories_UK.c
	mv *.o ${OUTPUT_PATH}

.PHONY: clean
clean:
	cd ${OUTPUT_PATH} && rm -r *.o || cd -
	#-rm -r main