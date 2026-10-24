.setcpu "65816"
.segment "CODE"
.org $2690
map_control_0e2690:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
