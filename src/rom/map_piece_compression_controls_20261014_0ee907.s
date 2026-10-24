.setcpu "65816"
.segment "CODE"
.org $E907
map_control_0ee907:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
