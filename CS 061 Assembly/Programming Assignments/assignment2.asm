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

GETC ;reads input into R0
ST R0, FIRST_OPERAND ;stores first input 
OUT 
LD R0, newline
OUT

GETC 
ST R0, SECOND_OPERAND
OUT
LD R0, newline
OUT
;-------------------------------
;INSERT YOUR CODE here
;--------------------------------

LD R1, FIRST_OPERAND
LD R2, ZEROF
AND R0, R1, R2

LD R1, SECOND_OPERAND
LD R2, ZEROF
AND R3, R1, R2 

NOT R4, R3

ADD R4, R4, #1 ;two's complement
ADD R1, R0, R4

LD R0, FIRST_OPERAND
OUT

LD R0, SPACE
OUT

LD R0, MINUS
OUT

LD R0, SPACE
OUT

LD R0, SECOND_OPERAND
OUT

LD R0, SPACE
OUT

LD R0, EQUAL
OUT

LD R0, SPACE
OUT 

LD R2, ZERO
AND R0, R1, X30
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
ZEROF .FILL x0F
ZERO .FILL x30
FIRST_OPERAND .FILL 0
SECOND_OPERAND .FILL 0
;---------------	
;END of PROGRAM
;---------------	
.END

