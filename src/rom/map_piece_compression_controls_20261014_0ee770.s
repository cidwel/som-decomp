.setcpu "65816"
.segment "CODE"
.org $E770
map_control_0ee770:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
