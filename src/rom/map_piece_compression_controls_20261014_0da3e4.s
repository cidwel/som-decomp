.setcpu "65816"
.segment "CODE"
.org $A3E4
map_control_0da3e4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
