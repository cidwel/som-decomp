.setcpu "65816"
.segment "CODE"
.org $E7C1
map_control_0ee7c1:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
