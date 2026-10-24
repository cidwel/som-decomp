.setcpu "65816"
.segment "CODE"
.org $E4C1
map_control_0ee4c1:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
