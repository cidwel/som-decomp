.setcpu "65816"
.segment "CODE"
.org $A9C2
map_control_0da9c2:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
