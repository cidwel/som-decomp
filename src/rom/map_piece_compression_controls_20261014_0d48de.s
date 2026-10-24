.setcpu "65816"
.segment "CODE"
.org $48DE
map_control_0d48de:
    .byte $E8 ; backreference distance high bits
    .byte $A7 ; distance low bit/count
