.setcpu "65816"
.segment "CODE"
.org $F84C
map_control_0cf84c:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
