.setcpu "65816"
.segment "CODE"
.org $969E
map_control_0e969e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
