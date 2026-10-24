.setcpu "65816"
.segment "CODE"
.org $1711
map_control_0f1711:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
