.setcpu "65816"
.segment "CODE"
.org $133C
map_control_0f133c:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
