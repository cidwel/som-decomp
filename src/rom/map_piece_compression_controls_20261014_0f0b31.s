.setcpu "65816"
.segment "CODE"
.org $0B31
map_control_0f0b31:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
