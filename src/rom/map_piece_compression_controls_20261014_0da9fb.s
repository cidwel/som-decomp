.setcpu "65816"
.segment "CODE"
.org $A9FB
map_control_0da9fb:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
