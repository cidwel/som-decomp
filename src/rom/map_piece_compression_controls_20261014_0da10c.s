.setcpu "65816"
.segment "CODE"
.org $A10C
map_control_0da10c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
