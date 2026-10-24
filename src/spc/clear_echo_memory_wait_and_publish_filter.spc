MOV A,#$00
MOV Y,A
clear_echo_page:
MOV [$E1]+Y,A
INC Y
BNE clear_echo_page
INC $E2
CMP $E2,#$FA
BNE clear_echo_page
MOV A,$FE
BRA check_previous_delay
wait_previous_delay:
MOV Y,$FE
BEQ wait_previous_delay
INC A
check_previous_delay:
CMP A,$E0
BCC wait_previous_delay
MOV $F2,#$6C
MOV A,$F3
AND A,#$DF
MOV $F3,A
MOV A,$FE
BRA check_current_delay
wait_current_delay:
MOV Y,$FE
BEQ wait_current_delay
INC A
check_current_delay:
CMP A,$DF
BCC wait_current_delay
MOV A,$A7
MOV Y,#$2C
CALL !$061B
MOV Y,#$3C
CALL !$061B
AND $C7,#$03
MOV A,$C7
ASL A
ASL A
ASL A
MOV Y,A
MOV X,#$0F
filter_registers:
MOV A,!$150C+Y
MOV $F2,X
MOV $F3,A
INC Y
MOV A,X
CLRC
ADC A,#$10
MOV X,A
BPL filter_registers
MOV Y,#$0D
MOV A,$C8
JMP !$061B
