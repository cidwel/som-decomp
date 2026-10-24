.setcpu "65816"
.segment "CODE"
.org $A7AC
map_control_0da7ac:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
