; SPC $100F; physical ROM $C31559; native high command.
SET1 $B1.5
MOV A,$B5
AND $B5,#$F0
AND A,#$0F
MOV Y,#$11
MUL YA
MOV $B6,A
MOV $F5,$B5
MOV Y,$B6
MOV A,$B5
set_counter:
MOV $8B,A
BNE compute_velocity
MOV $84,Y
MOV $83,A
MOV $88,A
MOV $87,A
OR $C9,$AD
BRA finished
compute_velocity:
MOV A,Y
SETC
SBC A,$84
BEQ set_counter
PUSH PSW
BCS positive
EOR A,#$FF
INC A
positive:
MOV X,$B5
MOV Y,#$00
DIV YA,X
MOV $35,A
MOV A,#$00
DIV YA,X
MOV $34,A
MOVW YA,$34
BNE nonzero
INC $34
nonzero:
POP PSW
BCS store_velocity
EOR $34,#$FF
EOR $35,#$FF
INCW $34
store_velocity:
MOVW YA,$34
MOVW $87,YA
MOV $83,#$00
finished:
RET
