.setcpu "65816"
.segment "CODE"
.org $A6D6
map_control_0da6d6:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
