BIN=bin
SRC=src
SRC_ASM=src/asm
SRC_C=src/c

all:
	@nasm ${SRC_ASM}/boot-sect.asm -f bin -o ${BIN}/bootsect.bin
	@nasm ${SRC_ASM}/k-entry.asm -f elf32 -o ${BIN}/entry.bin

	@gcc -m32 -ffreestanding -c ${SRC_C}/kernel.c -o ${BIN}/kernel.o
	@ld -m elf_i386 -z noexecstack -e kmain -o ${BIN}/kernel.img -Ttext 0x1000 ${BIN}/entry.bin ${BIN}/kernel.o

	@objcopy -O binary -j .text ${BIN}/kernel.img ${BIN}/kernel.bin
	@cat ${BIN}/bootsect.bin ${BIN}/kernel.bin > ${BIN}/os-image

run:
	qemu-system-i386 -drive format=raw,file=${BIN}/os-image