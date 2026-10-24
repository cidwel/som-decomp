.setcpu "65816"
.segment "CODE"
.org $A7A5
map_control_0fa7a5:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
