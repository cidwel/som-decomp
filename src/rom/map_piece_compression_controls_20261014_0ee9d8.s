.setcpu "65816"
.segment "CODE"
.org $E9D8
map_control_0ee9d8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
