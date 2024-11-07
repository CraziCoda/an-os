# BIN=bin
# SRCDIR=src
# OBJDIR=obj
# SRC_ASM=src/asm
# SRC_C=src/c
# CC=gcc
# CFLAGS=-Isrc/c/include -m32 -ffreestanding
# SRC_C_FILES=$(shell find . -name '*.c')
# OBJS=$(patsubst ${SRC_C_FILES}, $(OBJDIR)/%.o, $(SRC_C_FILES))

# all :
# 	@echo ${SRC_C_FILES}
# 	@nasm ${SRC_ASM}/boot-sect.asm -f bin -o ${BIN}/bootsect.bin
# 	@nasm ${SRC_ASM}/k-entry.asm -f elf32 -o ${BIN}/entry.bin

# 	# @${CC} ${CFLAGS} ${SRC_C_FILES} -o ${BIN}/kernel.o
# 	@ld -m elf_i386 -z noexecstack -e main -o ${BIN}/kernel.img -r -Ttext 0x1000 ${BIN}/entry.bin ${BIN}/kernel.o

# 	@objcopy -O binary -j .text ${BIN}/kernel.img ${BIN}/kernel.bin
# 	@cat ${BIN}/bootsect.bin ${BIN}/kernel.bin > ${BIN}/os-image

# run:
# 	@qemu-system-i386 -drive format=raw,file=${BIN}/os-image
BIN_DIR=bin
SRC_DIR=src
OBJ_DIR=obj

CC=gcc
CFLAGS=-Isrc/c/include -m32 -ffreestanding

SRCS_C := $(shell find $(SRC_DIR)/c -name '*.c')
OBJS_C := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_C))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS_C)
	@mkdir -p ${OBJ_DIR}/asm
	@nasm ${SRC_DIR}/asm/boot-sect.asm -f bin -o ${BIN_DIR}/bootsect.bin
	@nasm ${SRC_DIR}/asm/k-entry.asm -f elf32 -o ${BIN_DIR}/k-entry.bin

	@ld -m elf_i386 -z noexecstack -e kmain -o ${BIN_DIR}/kernel.img -Ttext 0x1000 ${BIN_DIR}/k-entry.bin ${OBJS_C}
	@objcopy -O binary -j .text ${BIN_DIR}/kernel.img ${BIN_DIR}/kernel.bin

	@cat ${BIN_DIR}/bootsect.bin ${BIN_DIR}/kernel.bin > ${BIN_DIR}/os-image

run:
	@qemu-system-i386 -drive format=raw,file=${BIN_DIR}/os-image
