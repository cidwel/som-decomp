.setcpu "65816"
.segment "CODE"
.org $B3A7
map_control_0eb3a7:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
