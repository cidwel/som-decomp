.setcpu "65816"
.segment "CODE"
.org $A912
map_control_0ea912:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
