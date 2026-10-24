.setcpu "65816"
.segment "CODE"
.org $A76F
map_control_0da76f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
