.setcpu "65816"
.segment "CODE"
.org $A803
map_control_0ea803:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
