.setcpu "65816"
.segment "CODE"
.org $0E9B
map_control_0e0e9b:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
