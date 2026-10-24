.setcpu "65816"
.segment "CODE"
.org $B594
map_control_0db594:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
