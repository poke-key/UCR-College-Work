;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Kunal Shrivastav
; Email: kshri003@ucr.edu
; 
; Assignment name: Assignment 2
; Lab section: 023  
; TA: Sanchit Goel
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------

;----------------------------------------------
;output prompt
;----------------------------------------------	
LEA R0, intro			; get starting address of prompt string
PUTS			    	; Invokes BIOS routine to output string

; read first operand into R0
; store it in FIRST_OPERAND
; echo back to the screen and end with newline
GETC
ST R0, FIRST_OPERAND 
OUT 
LD R0, newline
OUT

; read second operand into R0
; store it in SECOND_OPERAND
; echo back to the screen and end with newline
GETC 
ST R0, SECOND_OPERAND
OUT
LD R0, newline
OUT

; load first operand  into R1
; 0x37 [0011-0111] & x0F[0000-1111] => 0x07 [0000-0111]
; 0x37 - 0x30 = 0x7
; converting ascii code for number to the number
LD R1, FIRST_OPERAND
LD R2, ZEROF            ;mask
AND R0, R1, R2

; load second operand  into R1
; 0x37 [0011-0111] & x0F[0000-1111] => 0x07 [0000-0111]
; 0x37 - 0x30 = 0x7
; converting ascii code for number to the number

LD R1, SECOND_OPERAND
LD R2, ZEROF
AND R3, R1, R2

; first operand -> R0
; second operand -> R3

; find 2s compliment of second operand (R3), have teh answer in R1
NOT R4, R3
ADD R4, R4, #1 ;two's complement


; actual subtraction by addition of number and 2s complement of second number
; first operand is in R0 and 2s compleiemtn in in R4
; result is going in R1
ADD R1, R0, R4
BRN NEGATIVE_ANSWER

;-------------------------------------------------------
; we need to check if answer is negative of positive.
; check carry if yes carry the answer is positive and no 2s comp conversion
; check carry if no carry the answer is negative and we have to do 2s complement
; 2 - 7 = -5
; 7 - 2 = 5
;-------------------------------------------------------

; print first operand
LD R0, FIRST_OPERAND
OUT

; print space
LD R0, SPACE
OUT

; print minus sign
LD R0, MINUS
OUT

; print space
LD R0, SPACE
OUT

; print second operand 
LD R0, SECOND_OPERAND
OUT

; print space
LD R0, SPACE
OUT

; print equal sign
LD R0, EQUAL
OUT

;print space
LD R0, SPACE
OUT 

; print the result
; convert teh result from number to ascii for teh number by oring with x0030
; answer in R1
NOT R1 , R1 ; R1   NOT(R1 )
LD  R2, ZERO
NOT R2 , R2 ; R2   NOT(R2 )
AND R0 , R1 , R2 ; R0   NOT(R1 ) AND NOT(R2 )
NOT R0 , R0 ; R0   R1 OR R2
OUT

LD R0, newline
OUT

HALT				; Stop execution of program

NEGATIVE_ANSWER

;-------------------------------------------------------
; we need to check if answer is negative of positive.
; check carry if yes carry the answer is positive and no 2s comp conversion
; check carry if no carry the answer is negative and we have to do 2s complement
; 2 - 7 = -5
; 7 - 2 = 5
;-------------------------------------------------------

; print first operand
LD R0, FIRST_OPERAND
OUT

; print space
LD R0, SPACE
OUT

; print minus sign
LD R0, MINUS
OUT

; print space
LD R0, SPACE
OUT

; print second operand 
LD R0, SECOND_OPERAND
OUT

; print space
LD R0, SPACE
OUT

; print equal sign
LD R0, EQUAL
OUT

;print space
LD R0, SPACE
OUT 


; print minus sign
LD R0, MINUS
OUT

; answer is in R1 but since it is negative we need to take 2s compelement
NOT R1, R1
ADD R1, R1, #1 ;two's complement

; print the result
; convert teh result from number to ascii for teh number by oring with x0030
; answer in R1
NOT R1 , R1 ; R1   NOT(R1 )
LD  R2, ZERO
NOT R2 , R2 ; R2   NOT(R2 )
AND R0 , R1 , R2 ; R0   NOT(R1 ) AND NOT(R2 )
NOT R0 , R0 ; R0   R1 OR R2
OUT

LD R0, newline
OUT

HALT				; Stop execution of program



;------	
;Data
;------
; String to prompt user. Note: already includes terminating newline!
intro 	.STRINGZ	"ENTER two numbers (i.e '0'....'9')\n" 		; prompt string - use with LEA, followed by PUTS.
newline .FILL x0A	; newline character - use with LD followed by OUT
MINUS .FILL x2D
EQUAL .FILL x3D
SPACE .FILL x20
ZEROF .FILL x000F
ZERO .FILL x0030
ZERO_2SCOMP .FILL   xFFD0
FIRST_OPERAND .FILL 0
SECOND_OPERAND .FILL 0
;---------------	
;END of PROGRAM
;---------------	
.END

