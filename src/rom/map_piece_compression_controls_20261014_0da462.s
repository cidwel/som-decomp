.setcpu "65816"
.segment "CODE"
.org $A462
map_control_0da462:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
