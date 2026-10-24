NOT1 $00B4.1
MOV1 C,$00B4.1
MOV1 $00B1.1,C
BCS fast_timer
MOV A,#$24
BRA selected
fast_timer:
MOV A,#$01
selected:
MOV $F1,#$00
MOV $FA,A
MOV $F1,#$01
RET
