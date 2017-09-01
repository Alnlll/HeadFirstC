CUR_PATH = ./

SRC_PATH = ${CUR_PATH}src/
INC_PATH = ${CUR_PATH}include/
OUTPUT_PATH = ${CUR_PATH}output/
LIB_PATH = /my_lib/

main: main.o libhfcal.so
	gcc ${OUTPUT_PATH}main.o -L${LIB_PATH} -lhfcal -o main

libhfcal.so: calories.o
	gcc -shared ${OUTPUT_PATH}calories.o -o ${LIB_PATH}libhfcal.so

main.o: ${SRC_PATH}main.c
	gcc -I${INC_PATH} -c ${SRC_PATH}main.c
	mv *.o ${OUTPUT_PATH}
calories.o: ${SRC_PATH}calories.c ${INC_PATH}calories.h
	gcc -I${INC_PATH} -fPIC -c ${SRC_PATH}calories.c
	mv *.o ${OUTPUT_PATH}

.PHONY: clean
clean:
	cd ${OUTPUT_PATH} && rm -r *.o || cd -
	-rm -r main