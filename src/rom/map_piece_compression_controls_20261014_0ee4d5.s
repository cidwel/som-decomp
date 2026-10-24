.setcpu "65816"
.segment "CODE"
.org $E4D5
map_control_0ee4d5:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
