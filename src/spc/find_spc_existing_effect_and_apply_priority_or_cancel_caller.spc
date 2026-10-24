; SPC $0FCE; physical ROM $C31518; native effect allocation.
MOV Y,#$08
MOV A,$B5
find_existing:
CMP A,!$FF7F+Y
BEQ found
DBNZ Y,find_existing
BRA finished
found:
MOV A,$B6
AND A,#$0F
BEQ cancel_caller
MOV $34,Y
DEC $34
ASL $34
SET1 $34.4
MOV A,X
BRA check_index
next_index:
LSR $B2
DEC A
DEC A
check_index:
CBNE $34,next_index
MOV X,A
BRA finished
cancel_caller:
POP A
POP A
finished:
RET
