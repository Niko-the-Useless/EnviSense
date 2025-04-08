;------------LCD---------
.macro pulseE
	sbi PORTC, 5
	ldi r18, 1;delay time in ms
	rcall delayMs
	cbi PORTC, 5
.endm
.macro lcdWrite, data
	ldi r21, \data
	rcall lcdWriteFunc
.endm
lcdWriteFunc:
	ldi r16, 0b00000001;RS1 RW0 E0
	out PORTC, r16
	out PORTA, r21
	pulseE
	ldi r18 ,1 
	rcall delayMs
	ret
.macro lcdSetting, data
	ldi r16, 0b00000000;RS0 RW0 E0
	out PORTC, r16
	ldi r16, \data
	out PORTA, r16
	pulseE
	ldi r18, 40
	rcall delayMs
.endm
;------------TIMING----------
delayMs:
    ldi r19, 250
delayLoop:
    dec r19
    brne delayLoop
    dec r18
    brne delayMs
    ret         
;------------SPI-------------
spiReceive:
	cbi PORTB, 4
	ldi r16, 0x00
	out SPDR, r16
	rcall spiWait
	in r20, SPDR
	sbi PORTB, 4
	ret
spiWait:
	sbis SPRS, 7
	rjmp spiWait
	ret
spiSend:
	cbi PORTB, 4
	out SPDR, r20
	rcall spiWait
	sbi PORTB, 4
	ret
