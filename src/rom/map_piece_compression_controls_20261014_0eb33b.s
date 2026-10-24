.setcpu "65816"
.segment "CODE"
.org $B33B
map_control_0eb33b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
