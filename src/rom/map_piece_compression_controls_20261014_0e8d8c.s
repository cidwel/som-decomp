.setcpu "65816"
.segment "CODE"
.org $8D8C
map_control_0e8d8c:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
