.setcpu "65816"
.segment "CODE"
.org $A95D
map_control_0da95d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
