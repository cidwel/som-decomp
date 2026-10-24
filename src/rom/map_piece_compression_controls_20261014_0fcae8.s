.setcpu "65816"
.segment "CODE"
.org $CAE8
map_control_0fcae8:
    .byte $E8 ; backreference distance high bits
    .byte $6B ; distance low bit/count
