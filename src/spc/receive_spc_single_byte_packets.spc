byte_packet:
MOV $F4,X
MOV A,$F7
MOV [$2C]+Y,A
INCW $2C
wait_token:
CMP X,$F4
BEQ wait_token
MOV X,$F4
BNE byte_packet
BRA $11EA
