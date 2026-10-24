.setcpu "65816"
.segment "CODE"
.org $D951
map_control_0dd951:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
