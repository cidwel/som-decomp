.setcpu "65816"
.segment "CODE"
.org $F33F
map_control_0ef33f:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
