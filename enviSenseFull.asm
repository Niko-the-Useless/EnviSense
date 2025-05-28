.include "defs.inc"
.include "edata.inc"
.text
.org RESETaddr 
	rjmp setup
.org INT0addr
	rjmp test
.org INT1addr
	rjmp test2

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
	ldi r16, 0b11111111
	out PORTD, r16; pullup na D poza 1wire
	ldi r16,0b00001101
	out DDRB,r16;DDRB SS out, mosi out, miso in, sck output
;lcd_setup
	ldi r18, 20
	rcall delayMs
	lcdSetting lcdInit
	lcdSetting lcdInit
	lcdSetting lcdInit
	lcdSetting lcdInit
	lcdSetting lcdFunction
	lcdSetting lcdEntry
	lcdSetting lcdOn
	lcdSetting lcdClear 
;menu setup
	ldi r23, 0x00
;spi_setup
	sbi PORTB, 4
	ldi r16, 0b01010000
	out SPCR, r16
;tc77 setup
	ldi r20,0b00000000
	rcall spiSend
;i2c_setup
;wire_setup
;interrupt_setup
	ldi r16, 0b00000000
	out MCUCR, r16
	ldi r16, 0b11000000
	out GICR, r16
	sei 

main:
	rjmp loop
loop:
	rjmp loop
;---------------menu
rollover:
	ldi r23, 0x00
next:
	inc r23
	cpse r23, 3 
	breq rollover
	reti
back:
	dec r23
	cpse r23, 3 
	brsh rollover
	reti
test:
	ldi r16, 0b11111111
	out PORTB, r16
	reti
test2:
	ldi r16, 0b00000000
	out PORTB, r16
	reti
write:
	ldi r26, 0x00
	ldi r27, 0x03
	ldi r18, 50
	rcall delayMs
	lcdSetting lcdClear
	out EEARL, r26
	loopWrite:
	in r16, EEARL
	cp r16, r27
	in r21, EEDR
	rcall lcdWriteFunc
	rcall delayMs
	inc EEARL
	brne loopWrite
	reti
;------------LCD---------
lcdWriteFunc:
	ldi r16, 0b10000000;RS1 RW0 E0
	out PORTC, r16
	out PORTA, r21
	sbi PORTC, 5
	ldi r18, 1
	rcall delayMs
	cbi PORTC, 5
	ldi r18 ,1
	rcall delayMs
	ret
;------------TIMING----------
delayMs:
	loop1: ldi r19, 4
	loop2: ldi r20, 125
	loop3: dec r20
	brne loop3
	dec r19
	brne loop2
	dec r18
	brne loop1
	ret
;------------SPI-------------
spiReceive:
    cbi PORTB, 4           ; Pull SS low (select slave)
    ldi r16, 0x00
    out SPDR, r16
    rcall spiWait
    in r20, SPDR           ; r20 = first 8 bits (bits 12..5)
    out SPDR, r16
    rcall spiWait
    in r22, SPDR           ; r22 = second 8 bits (bits 4..0 + 3x'1')
    sbi PORTB, 4           ; Pull SS high (deselect slave)
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
