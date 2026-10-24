.setcpu "65816"
.segment "CODE"
.org $0EE9
map_control_0d0ee9:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
