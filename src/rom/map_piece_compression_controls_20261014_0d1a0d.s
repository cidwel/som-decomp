.setcpu "65816"
.segment "CODE"
.org $1A0D
map_control_0d1a0d:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
