.setcpu "65816"
.segment "CODE"
.org $0A2C
map_control_0f0a2c:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
