.setcpu "65816"
.segment "CODE"
.org $0A97
map_control_0f0a97:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
