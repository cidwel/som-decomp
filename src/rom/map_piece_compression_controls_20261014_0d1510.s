.setcpu "65816"
.segment "CODE"
.org $1510
map_control_0d1510:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
