;--------------- 
; Assembly Code 
;--------------- 
#define __SFR_OFFSET 0x00 
#include “avr/io.h” 
;------------------------ 
 
.global start 
.global led 
;------------------------
start: 
SBI   DDRB, 5;          set PB5 (D13) as o/p 
RET;                           return to setup() function 
;--------------------------------------------------------------------------- 
led: 
CPI         R24, 0x00;           value in R24 passed by caller compared with 0 
BREQ    ledOFF;                jump (branch) if equal to subroutine ledOFF 
SBI        PORTB, 5;            set D13 to HIGH, i.e., the LED will turn ON 
RCALL myDelay;             Calling a delay function to determine the ON duration of LED 
RET;                                   return to loop() function 
;--------------------------------------------------------------------------- 
ledOFF: 
CBI        PORTB, 5;          set D13 to LOW, i.e., the LED will turn OFF 
RCALL myDelay;             Calling a delay function to determine the OFF duration of LED 
RET;                                  return to loop() function 
;--------------------------------------------------------------------------- 
.equ  delayVal, 10000;           initial count value for the inner loop (0010011100010000) 
;--------------------------------------------------------------------------- 
myDelay: 
LDI   R20, 100;                   initial count value for the outer loop 
outerLoop: 
LDI   R30, lo8(delayVal);   low byte of delayVal in R30 (00010000) 
LDI   R31, hi8(delayVal);     high byte of delayVal in R31 (00100111) 
innerLoop: 
SBIW  R30, 1;                        subtract 1 from 16-bit value in R31, R30 
BRNE  innerLoop;                 jump if countVal not equal to 0 
;-------------- 
SUBI  R20, 1;                 subtract 1 from R20 
BRNE  outerLoop;                jump if R20 is not equal to 0 
RET 
;--------------------------------------------------------------------------- 
