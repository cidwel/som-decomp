.setcpu "65816"
.segment "CODE"
.org $D7D1
map_control_0ed7d1:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
