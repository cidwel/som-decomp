.setcpu "65816"
.segment "CODE"
.org $1F2C
map_control_0d1f2c:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
