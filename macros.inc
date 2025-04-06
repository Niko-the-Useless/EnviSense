;------------LCD---------
.macro pulseE
	sbi PORTC, 5
	ldi r18, 1;delay time in ms
	rcall delayMs
	cbi PORTC, 5
.endm
.macro lcdWrite, char
	ldi r16, 0b00000001;RS1 RW0 E0
	out PORTC, r16
	ldi r16,\char
	out PORTA, r16
	pulseE
	ldi r18 ,1 
	rcall delayMs
.endm
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
