.setcpu "65816"
.segment "CODE"
.org $B2D6
map_control_0eb2d6:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
