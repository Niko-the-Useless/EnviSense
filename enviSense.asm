setup:
	ldi r16,0b11111111
	out 0x1a,r16;DDRA output
	out 0x14,r16;DDRC output
	ldi r16,0b00000000
	out 0x11,r16;DDRD input
;lcd
clear:
entry:
onOff:
function:
readFlags:

.macro delay_ms ms
    ldi r18, \ms    ; Load delay count (in ms)
loop_ms:
    ldi r19, 250    ; Set up inner loop for 250 iterations (approximating 1 ms)
inner_loop:
    dec r19         ; Decrement the counter
    brne inner_loop ; Loop until r19 reaches 0
    dec r18         ; Decrement the outer loop counter (ms)
    brne loop_ms    ; Repeat for all ms
.endm
