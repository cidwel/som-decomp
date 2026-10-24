.setcpu "65816"
.segment "CODE"
.org $A41B
map_control_0da41b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
