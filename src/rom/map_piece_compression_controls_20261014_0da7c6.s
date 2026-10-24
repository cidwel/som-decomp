.setcpu "65816"
.segment "CODE"
.org $A7C6
map_control_0da7c6:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
