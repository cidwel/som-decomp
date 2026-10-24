.setcpu "65816"
.segment "CODE"
.org $C9C9
map_control_0ec9c9:
    .byte $E8 ; backreference distance high bits
    .byte $A2 ; distance low bit/count
