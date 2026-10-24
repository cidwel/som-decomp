.setcpu "65816"
.segment "CODE"
.org $B593
map_control_0fb593:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
