.setcpu "65816"
.segment "CODE"
.org $E1F4
map_control_0ee1f4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
