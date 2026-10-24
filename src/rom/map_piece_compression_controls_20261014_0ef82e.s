.setcpu "65816"
.segment "CODE"
.org $F82E
map_control_0ef82e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
