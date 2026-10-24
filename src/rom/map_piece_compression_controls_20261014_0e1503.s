.setcpu "65816"
.segment "CODE"
.org $1503
map_control_0e1503:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
