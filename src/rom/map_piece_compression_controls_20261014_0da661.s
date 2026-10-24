.setcpu "65816"
.segment "CODE"
.org $A661
map_control_0da661:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
