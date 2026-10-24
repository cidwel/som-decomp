.setcpu "65816"
.segment "CODE"
.org $B2FE
map_control_0eb2fe:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
