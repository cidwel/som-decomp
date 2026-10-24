.setcpu "65816"
.segment "CODE"
.org $FA19
map_control_0dfa19:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
