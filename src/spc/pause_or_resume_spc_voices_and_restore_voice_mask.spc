; SPC $118E; physical ROM $C316D8; native high command.
BBS $B4.0,resume
MOV Y,#$05
pause_adsr:
MOV $F2,Y
MOV A,$F3
AND A,#$7F
MOV $F3,A
MOV A,Y
CLRC
ADC A,#$10
MOV Y,A
BPL pause_adsr
MOV X,#$00
MOV Y,#$00
clear_volumes:
MOV $F2,Y
MOV $F3,X
INC Y
MOV $F2,Y
MOV $F3,X
MOV A,Y
CLRC
ADC A,#$0F
MOV Y,A
BPL clear_volumes
MOVW YA,$AD
BEQ voices_saved
MOVW $CB,YA
MOVW YA,$00
MOVW $AD,YA
voices_saved:
MOV $AF,A
MOV Y,#$10
clear_scales:
MOV !$00CC+Y,A
DBNZ Y,clear_scales
BRA finished
resume:
MOV Y,#$05
resume_adsr:
MOV $F2,Y
MOV A,$F3
OR A,#$80
MOV $F3,A
MOV A,Y
CLRC
ADC A,#$10
MOV Y,A
BPL resume_adsr
MOVW YA,$CB
BEQ finished
MOV $C9,#$FF
MOVW $AD,YA
MOVW YA,$00
MOVW $CB,YA
finished:
RET
