.setcpu "65816"
.segment "CODE"
.org $E8D8
map_control_0ee8d8:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
