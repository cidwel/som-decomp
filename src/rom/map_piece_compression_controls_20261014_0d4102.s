.setcpu "65816"
.segment "CODE"
.org $4102
map_control_0d4102:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
