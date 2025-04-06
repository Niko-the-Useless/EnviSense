;------------LCD---------
.macro pulseE
	sbi PORTC, 5
	delayMs, 1
	cbi PORTC, 5
.endm
.macro lcdWrite, \char
	ldi r16, 0b00000001;RS1 RW0 E0
	out PORTC, r16
	ldi r16,\char
	out PORTA, r16
	pulseE
	delayMs,1
.endm
.macro lcdSetting, \data, \delay
	ldi r16, 0b00000000;RS0 RW0 E0
	out PORTC, r16
	ldi r16, \data
	out PORTA, r16
	pulseE
	delayMs, \delay
.endm
;------------TIMING----------
.macro delayMs, ms;for 16Mhz
    ldi r18, \ms 
loop_ms:
    ldi r19, 250
inner_loop:
    dec r19
    brne inner_loop
    dec r18
    brne loop_ms
.endm

