.setcpu "65816"
.segment "CODE"
.org $E473
map_control_0ee473:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
