; SPC $0F91; physical ROM $C314DB; native effect helper.
MOV A,$B7
XCN A
AND A,#$F0
BNE initial_nonzero
MOV A,#$80
initial_nonzero:
MOV $B5,A
AND $B7,#$F0
BNE target_nonzero
SET1 $B7.7
target_nonzero:
AND $B6,#$F0
MOV A,$B7
SETC
SBC A,$B5
PUSH PSW
BCS magnitude_ready
EOR A,#$FF
INC A
magnitude_ready:
MOV X,$B6
BNE divide
POP A
BRA finished
divide:
MOV Y,#$00
DIV YA,X
MOV $B5,A
MOV A,#$00
DIV YA,X
MOV $B4,A
POP PSW
BCC finished
EOR $B4,#$FF
EOR $B5,#$FF
INCW $B4
finished:
RET
