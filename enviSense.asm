.include "defs.inc"
.include "macros.inc"
setup:
	ldi r16,0b11111111
	out DDRA,r16;DDRA output
	out DDRC,r16;DDRC output
	ldi r16,0b00000000
	out DDRD,r16;DDRD input
