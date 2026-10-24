.setcpu "65816"
.segment "CODE"
.org $1112
map_control_0d1112:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
