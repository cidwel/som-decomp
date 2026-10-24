triple_packet:
MOV A,$F5
MOV [$2C]+Y,A
MOV $F4,X
INC Y
MOV A,$F6
MOV [$2C]+Y,A
INC Y
MOV A,$F7
MOV [$2C]+Y,A
CLRC
ADC $2C,#$03
ADC $2D,#$00
MOV Y,#$00
wait_token:
CMP X,$F4
BEQ wait_token
MOV X,$F4
BNE triple_packet
BRA $11EA
