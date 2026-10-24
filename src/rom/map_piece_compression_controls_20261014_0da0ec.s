.setcpu "65816"
.segment "CODE"
.org $A0EC
map_control_0da0ec:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
