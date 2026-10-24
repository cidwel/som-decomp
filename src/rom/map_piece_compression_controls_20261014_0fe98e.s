.setcpu "65816"
.segment "CODE"
.org $E98E
map_control_0fe98e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
