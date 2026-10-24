MOV A,#$FF
MOV Y,#$FE
CMPW YA,$B4
BNE clear_marker
MOV A,#$FD
MOV Y,#$FC
CMPW YA,$B6
BNE clear_marker
SET1 $B1.7
BRA finished
clear_marker:
CLR1 $B1.7
finished:
RET
