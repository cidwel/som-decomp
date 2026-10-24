.setcpu "65816"
.segment "CODE"
.org $7DD7
map_control_0c7dd7:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
