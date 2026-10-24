.setcpu "65816"
.segment "CODE"
.org $F922
map_control_0ef922:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
