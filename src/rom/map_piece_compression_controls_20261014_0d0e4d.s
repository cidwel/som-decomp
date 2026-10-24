.setcpu "65816"
.segment "CODE"
.org $0E4D
map_control_0d0e4d:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
