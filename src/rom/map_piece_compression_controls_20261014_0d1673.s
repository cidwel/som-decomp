.setcpu "65816"
.segment "CODE"
.org $1673
map_control_0d1673:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
