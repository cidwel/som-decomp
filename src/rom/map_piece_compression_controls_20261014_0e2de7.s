.setcpu "65816"
.segment "CODE"
.org $2DE7
map_control_0e2de7:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
