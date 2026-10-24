.setcpu "65816"
.segment "CODE"
.org $FA8D
map_control_0ffa8d:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
