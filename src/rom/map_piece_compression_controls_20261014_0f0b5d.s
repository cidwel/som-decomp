.setcpu "65816"
.segment "CODE"
.org $0B5D
map_control_0f0b5d:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
