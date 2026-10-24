.setcpu "65816"
.segment "CODE"
.org $CB2D
map_control_0dcb2d:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
