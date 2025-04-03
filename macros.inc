;------------LCD---------
.macro lcdFunction
	ldi r16, 0b00110000
	out PORTA, r16
.endm
.macro lcdClear
	ldi r16, 00000001
	out PORTA, r16
.endm
.macro lcdEntry
	ldi r16, 00000110
	out PORTA, r16
.endm
.macro lcdOn
	ldi r16, 00001110
	out PORTA, r16
.endm
.macro lcdOf
	ldi r16, 00001000
	out PORTA, r16
.endm
