.setcpu "65816"
.segment "CODE"
.org $0E7F
map_control_0f0e7f:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
