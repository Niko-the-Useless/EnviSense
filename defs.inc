;io
.equ PORTA, 0x1b
.equ DDRA, 0x1a
.equ PINA, 0x19
.equ PORTB, 0x18
.equ DDRB, 0x17
.equ PINB, 0x16
.equ PORTC, 0x15
.equ DDRC, 0x14
.equ PINC, 0x13
.equ PORTD, 0x12
.equ DDRD, 0x11
.equ PIND, 0x10
;eeprom
.equ EEARL, 0x1e
.equ EEARH, 0x1f
.equ EEDR, 0x1d
.equ EECR, 0x1c
;stack
.equ SPH, 0x3e
.equ SPL, 0x3d
;interrupts
.equ INT2, 5
.equ INT0, 6
.equ INT1, 7

;interrupts vectors
.equ RESETaddr, 0x0000
.equ INT0addr, 0x0002
.equ INT1addr, 0x0004
.equ INT2addr, 0x0006
.equ MCUCSR, 0x34
.equ MCUCR, 0x35
.equ GICR, 0x3b

;spi
.equ SPDR, 0x0f
.equ SPRS, 0x0e
.equ SPCR, 0x0d
.equ SPIF, 7

;lcd settings
.equ lcdInit, 0b0011000
.equ lcdOn, 0b00001110
.equ lcdOf, 0b00001000
.equ lcdFunction, 0b00111000
.equ lcdClear, 0b00000001
.equ lcdEntry, 0b00000110
.equ lcdNewLine, 0b11000000
;lcd symbols
.equ S0, 0b00110000
.equ S1, 0b00110001
.equ S2, 0b00110010
.equ S3, 0b00110011
.equ S4, 0b00110100
.equ S5, 0b00110101
.equ S6, 0b00110110
.equ S7, 0b00110111
.equ S8, 0b00111000
.equ S9, 0b00111001
.equ Spercent, 0b00100101 
.equ Scomma, 0b00101100
.equ SA, 0b01000001
.equ SB, 0b01000010
.equ SC, 0b01000011
.equ SD, 0b01000100
.equ SE, 0b01000101
.equ SF, 0b01000110
.equ SG, 0b01000111
.equ SH, 0b01001000
.equ SI, 0b01001001
.equ SJ, 0b01001010
.equ SK, 0b01001011
.equ SL, 0b01001100
.equ SM, 0b01001101
.equ SN, 0b01001110
.equ SO, 0b01001111
.equ SP, 0b01010000
.equ SQ, 0b01010001
.equ SR, 0b01010010
.equ SS, 0b01010011
.equ ST, 0b01010100
.equ SU, 0b01010101
.equ SV, 0b01010110
.equ SW, 0b01010111
.equ SX, 0b01011000
.equ SY, 0b01011001
.equ SZ, 0b01011010
.equ SNULL, 0b00100000

.macro lcdSetting setting
	ldi r16, 0b00000000;RS0 RW0 E0
	out PORTC, r16
	ldi r16, \setting
	out PORTA, r16
	sbi PORTC, 5
	nop
	cbi PORTC, 5
	ldi r18, 40
	rcall delayMs
.endm
.macro lcdWrite symbol
	ldi r21, \symbol
	rcall lcdWriteFunc
.endm
.macro callDelay time
	ldi r18, \time
	rcall delayMs
.endm
