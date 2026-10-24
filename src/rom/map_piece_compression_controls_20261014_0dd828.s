.setcpu "65816"
.segment "CODE"
.org $D828
map_control_0dd828:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
