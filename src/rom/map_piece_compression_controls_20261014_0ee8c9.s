.setcpu "65816"
.segment "CODE"
.org $E8C9
map_control_0ee8c9:
    .byte $E8 ; backreference distance high bits
    .byte $63 ; distance low bit/count
