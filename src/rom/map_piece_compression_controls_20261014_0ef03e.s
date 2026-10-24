.setcpu "65816"
.segment "CODE"
.org $F03E
map_control_0ef03e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
