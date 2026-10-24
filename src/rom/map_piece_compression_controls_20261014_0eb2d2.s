.setcpu "65816"
.segment "CODE"
.org $B2D2
map_control_0eb2d2:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
