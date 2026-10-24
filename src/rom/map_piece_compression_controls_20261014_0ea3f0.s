.setcpu "65816"
.segment "CODE"
.org $A3F0
map_control_0ea3f0:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
