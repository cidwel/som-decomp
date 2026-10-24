.setcpu "65816"
.segment "CODE"
.org $A6C2
map_control_0da6c2:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
