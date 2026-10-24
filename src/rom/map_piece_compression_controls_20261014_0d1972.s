.setcpu "65816"
.segment "CODE"
.org $1972
map_control_0d1972:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
