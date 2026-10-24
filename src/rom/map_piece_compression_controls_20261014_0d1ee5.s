.setcpu "65816"
.segment "CODE"
.org $1EE5
map_control_0d1ee5:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
