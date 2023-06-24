; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Kunal Shrivastav
; Email: kshri003@ucr.edu   
; 
; Assignment name: Assignment 5
; Lab section: 023
; TA: Sanchit Goel
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
; PUT ALL YOUR CODE AFTER THE main LABEL
;=================================================================================

;---------------------------------------------------------------------------------
;  Initialize program by setting stack pointer and calling main subroutine
;---------------------------------------------------------------------------------
.ORIG x3000

; initialize the stack
ld r6, stack_addr


; call main subroutine
lea r5, main
jsrr r5



;---------------------------------------------------------------------------------
; Main Subroutine
;---------------------------------------------------------------------------------
main
    ; get a string from the user
    ; * put your code here
    LEA R0, user_prompt
    PUTS
    
    LEA R1, user_string
    LD R5, get_user_string_addr
    JSRR R5
    
    ; find size of input string
    ; * put your code here
    LEA R1, user_string
    LD R5, strlen_addr
    JSRR R5
    
    ; call palindrome method
    ; * put your code here
    LEA R1, user_string
    ADD R2, R1, R0
    ADD R2, R2, #-1
    LD R5, palindrome_addr
    JSRR R5
    AND R1, R1, #0
    ADD R1, R0, #0
    
    ; determine of string is a palindrome
    ; * put your code here
    ; R0 = 0 not a palindrome, 1= is a palindrome
    
    ; print the result to the screen
    ; * put your code here
    LEA  R0, result_string
    PUTS
    ; decide whether or not to print "not"
    ; * put your code here
    ADD R1, R1, #-1
    BRz IS_PALINDROME
    LEA R0, not_string
    PUTS
IS_PALINDROME
    LEA  R0, final_string
    PUTS

HALT

;---------------------------------------------------------------------------------
; Required labels/addresses
;---------------------------------------------------------------------------------

; Stack address ** DO NOT CHANGE **
stack_addr           .FILL    xFE00

; Addresses of subroutines, other than main
get_user_string_addr .FILL    x3200
strlen_addr          .FILL    x3300
palindrome_addr      .FILL	  x3400


; Reserve memory for strings in the progrtam
user_prompt          .STRINGZ "Enter a string: "
result_string        .STRINGZ "The string is "
not_string           .STRINGZ "not "
final_string         .STRINGZ	"a palindrome\n"

; Reserve memory for user input string
user_string          .BLKW	  100

.END

;---------------------------------------------------------------------------------
; get_user_string - This function gets the string inputted and terminates when null character is entered.
;---------------------------------------------------------------------------------
.ORIG x3200
get_user_string
; Backup all used registers, R7 first, using proper stack discipline
    ;back up the important and modified registers
    ADD R6, R6, #-1
    STR R7, R6, #0 
    ADD R6, R6, #-1
    STR R0, R6, #0 
    ADD R6, R6, #-1
    STR R1, R6, #0
    ADD R6, R6, #-1
    STR R2, R6, #0 
    ADD R6, R6, #-1
    STR R3, R6, #0 
    ADD R6, R6, #-1
    STR R4, R6, #0 
    
    LD R2, I_SENTINEL
   ; LEA R0, PROMPT
    ;PUTS

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; read characters until sentinel character and store in memory location
    AND R5, R5, #0 ;clear R5 to return number of characters read
    AND R3, R3, x0
LOOP_1 
    GETC ;reads into R0
    OUT

    
    ; we subtract R2(I_SENTINEL) from the character read to determine if they are same
    ;compare with the sentinal character in R2
    NOT R4, R2
    ADD R4, R4, #1
    ADD R4, R0, R4      ; subtraction

    BRz LOOP_OUT        ; if zero means sentinel chaacater was read so exit the loop
                        ; esle increment the location counter and continue the loop
    ;store the chacarter read at the buffer location
    STR R0, R1, #0
    ADD R5, R5, #1
    ADD R1, R1, #1      ;increment R1 to next location
    BR LOOP_1           ; continue the loop
