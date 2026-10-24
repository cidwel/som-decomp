.setcpu "65816"
.segment "CODE"
.org $A93D
map_control_0ea93d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
