.setcpu "65816"
.segment "CODE"
.org $0AD9
map_control_0f0ad9:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
