.setcpu "65816"
.segment "CODE"
.org $E0FE
map_control_0ee0fe:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
