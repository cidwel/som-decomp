.setcpu "65816"
.segment "CODE"
.org $A8D0
map_control_0da8d0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
