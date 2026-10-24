.setcpu "65816"
.segment "CODE"
.org $1B97
map_control_0d1b97:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
