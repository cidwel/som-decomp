.setcpu "65816"
.segment "CODE"
.org $B32A
map_control_0eb32a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
