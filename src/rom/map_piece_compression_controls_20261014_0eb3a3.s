.setcpu "65816"
.segment "CODE"
.org $B3A3
map_control_0eb3a3:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
