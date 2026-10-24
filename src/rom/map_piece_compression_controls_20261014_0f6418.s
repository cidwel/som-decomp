.setcpu "65816"
.segment "CODE"
.org $6418
map_control_0f6418:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
