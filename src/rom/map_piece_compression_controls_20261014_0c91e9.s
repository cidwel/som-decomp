.setcpu "65816"
.segment "CODE"
.org $91E9
map_control_0c91e9:
    .byte $E8 ; backreference distance high bits
    .byte $A9 ; distance low bit/count
