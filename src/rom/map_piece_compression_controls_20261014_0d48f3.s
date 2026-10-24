.setcpu "65816"
.segment "CODE"
.org $48F3
map_control_0d48f3:
    .byte $E8 ; backreference distance high bits
    .byte $A8 ; distance low bit/count
