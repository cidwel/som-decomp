.setcpu "65816"
.segment "CODE"
.org $A7A4
map_control_0ea7a4:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
