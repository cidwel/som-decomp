.setcpu "65816"
.segment "CODE"
.org $E9D5
map_control_0ee9d5:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
