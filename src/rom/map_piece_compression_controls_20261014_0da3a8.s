.setcpu "65816"
.segment "CODE"
.org $A3A8
map_control_0da3a8:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
