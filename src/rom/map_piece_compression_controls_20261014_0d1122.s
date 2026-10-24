.setcpu "65816"
.segment "CODE"
.org $1122
map_control_0d1122:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
