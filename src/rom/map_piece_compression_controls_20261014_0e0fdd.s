.setcpu "65816"
.segment "CODE"
.org $0FDD
map_control_0e0fdd:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