LOOP_OUT
    AND R0, R0, #0 ; set R0 to NULL
    STR R0, R1, #0 ;terminate the buffer with NULL
    ;restore backed up registers
    LDR R4, R6, #0
    ADD R6, R6, #1
    LDR R3, R6, #0
    ADD R6, R6, #1
    LDR R2, R6, #0
    ADD R6, R6, #1
    LDR R1, R6, #0
    ADD R6, R6, #1
    LDR R0, R6, #0
    ADD R6, R6, #1
    LDR R7, R6, #0
    ADD R6, R6, #1
    
    RET 
;PROMPT      .STRINGZ "Please enter a string followed by ENTER :\n"
newline     .FILL xA
I_SENTINEL  .FILL xA
; Resture all used registers, R7 last, using proper stack discipline
.END

;---------------------------------------------------------------------------------
; strlen - Returns the length of the null-terminated string. 
; input - R1
;       address of string
; output - R1
;        length of string
;---------------------------------------------------------------------------------
.ORIG x3300
strlen
; Backup all used registers, R7 first, using proper stack discipline
    ADD R6, R6, #-1
    STR R7, R6, #0
    ADD R6, R6, #-1
    STR R5, R6, #0 
    ADD R6, R6, #-1
    STR R5, R6, #0 
AND R2, R2, #0 ;clear R2 to be counter for size of input string
COUNT_LOOP
    LDR R5, R1, #0
    BRz COUNT_DONE
    ADD R2, R2, #1 ;increment counter
    ADD R1, R1, #1 ;increment address in the buffer
    BR COUNT_LOOP
COUNT_DONE
AND R0, R0, #0
ADD R0, R2, #0
; Restore all used registers, R7 last, using proper stack discipline
    LDR R2, R6, #0
    ADD R6, R6, #1
    LDR R5, R6, #0
    ADD R6, R6, #1
    LDR R7, R6, #0
    ADD R6, R6, #1
RET
.END

;---------------------------------------------------------------------------------
; palindrome - is a recursive subroutine to check if given string is a palindrome
; input - R1 is beginning of string, R2 is the end of string
; output - R0, 1 if palindrome, 0 if not palindrome
;---------------------------------------------------------------------------------
.ORIG x3400
palindrome ; Hint, do not change this label and use for recursive alls
; Backup all used registers, R7 first, using proper stack discipline
    ADD R6, R6, #-1
    STR R7, R6, #0
    ADD R6, R6, #-1
    STR R5, R6, #0
    ADD R6, R6, #-1
    STR R4, R6, #0
    ADD R6, R6, #-1
    STR R3, R6, #0
;---------------------------------------------------------------------------------    
    AND R3, R3, #0
    AND R4, R4, #0
    ADD R3, R1, #0 ; move R1 to R3
    ADD R4, R2, #0 ; move R2 to R4
    NOT R4, R4
    ADD R4, R4, #1
    ADD R4, R3, R4
    BRn CONTINUE_1
    AND R0, R0, #0
    ADD R0, R0, #1  ;return true
    BR RESTORE_STACK
CONTINUE_1
    LDR R3, R1, #0
    LDR R4, R2, #0
    NOT R3, R3
    ADD R3, R3, #1
    ADD R4, R3, R4
    BRz CONTINUE_2
    AND R0, R0, #0 ;return false 
    BR RESTORE_STACK
CONTINUE_2
    ADD R1, R1, #1
    ADD R2, R2, #-1
    LEA R5, palindrome
    JSRR R5
; Restore all used registers, R7 last, using proper stack discipline
RESTORE_STACK
    LDR R3, R6, #0
    ADD R6, R6, #1
    LDR R4, R6, #0
    ADD R6, R6, #1
    LDR R5, R6, #0
    ADD R6, R6, #1
    LDR R7, R6, #0
    ADD R6, R6, #1
;---------------------------------------------------------------------------------
    RET

.END