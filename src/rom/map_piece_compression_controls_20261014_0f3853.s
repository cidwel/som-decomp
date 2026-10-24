.setcpu "65816"
.segment "CODE"
.org $3853
map_control_0f3853:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
