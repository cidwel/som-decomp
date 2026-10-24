.setcpu "65816"
.segment "CODE"
.org $A1A4
map_control_0da1a4:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
