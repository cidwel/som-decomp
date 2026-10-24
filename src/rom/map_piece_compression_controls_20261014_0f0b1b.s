.setcpu "65816"
.segment "CODE"
.org $0B1B
map_control_0f0b1b:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
