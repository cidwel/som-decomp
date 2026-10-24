.setcpu "65816"
.segment "CODE"
.org $787E
map_control_0d787e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
