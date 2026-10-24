.setcpu "65816"
.segment "CODE"
.org $0E69
map_control_0e0e69:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
