.setcpu "65816"
.segment "CODE"
.org $3BE8
map_control_0d3be8:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
