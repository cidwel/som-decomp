.setcpu "65816"
.segment "CODE"
.org $A14E
map_control_0da14e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
