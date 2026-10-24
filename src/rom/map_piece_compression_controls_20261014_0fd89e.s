.setcpu "65816"
.segment "CODE"
.org $D89E
map_control_0fd89e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
