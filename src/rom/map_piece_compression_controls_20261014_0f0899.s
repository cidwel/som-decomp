.setcpu "65816"
.segment "CODE"
.org $0899
map_control_0f0899:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
