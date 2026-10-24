.setcpu "65816"
.segment "CODE"
.org $2D2C
map_control_0c2d2c:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
