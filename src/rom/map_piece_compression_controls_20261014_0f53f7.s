.setcpu "65816"
.segment "CODE"
.org $53F7
map_control_0f53f7:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
