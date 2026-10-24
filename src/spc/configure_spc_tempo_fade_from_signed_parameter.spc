; SPC $1066; physical ROM $C315B0; native high command.
MOV A,$B5
AND A,#$07
BEQ invert_target
BBC $B5.3,scale_target
DEC A
scale_target:
MOV Y,#$12
MUL YA
BBS $B5.3,target_selected
invert_target:
EOR A,#$80
target_selected:
MOV $B6,A
AND $B5,#$F0
MOV Y,$B6
MOV A,$B5
set_counter:
MOV $97,A
BNE compute_velocity
MOV $90,Y
MOV $8F,A
MOV $94,A
MOV $93,A
BRA finished
compute_velocity:
MOV A,Y
SETC
SBC A,$90
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
MOVW $93,YA
MOV $8F,#$00
finished:
RET
