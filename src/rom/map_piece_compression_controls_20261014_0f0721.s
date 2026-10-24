.setcpu "65816"
.segment "CODE"
.org $0721
map_control_0f0721:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
