.setcpu "65816"
.segment "CODE"
.org $1F00
map_control_0d1f00:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
