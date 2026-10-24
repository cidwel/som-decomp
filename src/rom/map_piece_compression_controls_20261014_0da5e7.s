.setcpu "65816"
.segment "CODE"
.org $A5E7
map_control_0da5e7:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
