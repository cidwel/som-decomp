.setcpu "65816"
.segment "CODE"
.org $E8E4
map_control_0ee8e4:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
