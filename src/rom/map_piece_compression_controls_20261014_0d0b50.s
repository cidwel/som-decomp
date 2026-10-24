.setcpu "65816"
.segment "CODE"
.org $0B50
map_control_0d0b50:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
