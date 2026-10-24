.setcpu "65816"
.segment "CODE"
.org $F28F
map_control_0ff28f:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
