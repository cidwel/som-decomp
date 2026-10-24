.setcpu "65816"
.segment "CODE"
.org $1DC4
map_control_0d1dc4:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
