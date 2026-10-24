.setcpu "65816"
.segment "CODE"
.org $0B10
map_control_0f0b10:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
