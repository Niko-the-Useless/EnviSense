.include "defs.inc"
.include "lib.inc"
setup:
;stack setup
	ldi r16, 0x08
	out SPH, r16
	ldi r16, 0x5F
	out SPL, r16
;pin_setup
	ldi r16,0b11111111
	out DDRA,r16;DDRA output LCD
	out DDRC,r16;DDRC output LCD
	ldi r16,0b00000000
	out DDRD,r16;DDRD input BUTTONS + 1wire
	ldi r16,0b00001101
	out DDRB,r16;DDRB SS out, mosi out, miso in, sck out
;lcd_setup
	lcdSetting lcdOn
	lcdSetting lcdClear 
	lcdSetting lcdFunction
	lcdSetting lcdEntry
;spi_setup
	sbi PORTB, 4
	ldi r16, 0b01010000
	out SPCR, r16
;i2c_setup
;wire_setup
;interrupt_setup
main:
	lcdWrite SN
	lcdWrite SI
	lcdWrite SK
	lcdWrite SO
loop:
	rjmp loop
