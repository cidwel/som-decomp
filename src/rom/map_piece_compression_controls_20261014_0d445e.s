.setcpu "65816"
.segment "CODE"
.org $445E
map_control_0d445e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
