.setcpu "65816"
.segment "CODE"
.org $2FB5
map_control_0c2fb5:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
