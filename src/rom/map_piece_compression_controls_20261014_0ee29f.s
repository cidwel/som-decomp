.setcpu "65816"
.segment "CODE"
.org $E29F
map_control_0ee29f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
