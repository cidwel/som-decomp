.setcpu "65816"
.segment "CODE"
.org $31A6
map_control_0f31a6:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
