; SPC $112C; physical ROM $C31676; native high command.
BBS $B4.1,stop_effect_voices
MOV A,$AE
EOR A,#$FF
TSET1 !$00B0
TCLR1 !$00AF
TCLR1 !$00B8
TCLR1 !$00BA
TCLR1 !$00B9
MOV A,#$00
MOV $AD,A
MOV $CB,A
MOV $BC,A
MOV $C0,A
MOV $BE,A
CLR1 $B1.5
BBS $B4.0,finished
stop_effect_voices:
MOV A,$AE
TSET1 !$00B0
TCLR1 !$00AF
TCLR1 !$00B8
TCLR1 !$00BA
TCLR1 !$00B9
CLR1 $B1.4
MOV A,#$00
MOV $AE,A
MOV $BD,A
MOV $C1,A
MOV $BF,A
MOV Y,#$08
MOV A,#$FF
clear_flags:
MOV !$FF7F+Y,A
DBNZ Y,clear_flags
finished:
RET
