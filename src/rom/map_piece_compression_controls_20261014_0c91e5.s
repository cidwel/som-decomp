.setcpu "65816"
.segment "CODE"
.org $91E5
map_control_0c91e5:
    .byte $E8 ; backreference distance high bits
    .byte $A9 ; distance low bit/count
