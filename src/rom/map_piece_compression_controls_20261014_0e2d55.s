.setcpu "65816"
.segment "CODE"
.org $2D55
map_control_0e2d55:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
