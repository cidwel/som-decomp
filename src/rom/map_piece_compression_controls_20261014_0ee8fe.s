.setcpu "65816"
.segment "CODE"
.org $E8FE
map_control_0ee8fe:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
