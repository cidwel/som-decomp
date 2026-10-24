; SPC $0EF6; physical ROM $C31440; native effect allocation.
MOV A,X
AND A,#$0F
ASL A
MOV Y,A
MOV A,!$153C+Y
BNE sequence_present
RET
sequence_present:
MOV $31,A
MOV A,!$153B+Y
MOV $30,A
MOV $B5,#$FE
MOV $B6,#$0F
MOV $B7,#$80
