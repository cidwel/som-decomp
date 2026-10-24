.setcpu "65816"
.segment "CODE"
.org $B32E
map_control_0fb32e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
