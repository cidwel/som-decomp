.setcpu "65816"
.segment "CODE"
.org $A3A0
map_control_0ea3a0:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
