.setcpu "65816"
.segment "CODE"
.org $53E8
map_control_0f53e8:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
