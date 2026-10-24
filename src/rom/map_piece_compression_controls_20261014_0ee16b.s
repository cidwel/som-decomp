.setcpu "65816"
.segment "CODE"
.org $E16B
map_control_0ee16b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
