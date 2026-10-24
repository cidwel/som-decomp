.setcpu "65816"
.segment "CODE"
.org $C9B6
map_control_0ec9b6:
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count
