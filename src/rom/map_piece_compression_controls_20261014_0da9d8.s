.setcpu "65816"
.segment "CODE"
.org $A9D8
map_control_0da9d8:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
