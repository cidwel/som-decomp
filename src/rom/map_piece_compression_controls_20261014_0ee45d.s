.setcpu "65816"
.segment "CODE"
.org $E45D
map_control_0ee45d:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
