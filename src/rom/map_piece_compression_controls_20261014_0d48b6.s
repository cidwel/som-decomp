.setcpu "65816"
.segment "CODE"
.org $48B6
map_control_0d48b6:
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count
