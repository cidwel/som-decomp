.setcpu "65816"
.segment "CODE"
.org $E7A8
map_control_0ee7a8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
