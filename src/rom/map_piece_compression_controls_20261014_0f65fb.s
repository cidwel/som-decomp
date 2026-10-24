.setcpu "65816"
.segment "CODE"
.org $65FB
map_control_0f65fb:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
