.setcpu "65816"
.segment "CODE"
.org $53F4
map_control_0f53f4:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
