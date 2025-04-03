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

;interrupts
.equ INT2, 5
.equ INT0, 6
.equ INT1, 7

;interrupts vectors
.equ INT0addr, 0x0002
.equ INT1addr, 0x0004
.equ INT2addr, 0x0006

;lcd symbols
.equ S0, 00110000
.equ S1, 00110001
.equ S2, 00110010
.equ S3, 00110011
.equ S4, 00110100
.equ S5, 00110101
.equ S6, 00110110
.equ S7, 00110111
.equ S8, 00111000
.equ S9, 00111001
.equ Spercent, 00100101 
.equ Scomma, 00101100
.equ SA, 0100 0001
.equ SB, 0100 0010
.equ SC, 0100 0011
.equ SD, 0100 0100
.equ SE, 0100 0101
.equ SF, 0100 0110
.equ SG, 0100 0111
.equ SH, 0100 1000
.equ SI, 0100 1001
.equ SJ, 0100 1010
.equ SK, 0100 1011
.equ SL, 0100 1100
.equ SM, 0100 1101
.equ SN, 0100 1110
.equ SO, 0100 1111
.equ SP, 0101 0000
.equ SQ, 0101 0001
.equ SR, 0101 0010
.equ SS, 0101 0011
.equ ST, 0101 0100
.equ SU, 0101 0101
.equ SV, 0101 0110
.equ SW, 0101 0111
.equ SX, 0101 1000
.equ SY, 0101 1001
.equ SZ, 0101 1010
