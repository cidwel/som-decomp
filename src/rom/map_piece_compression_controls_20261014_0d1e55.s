.setcpu "65816"
.segment "CODE"
.org $1E55
map_control_0d1e55:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
