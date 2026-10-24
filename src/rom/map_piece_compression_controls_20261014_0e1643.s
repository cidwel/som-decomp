.setcpu "65816"
.segment "CODE"
.org $1643
map_control_0e1643:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
