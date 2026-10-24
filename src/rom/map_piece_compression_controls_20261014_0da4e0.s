.setcpu "65816"
.segment "CODE"
.org $A4E0
map_control_0da4e0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
