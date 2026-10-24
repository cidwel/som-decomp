.setcpu "65816"
.segment "CODE"
.org $53F0
map_control_0f53f0:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
