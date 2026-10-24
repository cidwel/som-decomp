.setcpu "65816"
.segment "CODE"
.org $FA9D
map_control_0dfa9d:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
