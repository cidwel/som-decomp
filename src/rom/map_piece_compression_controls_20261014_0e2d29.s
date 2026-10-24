.setcpu "65816"
.segment "CODE"
.org $2D29
map_control_0e2d29:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
