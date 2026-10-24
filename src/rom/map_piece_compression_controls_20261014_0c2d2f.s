.setcpu "65816"
.segment "CODE"
.org $2D2F
map_control_0c2d2f:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
