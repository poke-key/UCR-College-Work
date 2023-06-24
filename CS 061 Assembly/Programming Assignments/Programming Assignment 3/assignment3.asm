;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Kunal Shrivastav    
; Email: kshri003@ucr.edu
; 
; Assignment name: Assignment 3
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
    LD R6, Value_ptr		; R6 <-- pointer to value to be displayed as binary
    LDR R1, R6, #0			; R1 <-- value to be displayed as binary 
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------
    ;ADD R2, R1, #0 ;adds 0 to R1 and moves to R2
    AND R3, R3, #0 ; clear register
    ADD R3, R3, #8 ;R3 is our loop counter
    ADD R3, R3, #8
    LD R4, Mask ;loading mask into R4 register
    AND R5, R5, #0
LOOP_1
    
    AND R2, R1, R4 ;AND the mask with the number
    BRz Print_Zero
    LD R0, One
    OUT
    BR Print_done
Print_Zero 
    LD R0, Zero
    OUT
    
Print_done
    ADD R1, R1, R1 ;double value of R2
    ADD R3, R3, #-1
    BRz alldone

    ;logic to print space after every four prints
    ADD R5, R5, #1
    AND R6, R5, x4 
    BRz LOOP_1
    LD R0, Space
    OUT
    AND R5, R5, #0
    BR  LOOP_1

alldone
    LD R0, newline
    OUT
    HALT
;---------------	
;Data
;---------------
Value_ptr	.FILL xCA01	; The address where value to be displayed is stored
Mask .FILL x8000 ;mask to check the MSB
Zero .FILL x30
One  .FILL x31
Space .FILL x20
newline .FILL x0A
.END

.ORIG xCA01					; Remote data
Value .FILL xABCD			; <----!!!NUMBER TO BE DISPLAYED AS BINARY!!! Note: label is redundant. Binary Value: 1010-1011-1100-1101
;---------------	
;END of PROGRAM
;---------------	
.END