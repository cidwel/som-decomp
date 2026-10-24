.setcpu "65816"
.segment "CODE"
.org $A16F
map_control_0ea16f:
    .byte $E9 ; backreference distance high bits
    .byte $0A ; distance low bit/count
