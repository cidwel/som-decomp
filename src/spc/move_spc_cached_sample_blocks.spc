move_packet:
MOVW YA,$F6
MOVW $2E,YA
MOV $F4,X
wait_length:
CMP X,$F4
BEQ wait_length
MOV X,$F4
MOVW YA,$F6
MOVW $34,YA
MOV $F4,X
MOV Y,#$00
copy_byte:
MOV A,[$2C]+Y
MOV [$2E]+Y,A
INC Y
BNE decrement_length
INC $2D
INC $2F
decrement_length:
DECW $34
BNE copy_byte
wait_next_source:
CMP X,$F4
BEQ wait_next_source
MOV X,$F4
BEQ finished
MOVW YA,$F6
MOVW $2C,YA
MOV $F4,X
wait_next_move:
CMP X,$F4
BEQ wait_next_move
MOV X,$F4
BRA move_packet
finished:
JMP !$11EA
