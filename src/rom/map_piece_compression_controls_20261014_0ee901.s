.setcpu "65816"
.segment "CODE"
.org $E901
map_control_0ee901:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
