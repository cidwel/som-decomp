.setcpu "65816"
.segment "CODE"
.org $A1D1
map_control_0da1d1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
