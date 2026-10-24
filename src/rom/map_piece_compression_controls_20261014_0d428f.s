.setcpu "65816"
.segment "CODE"
.org $428F
map_control_0d428f:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
