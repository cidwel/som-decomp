.setcpu "65816"
.segment "CODE"
.org $0E9B
map_control_0d0e9b:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
