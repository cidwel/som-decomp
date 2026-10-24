.setcpu "65816"
.segment "CODE"
.org $710E
map_control_0d710e:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
