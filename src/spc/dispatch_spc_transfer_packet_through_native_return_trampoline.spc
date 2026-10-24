MOV A,$F5
MOV $04,A
AND A,#$07
MOV $F5,A
BNE transfer_selected
MOV $F4,X
BRA return_from_transfer
transfer_selected:
ASL A
PUSH A
MOVW YA,$F6
MOVW $2C,YA
POP Y
MOV A,!$1419+Y
PUSH A
MOV A,!$1418+Y
PUSH A
MOV Y,#$00
MOV X,$F4
MOV $F4,X
wait_token:
CMP X,$F4
BEQ wait_token
MOV X,$F4
return_from_transfer:
RET
