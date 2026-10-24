.setcpu "65816"
.segment "CODE"
.org $D79F
map_control_0dd79f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
