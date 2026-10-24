.setcpu "65816"
.segment "CODE"
.org $F03E
map_control_0ff03e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
