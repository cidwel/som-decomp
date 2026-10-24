.setcpu "65816"
.segment "CODE"
.org $81E7
map_control_0f81e7:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $92 ; distance low bit/count
