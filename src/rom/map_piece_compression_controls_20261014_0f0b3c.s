.setcpu "65816"
.segment "CODE"
.org $0B3C
map_control_0f0b3c:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
