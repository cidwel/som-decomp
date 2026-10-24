.setcpu "65816"
.segment "CODE"
.org $48A0
map_control_0d48a0:
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count
