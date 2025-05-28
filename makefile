MCU = atmega32A
TARGET = enviSense
AS = avr-as
LD = avr-ld
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU)

all: $(TARGET).hex

$(TARGET).o: $(TARGET).asm
	$(AS) $(CFLAGS) -o $@ $<

$(TARGET).elf: $(TARGET).o
	$(LD) -o $@ $<

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -f *.o *.elf *.hex

