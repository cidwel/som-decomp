.setcpu "65816"
.segment "CODE"
.org $B2D2
map_control_0fb2d2:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
