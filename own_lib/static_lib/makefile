CUR_PATH = ./

SRC_PATH = ${CUR_PATH}src/
INC_PATH = ${CUR_PATH}include/
OUTPUT_PATH = ${CUR_PATH}output/
LIB_PATH = /my_lib/

#main: ${OUTPUT_PATH}main.o ${OUTPUT_PATH}encrypt.o ${OUTPUT_PATH}checksum.o
#	gcc ${OUTPUT_PATH}main.o ${OUTPUT_PATH}encrypt.o ${OUTPUT_PATH}checksum.o -o main
main: ${OUTPUT_PATH}main.o ${OUTPUT_PATH}libhfsecurity.a
	gcc ${OUTPUT_PATH}main.o -L${LIB_PATH} -lhfsecurity -o main

${OUTPUT_PATH}libhfsecurity.a: ${OUTPUT_PATH}encrypt.o ${OUTPUT_PATH}checksum.o
	ar -rcs ${OUTPUT_PATH}libhfsecurity.a ${OUTPUT_PATH}encrypt.o ${OUTPUT_PATH}checksum.o && cp ${OUTPUT_PATH}libhfsecurity.a ${LIB_PATH}

${OUTPUT_PATH}main.o: ${SRC_PATH}main.c
	gcc -I${INC_PATH} -c ${SRC_PATH}main.c
	mv *.o ${OUTPUT_PATH}

${OUTPUT_PATH}encrypt.o: ${SRC_PATH}encrypt.c ${INC_PATH}encrypt.h
	gcc -c ${SRC_PATH}encrypt.c
	mv *.o ${OUTPUT_PATH}

${OUTPUT_PATH}checksum.o: ${SRC_PATH}checksum.c ${INC_PATH}checksum.h
	gcc -c ${SRC_PATH}checksum.c
	mv *.o ${OUTPUT_PATH}


.PHONY: clean
clean:
	cd ${OUTPUT_PATH} && rm -r *.o || cd -
	-rm -r main