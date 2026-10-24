.setcpu "65816"
.segment "CODE"
.org $87A5
map_control_0d87a5:
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
