.setcpu "65816"
.segment "CODE"
.org $E69C
map_control_0fe69c:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
