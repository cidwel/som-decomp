.setcpu "65816"
.segment "CODE"
.org $E49C
map_control_0ee49c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
