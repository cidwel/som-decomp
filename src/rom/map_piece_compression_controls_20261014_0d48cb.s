.setcpu "65816"
.segment "CODE"
.org $48CB
map_control_0d48cb:
    .byte $E8 ; backreference distance high bits
    .byte $A7 ; distance low bit/count
