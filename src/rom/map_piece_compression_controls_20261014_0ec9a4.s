.setcpu "65816"
.segment "CODE"
.org $C9A4
map_control_0ec9a4:
    .byte $E8 ; backreference distance high bits
    .byte $A6 ; distance low bit/count
