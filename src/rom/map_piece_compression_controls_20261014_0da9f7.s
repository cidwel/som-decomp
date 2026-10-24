.setcpu "65816"
.segment "CODE"
.org $A9F7
map_control_0da9f7:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
