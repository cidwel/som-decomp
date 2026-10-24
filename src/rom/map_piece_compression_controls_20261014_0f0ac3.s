.setcpu "65816"
.segment "CODE"
.org $0AC3
map_control_0f0ac3:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
