# Compiler and Linker settings
AVR_AS = avr-as
AVR_LD = avr-ld
MCU = atmega32
CFLAGS = -mmcu=$(MCU) -g   # Include debugging information (-g)

# File names
ASM_SRC = enviSense.asm
OBJ_FILE = enviSense.o
ELF_FILE = enviSense.elf

# Default target (compiles and links)
all: $(ELF_FILE)

# Compile .asm file to .o object file
$(OBJ_FILE): $(ASM_SRC)
	$(AVR_AS) $(CFLAGS) -o $(OBJ_FILE) $(ASM_SRC)

# Link .o object file to .elf executable
$(ELF_FILE): $(OBJ_FILE)
	$(AVR_LD) -o $(ELF_FILE) $(OBJ_FILE)

# Clean up generated files
clean:
	rm -f $(OBJ_FILE) $(ELF_FILE)

# Phony targets to avoid confusion with file names
.PHONY: all clean

