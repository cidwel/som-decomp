.setcpu "65816"
.segment "CODE"
.org $65A6
map_control_0e65a6:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
