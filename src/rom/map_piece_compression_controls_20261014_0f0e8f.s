.setcpu "65816"
.segment "CODE"
.org $0E8F
map_control_0f0e8f:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
