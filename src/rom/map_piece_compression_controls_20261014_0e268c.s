.setcpu "65816"
.segment "CODE"
.org $268C
map_control_0e268c:
    .byte $E8 ; backreference distance high bits
    .byte $60 ; distance low bit/count
