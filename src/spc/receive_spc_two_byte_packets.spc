pair_packet:
MOV A,$F6
MOV [$2C]+Y,A
MOV $F4,X
INC Y
MOV A,$F7
MOV [$2C]+Y,A
INCW $2C
INCW $2C
DEC Y
wait_token:
CMP X,$F4
BEQ wait_token
MOV X,$F4
BNE pair_packet
BRA $11EA
