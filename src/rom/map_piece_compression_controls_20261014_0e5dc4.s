.setcpu "65816"
.segment "CODE"
.org $5DC4
map_control_0e5dc4:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
