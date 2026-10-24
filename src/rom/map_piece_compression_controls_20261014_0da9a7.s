.setcpu "65816"
.segment "CODE"
.org $A9A7
map_control_0da9a7:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
