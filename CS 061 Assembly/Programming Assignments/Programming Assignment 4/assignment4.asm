;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Kunal Shrivastav
; Email: kshri003@ucr.edu
; 
; Assignment name: Assignment 4
; Lab section: 23
; TA: Sanchit Goel
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL NUMBER MUST BE STORED IN R4
;=================================================================================

.ORIG x3000		
;-------------
;Instructions
;-------------

; output intro prompt
START_OVER
    AND R5, R5, #0
    ADD R5, R5, #5  ; counter for 4 additional digits

    AND R4, R4, #0          ; clear target register everytime
    LD R0, introPromptPtr
    PUTS
    ; Set up flags, counters, accumulators as needed\
    ;R2 is the counter
    ;R$ will be used to store the number
    ;AND R1, R1, #0
    ;ADD R1, R1, #3
    ;ST R1, NEG_FLAG
    AND R2, R2, #0      ; initialize R2 = 0
    
    ; Get first character, test for '\n', '+', '-', digit/non-digit 
GET_DIGIT
    GETC
    OUT
    
    ; is very first character = '\n'? if so, just quit (no message)!
    ; TODO
    
    ; is it = '+'? if so, ignore it, go get digits
    ;ASCII value of "+" is x2B
    LD R3, PLUS
    NOT R3, R3
    ADD R3, R3, #1
    ADD R3, R0, R3
    BRz CONT_2
    
    ; is it = '-'? if so, set neg flag, go get digits
    LD R3, MINUS
    NOT R3, R3
    ADD R3, R3, #1
    ADD R3, R0, R3
    BRz SET_NEG_FLAG
    
    ; we already have teh first digit
    BR  CONT_3
    
SET_NEG_FLAG
    ADD R3, R3, #1 ;R3 is already zero so just add 1
    ST R3, NEG_FLAG 
    BR  CONT_2

CONT_2
    GETC
    OUT

CONT_3
    ; compare with newline
    LD R3, newline
    NOT R3, R3
    ADD R3, R3, #1
    ADD R3, R0, R3
    BRz DONE

    ; is it < '0'? if so, it is not a digit	- o/p error message, start over
    LD R3, THIRTY
    NOT R3, R3
    ADD R3, R3, #1
    ADD R3, R0, R3
    BRn START_OVER

    ; is it > '9'? if so, it is not a digit	- o/p error message, start over
    LD R3, THIRTY_NINE
    NOT R3, R3
    ADD R3, R3, #1
    ADD R3, R0, R3
	BRp START_OVER

    ; if R4 (counter is 5 thehn no mult by 10)
    ADD R3, R5, #-5
    BRn M0
    
    LD  R3, NUMBERMASK
    AND R0, R0, R3
    ADD R4, R4, R0
    BR  M1

M0    
    AND R6, R6, #0
    AND R3, R3, #0
    ADD R3, R3, #10
MULT
    ADD R6, R6, R4
    ADD R3, R3, #-1
    BRp MULT
    AND R4, R4, #0      ; clear R5
    ADD R4, R4, R6
    
    LD  R3, NUMBERMASK
    AND R0, R0, R3
    ADD R4, R4, R0
    
M1
    ; counter for 4(R4) numbers
    ADD R5, R5, #-1
    BRz DONE
	BR  CONT_2

    ; Now get remaining digits from user in a loop (max 5), testing each to see if it is a digit, and build up number in accumulator
    ; remember to end with a newline!
DONE
    LD  R3, NEG_FLAG
    BRz DONE1
    NOT R4, R4
    ADD R4, R4, #1  ; 2s complement
    
DONE1    
    HALT

;---------------	
; Program Data
;---------------
introPromptPtr  .FILL xB000
errorMessagePtr .FILL xB200
NEG_FLAG        .FILL x0
MINUS           .FILL x2D
PLUS            .FILL x2B
newline         .FILL xA
NUMBERMASK      .FILL XF
THIRTY          .FILL x30
THIRTY_NINE     .FILL x39
SUB_GET_PLUS    .FILL   x3200
SUB_GET_MINUS   .FILL   x3400
SUB_GET_DIGIT   .FILL   x3600

.END

;------------
; Remote data
;------------
.ORIG xB000	 ; intro prompt
.STRINGZ	 "Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"

.END					
					
.ORIG xB200	 ; error message
.STRINGZ	 "ERROR: invalid input\n"
;---------------
; END of PROGRAM
;---------------
.END

;-------------------
; PURPOSE of PROGRAM
;-------------------
; Convert a sequence of up to 5 user-entered ascii numeric digits into a 16-bit two's complement binary representation of the number.
; if the input sequence is less than 5 digits, it will be user-terminated with a newline (ENTER).
; Otherwise, the program will emit its own newline after 5 input digits.
; The program must end with a *single* newline, entered either by the user (< 5 digits), or by the program (5 digits)
; Input validation is performed on the individual characters as they are input, but not on the magnitude of the number.
