.setcpu "65816"
.segment "CODE"
.org $A79F
map_control_0ea79f:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
