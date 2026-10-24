.setcpu "65816"
.segment "CODE"
.org $A0AA
map_control_0da0aa:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
