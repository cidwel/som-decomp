.setcpu "65816"
.segment "CODE"
.org $A9C9
map_control_0da9c9:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
