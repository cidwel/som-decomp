.setcpu "65816"
.segment "CODE"
.org $0B26
map_control_0f0b26:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
