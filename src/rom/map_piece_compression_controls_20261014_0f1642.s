.setcpu "65816"
.segment "CODE"
.org $1642
map_control_0f1642:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
