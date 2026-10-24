.setcpu "65816"
.segment "CODE"
.org $0E83
map_control_0e0e83:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
