.setcpu "65816"
.segment "CODE"
.org $9E93
map_control_0d9e93:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
