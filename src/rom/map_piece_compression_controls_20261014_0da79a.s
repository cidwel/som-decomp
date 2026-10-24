.setcpu "65816"
.segment "CODE"
.org $A79A
map_control_0da79a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
