.setcpu "65816"
.segment "CODE"
.org $A8C5
map_control_0da8c5:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
