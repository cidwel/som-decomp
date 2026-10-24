.setcpu "65816"
.segment "CODE"
.org $A9A3
map_control_0da9a3:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
