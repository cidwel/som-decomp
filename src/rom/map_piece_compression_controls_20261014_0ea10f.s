.setcpu "65816"
.segment "CODE"
.org $A10F
map_control_0ea10f:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
