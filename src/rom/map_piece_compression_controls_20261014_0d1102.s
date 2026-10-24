.setcpu "65816"
.segment "CODE"
.org $1102
map_control_0d1102:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
